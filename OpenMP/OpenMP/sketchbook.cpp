#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <omp.h>
#include <iostream>
#include <math.h>

#include <map>

#define ACCURACY  200000000

// Based on tutorials from:
// http://www.cmmsigma.eu/labs/parallel_comp/openmp_tutorial/index.pl.html

void omp_test(void)
{
	const int size = 2048;
	double mytable[size];
	std::map<int, int> t;

	#pragma omp parallel for   
	for (int n = 0; n < size; ++n) {
		double angle = 2 * 3.1415 * n / size;
		mytable[n] = std::sin(angle) - std::pow(std::cos(angle), 2.0);
		t[omp_get_thread_num()]++;
	}
	std::cout << "Number of elements processed per thread:" << std::endl;
	for (auto &x : t)
		std::cout << x.first << ": " << x.second << std::endl;
	std::cout << "Done" << std::endl;
}

int step_1(void)
{
	#define  NUM_LOOPS 100

	double **A;
	double *u, *v;
	long rows = 5000, columns = 5000;
	double begin_t, end_t;
	long i, j, k;

	// Inicjujemy wektory i macierz.
	u = (double*)malloc(columns * sizeof(double));
	v = (double*)malloc(rows * sizeof(double));

	A = (double**)malloc(rows * sizeof(double*));

	for (i = 0; i < rows; i++)
		A[i] = (double*)malloc(columns * sizeof(double));

	// Wype³niamy wektor u oraz macierz A dowolnymi wartoœciami.
	for (i = 0; i < columns; i++) {
		u[i] = (double)(i / 1000.0f);

		for (j = 0; j < rows; j++)
			A[j][i] = (double)(i * j / 1000.0f);
	}

	begin_t = omp_get_wtime();

	// Pêtla zewnêtrzna.
	for (k = 0; k < NUM_LOOPS; k++) {
		// Obliczamy v = A*u z wykorzystaniem dyrektyw OpenMP.
		#pragma omp parallel for shared(A, v, u, rows, columns) private(i, j)
		for (i = 0; i < rows; i++) {
			v[i] = 0.0f;
			for (j = 0; j < columns; j++)
				v[i] = v[i] + A[i][j] * u[j];
		}
	}

	end_t = omp_get_wtime();

	printf("Czas obliczen z openmp (petla wewnetrzna): %f.\n", end_t - begin_t);

	begin_t = omp_get_wtime();

	// Pêtla zewnêtrzna.
	#pragma omp parallel for shared(A, v, u, rows, columns) private(k, i, j)
	for (k = 0; k < NUM_LOOPS; k++) {
		// Obliczamy v = A*u z wykorzystaniem dyrektyw OpenMP.
		for (i = 0; i < rows; i++) {
			v[i] = 0.0f;
			for (j = 0; j < columns; j++)
				v[i] = v[i] + A[i][j] * u[j];
		}
	}

	end_t = omp_get_wtime();

	printf("Czas obliczen z openmp (petla zewnetrzna): %f.\n", end_t - begin_t);

	begin_t = omp_get_wtime();

	// Pêtla zewnêtrzna.
	for (k = 0; k < NUM_LOOPS; k++) {
		// Obliczamy v = A*u z wykorzystaniem dyrektyw OpenMP.
		for (i = 0; i < rows; i++) {
			v[i] = 0.0f;
			for (j = 0; j < columns; j++)
				v[i] = v[i] + A[i][j] * u[j];
		}
	}

	end_t = omp_get_wtime();

	printf("Czas obliczen bez openmp: %f.\n", end_t - begin_t);

	// Zwalniamy pamiêæ.
	free(u);
	free(v);

	for (i = 0; i < rows; i++)
		free(A[i]);

	free(A);

	return 0;

}

// Metoda Wallis'a obliczania wartosci liczby Pi bez OpenMP.
void
count_pi1(double *pi)
{
	double tmp = 1.0, a_n;
	long int i, N;

	N = ACCURACY;

	for (i = 1; i <= N; i++) {
		a_n = (double)(4.0*i*i / (4.0*i*i - 1.0));
		tmp = tmp * a_n;
	}

	*pi = (double)(2.0 * tmp);
}

// Metoda Wallis'a obliczania wartosci liczby Pi z wykorzystaniem OpenMP.
void count_pi1_omp(double *pi)
{
	double tmp = 1.0, a_n;
	long int i, N;

	N = ACCURACY;

#pragma omp parallel for default(none) shared(N) private(a_n, i) \
        reduction(* : tmp)
	for (i = 1; i <= N; i++) {
		a_n = (double)(4.0*i*i / (4.0*i*i - 1.0));
		tmp = tmp * a_n;
	}

	*pi = (double)(2.0 * tmp);
}

void count_pi1_omp_error_shared(double *pi)
{
	double tmp = 1.0, a_n;
	long int i, N;

	N = ACCURACY;

#pragma omp parallel for default(none) shared(N, tmp) private(a_n, i)
	for (i = 1; i <= ACCURACY; i++) {
		a_n = (double)(4.0*i*i / (4.0*i*i - 1.0));
		tmp = tmp * a_n;
	}

	*pi = (double)(2.0 * tmp);
}

void count_pi1_omp_error_private(double *pi)
{
	double tmp = 1.0, a_n;
	long int i, N;

	N = ACCURACY;

#pragma omp parallel for default(none) shared(N) private(a_n, i, tmp)
	for (i = 1; i <= ACCURACY; i++) {
		a_n = (double)(4.0*i*i / (4.0*i*i - 1.0));
		tmp = tmp * a_n;
	}

	*pi = (double)(2.0 * tmp);
}

void old_main(void)
{
	double value = 16.0;
	double power = 0.5;

	double result = pow(value, power);
	std::cout << result << std::endl;


	double p1, p2, pErrorPrivate, pErrorShared;
	double begin_t, end_t;

	printf("Bez OpenMP:\n");

	begin_t = omp_get_wtime();
	count_pi1(&p1);
	//count_pi2(&p2);
	end_t = omp_get_wtime();

	printf("Metoda Wallis'a Pi = %f.\n", p1);
	//printf("Metoda Leibniz'a Pi = %f.\n" , p2);
	printf("Czas wykonywania obliczen: %f.\n\n", end_t - begin_t);
	printf("Z OpenMP:");

	begin_t = omp_get_wtime();
	count_pi1_omp(&p1);
	//count_pi2_omp(&p2);
	end_t = omp_get_wtime();

	printf("Metoda Wallis'a Pi = %f.\n", p1);
	//printf("Metoda Leibniz'a Pi = %f.\n" , p2);
	printf("Czas wykonywania obliczen: %f.\n\n", end_t - begin_t);

	count_pi1_omp_error_shared(&pErrorShared);
	std::cout << pErrorShared << std::endl;

	count_pi1_omp_error_private(&pErrorPrivate);
	std::cout << pErrorPrivate << std::endl;


	const int size = 10000;
	int tab[size];
	for (int i = 0; i<size; i++)
	{
		tab[i] = i;
	}

	int sum = 0;
	int i;

	begin_t = omp_get_wtime();
	for (int j = 0; j < 10000; ++j)
	{
		sum = 0;
		for (i = 0; i < size; ++i)
		{
			sum = sum + tab[i];
		}
	}
	end_t = omp_get_wtime();
	printf("Srednia: %f, czas: %f\n", (float)sum / size, (end_t - begin_t));

	begin_t = omp_get_wtime();
	for (int j = 0; j < 10000; ++j)
	{
		sum = 0;
#pragma omp parallel default(none) shared(tab, size) private(i) reduction(+ : sum)
		for (i = 0; i < size; ++i)
		{
			sum = sum + tab[i];
		}
	}
	end_t = omp_get_wtime();
	printf("Srednia: %f, czas: %f\n", (float)sum / size, (end_t - begin_t));


}

// Program glowny.
int
main(int argc, char *argv[])
{
	omp_test();

	step_1();

	return 0;
}


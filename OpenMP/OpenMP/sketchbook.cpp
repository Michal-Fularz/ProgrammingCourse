#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
#include <omp.h>
#include <iostream>
#include <math.h>

#define ACCURACY  200000000

// Based on tutorials from:
// http://www.cmmsigma.eu/labs/parallel_comp/openmp_tutorial/index.pl.html

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

// Program glowny.
int
main(int argc, char *argv[])
{
	double value = 16.0;
	double power = 0.5;

	double result = pow(value, power);
	std::cout <<result << std::endl;


	double p1, p2, pErrorPrivate, pErrorShared;
	double begin_t, end_t;
	
	printf("Bez OpenMP:\n");

	begin_t = omp_get_wtime();
	count_pi1(&p1);
	//count_pi2(&p2);
	end_t = omp_get_wtime();

	printf("Metoda Wallis'a Pi = %f.\n" , p1);
	//printf("Metoda Leibniz'a Pi = %f.\n" , p2);
	printf("Czas wykonywania obliczen: %f.\n\n", end_t - begin_t);
	printf("Z OpenMP:");

	begin_t = omp_get_wtime();
	count_pi1_omp(&p1);
	//count_pi2_omp(&p2);
	end_t = omp_get_wtime();

	printf("Metoda Wallis'a Pi = %f.\n" , p1);
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
	printf("Srednia: %f, czas: %f\n", (float)sum / size, (end_t-begin_t));

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


	system("pause");

	return 0;
}


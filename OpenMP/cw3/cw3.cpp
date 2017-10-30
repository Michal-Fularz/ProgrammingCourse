#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

#define ACCURACY 200000000

// Metoda Wallis'a obliczania wartosci liczby Pi.
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

// Metoda Leibniza obliczania wartosci liczby Pi.
void
count_pi2(double *pi)
{
	double tmp = 0.0, a_n;
	long int i, N;

	N = ACCURACY;

	for (i = 0; i < N; i++) {
		if (i % 2 == 0) {
			a_n = (double)(1.0 / (2.0*i + 1.0));
		}
		else {
			a_n = (double)(-1.0 / (2.0*i + 1.0));
		}

		tmp = tmp + a_n;
	}

	*pi = (double)(4.0 * tmp);
}

// Program glowny.
int
main(int argc, char *argv[])
{
	//double tmp1, tmp2;
	double p1, p2, p3, p4;
	double begin_t, end_t;

	printf("Z OpenMP podzial na podstawie id:\n");

	int nr_threads, id;

	begin_t = omp_get_wtime();

#pragma omp parallel shared(nr_threads) private(id, p1, p2, p3, p4)
	{
#pragma omp single
		{
			nr_threads = omp_get_num_threads();
			printf("Dostepnych jest %d watkow.\n", nr_threads);
		}

		id = omp_get_thread_num();

		if (id == 0)
		{
			count_pi1(&p1);
			printf("Metoda Wallis'a Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p1, omp_get_thread_num());
		}

		if (id == 1)
		{
			count_pi2(&p2);
			printf("Metoda Leibniz'a Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p2, omp_get_thread_num());
		}

		if (id == 2)
		{
			count_pi1(&p3);
			printf("Metoda Wallis'a2 Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p3, omp_get_thread_num());
		}

		if (id == 3)
		{
			count_pi2(&p4);
			printf("Metoda Leibniz'a2 Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p4, omp_get_thread_num());
		}
	}
	end_t = omp_get_wtime();

	printf("Czas wykonywania obliczen: %f.\n\n", end_t - begin_t);

	printf("Z OpenMP sections:\n");

	begin_t = omp_get_wtime();
#pragma omp parallel sections private(p1, p2, p3, p4)
	{
#pragma omp section
		{
			count_pi1(&p1);
			printf("Metoda Wallis'a Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p1, omp_get_thread_num());
		}

#pragma omp section
		{
			count_pi2(&p2);
			printf("Metoda Leibniz'a Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p2, omp_get_thread_num());
		}
#pragma omp section
		{
			count_pi1(&p3);
			printf("Metoda Wallis'a2 Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p3, omp_get_thread_num());
		}

#pragma omp section
		{
			count_pi2(&p4);
			printf("Metoda Leibniz'a2 Pi = %f - obliczenia wykonane przez "
				"watek nr. %d.\n", p4, omp_get_thread_num());
		}
	}
	end_t = omp_get_wtime();

	printf("Czas wykonywania obliczen: %f.\n\n", end_t - begin_t);

	system("pause");

	return 0;
}

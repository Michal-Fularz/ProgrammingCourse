#include <stdio.h>
#include <omp.h>
#include <iostream>
#include <math.h>

#include <map>

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

// Program glowny.
int
main(int argc, char *argv[])
{
	omp_test();

	{
		double begin_t, end_t;

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

	return 0;
}


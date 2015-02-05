#include "StudentsProblems.h"

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <omp.h>
#include <algorithm>

#include <Windows.h>

#define ENABLE_OMP

#define MIN(a,b) (((a)<(b))?(a):(b))

void Merge(int *array, int start, int middle, int end) {
	// b³¹d - sizeof element tablicy
	//int *merged = (int *)malloc((end - start) * sizeof start);
	// sizeof(*array) ???
	int *merged = (int *)malloc((end - start) * sizeof(int));
	int l = 0, r = 0, i = 0;

	while (l < (middle - start) && r < (end - middle))
		i++[merged] =
		((start + l)[array] < (middle + r)[array])
		? (start + l++)[array]
		: (middle + r++)[array];

	while (r < (end - middle))
		i++[merged] = (middle + r++)[array];

	while (l < (middle - start))
		i++[merged] = (start + l++)[array];

	memcpy(array + start, merged, (end - start) * sizeof start);
	free(merged);
}

void recursiveMergeSort(int *array, int length) {

	if (length <= 1) return;

	int middle = length / 2;

	recursiveMergeSort(array, middle);
	recursiveMergeSort(array + middle, length - middle);

	Merge(array, 0, middle, length);
}

void recursiveMergeSortMP(int *array, int length, int num_threads) {

	if (length <= 1)
		return;

	int middle = length / 2;

	if (num_threads == 1)
		recursiveMergeSort(array, length);

	else if (num_threads > 1) {
		//omp_set_num_threads(2);
		//#pragma omp parallel sections //shared(array)
		//#pragma omp parallel sections num_threads(2)
//#pragma omp parallel shared(array, middle, num_threads) num_threads(2)
		{

			#pragma omp sections 
			{
				#pragma omp section
				{
					recursiveMergeSortMP(array, middle, num_threads / 2);
				}

				#pragma omp section
				{
					recursiveMergeSortMP(array + middle, length - middle, num_threads - (num_threads / 2));
				}
			}
		}
		Merge(array, 0, middle, length);
	}
}


void iterativeMergeSort(int *array, int length) {

	for (int i = 1; i <= length / 2 + 1; i *= 2)
		for (int j = i; j < length; j += 2 * i)
			Merge(array, j - i, j, MIN(j + i, length));
}

void iterativeMergeSortMP(int *array, int length) {

	for (int i = 1; i <= length / 2 + 1; i *= 2)
		for (int j = i; j < length; j += 2 * i)
			Merge(array, j - i, j, MIN(j + i, length));
}

void printIntTab(int * tab, int length) {
	for (int i = 0; i < length; ++i)
		printf("%d ", i[tab]);
	printf("\n");
}

void problem_2014_2015_merge_sort_recursion(void) {

	printf("nested: %d\n", omp_get_nested());
	omp_set_nested(1);
	printf("nested: %d\n", omp_get_nested());

	printf("num_threads: %d\n", omp_get_num_threads());
	omp_set_num_threads(4);
	printf("num_threads: %d\n", omp_get_num_threads());

	const int LENGTH = 10000;
	const int    MAX = 1000;
	const int  ITERS = 1000;

	int num_threads;

	#pragma omp parallel
	{
		#pragma omp master
		{
			num_threads = omp_get_num_threads();
			printf("num_threads: %d\n", num_threads);
		}
	}

	LARGE_INTEGER freq, start, end;
	double total = 0;

	QueryPerformanceFrequency(&freq);

	int tab[LENGTH];

	for (int i = 0; i < LENGTH; ++i)
		i[tab] = rand() % (MAX + 1);

	printf("Normal approach:\n");

	for (int i = 0; i < ITERS; ++i) {
		int tmp_tab[LENGTH];
		memcpy(tmp_tab, tab, LENGTH * sizeof i);

		QueryPerformanceCounter(&start);
		recursiveMergeSort(tmp_tab, LENGTH);
		QueryPerformanceCounter(&end);

		total += (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
		if (i == ITERS - 1){
			//printIntTab(tab, LENGTH);
			//printIntTab(tmp_tab, LENGTH);
			printf("TOTAL TIME: %f [s]\n", total);
		}
	}

	total = 0;

	printf("\nOPENMP parallelized:\n");
	for (int i = 0; i < ITERS; ++i) {
		int tmp_tab[LENGTH];
		memcpy(tmp_tab, tab, LENGTH * sizeof i);

		QueryPerformanceCounter(&start);
		recursiveMergeSortMP(tmp_tab, LENGTH, num_threads);
		QueryPerformanceCounter(&end);

		total += (double)(end.QuadPart - start.QuadPart) / freq.QuadPart;
		if (i == ITERS - 1){
			//printIntTab(tab, LENGTH);
			//printIntTab(tmp_tab, LENGTH);
			printf("TOTAL TIME: %f [s]\n", total);
		}
	}
}


#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int
main(int argc, char *argv[])
{
	int i, n, id, chunk_size;

	n = 9;
	chunk_size = 1;

#pragma omp parallel default(none) private(i, id) shared(n, chunk_size)
	{
#pragma omp single
		{
			printf("Program jest wykonywany na %d watkach.\n",
				omp_get_num_threads());
		}

#pragma omp for schedule(static, chunk_size)
		for (i = 0; i < n; i++) {
			id = omp_get_thread_num();
			printf("Iteracja %d wykonana przez watek nr. %d.\n", i, id);
		}
	}

	system("pause");

	return 0;
}
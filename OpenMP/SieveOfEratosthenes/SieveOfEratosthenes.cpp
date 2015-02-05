#include <omp.h>
#include <iostream>
#include <vector>

// calculates the sum of prime numbers that are less then upperBound (using Sieve of Eratosthenes) numberOfIterations times
void SumOfPrimesNumbers(int numberOfThreadsToUse, unsigned __int64 upperBound, int numberOfIterations)
{
	omp_set_num_threads(numberOfThreadsToUse);

	// initialization of all necessary variables
	unsigned __int64 primNumbersSum = 0;
	bool* isPrime;
	isPrime = new bool[upperBound + 1];
	//std::vector<bool> isPrime(upperBound + 1);

	int lastNumberToCalculate = (ceil(sqrt(upperBound)) + 1);
	

	double begin_t, end_t;
	begin_t = omp_get_wtime();

	for (int k = 0; k < numberOfIterations; ++k)
	{
		primNumbersSum = 0;
		long long i, j = 0;

		isPrime[0] = false;
		isPrime[1] = false;
		#pragma omp parallel for default(none) shared(upperBound, isPrime) private(i)
		for (i = 2; i <= upperBound; ++i)
		{
			isPrime[i] = true;
		}

		for (i = 2; i <= lastNumberToCalculate; ++i)
		{
			if (isPrime[i])
			{
				long long startValue = i*i;
				long long stopValue = (long long)upperBound;
				long long chunkSize = 10;
				// this does not work properly, because one thread can change the value in table that other thread is using!!!
				// hmm chyba jednka nie, przecie¿ sprawdzanie jest powy¿ej dla jednego w¹tka
				//#pragma omp parallel for default(none) shared(startValue, stopValue, chunkSize, isPrime, i) private(j) schedule(static, chunkSize)
				for (j = startValue; j <= stopValue; j += i)
				{
					isPrime[j] = false;
				}
			}
		}

		#pragma omp parallel for default(none) shared(upperBound, isPrime) private(i) reduction(+ : primNumbersSum) 
		for (i = 2; i <= upperBound; ++i)
		{
			if (isPrime[i])
			{
				primNumbersSum += i;
			}
		}
	}

	end_t = omp_get_wtime();

	std::cout << "Number of threads used: " << numberOfThreadsToUse << std::endl;
	std::cout << "Time of calculations: " << end_t - begin_t << std::endl;
	std::cout << "Sum of prime numbers that are less than " << upperBound << " is: " << primNumbersSum << std::endl;
	std::cout << std::endl;

	//delete[] isPrime;
}

int main(void)
{
	const unsigned __int64 upperBound = 20000000;
	const int numberOfIterations = 100;

	for (int i = 0; i < 1; ++i)
	{
		SumOfPrimesNumbers(1, upperBound, numberOfIterations);
		SumOfPrimesNumbers(2, upperBound, numberOfIterations);
		SumOfPrimesNumbers(4, upperBound, numberOfIterations);
	}

	std::cout << "Press enter to continue..." << std::endl;
	std::cin.sync();		// Flush The Input Buffer Just In Case
	std::cin.ignore();		// There's No Need To Actually Store The Users Input

	return 1;
}
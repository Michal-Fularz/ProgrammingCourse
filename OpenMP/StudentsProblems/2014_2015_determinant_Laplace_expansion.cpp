#include "StudentsProblems.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>
#include <windows.h>
#include <omp.h>

using namespace std;

int determinantOMP(int **matrix, int size);
int determinant(int **matrix, int size);
void ijMinor(int **matrix, int **minorMatrix, int size, int row, int column);

void problem_2014_2015_determinant_Laplace_expansion(void)
{
	const int size = 10;

	int **matrix;

	int matrixPattern[size][size] =
	{
		{ 1, 9, 8, 12, 2, 3, 4, 8, 5, 7 },
		{ 5, 8, 6, 9, 5, 7, 4, 5, 8, 9 },
		{ 4, 7, 4, 5, 6, 9, 8, 7, 4, 2 },
		{ 5, 6, 9, 5, 7, 4, 8, 5, 6, 9 },
		{ 7, 4, 2, 5, 4, 7, 1, 5, 4, 7 },
		{ 4, 8, 2, 4, 8, 9, 6, 3, 1, 5 },
		{ 5, 2, 4, 7, 8, 5, 2, 4, 8, 7 },
		{ 5, 6, 9, 7, 2, 1, 4, 7, 8, 5 },
		{ 5, 8, 7, 9, 6, 4, 5, 2, 1, 4 },
		{ 8, 6, 8, 7, 4, 1, 2, 5, 7, 5 }
	};

	matrix = new int*[size];
	for (int i = 0; i < size; i++)
		matrix[i] = new int[size];

	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			matrix[i][j] = matrixPattern[i][j];
		}
	}

	double start, stop;
	int det;

	start = omp_get_wtime();
	det = determinantOMP(matrix, size);
	stop = omp_get_wtime();
	cout << "\nWyznacznik OMP:\t" << det << ". Czas wykonania:\t" << (stop - start) << endl;

	start = omp_get_wtime();
	det = determinant(matrix, size);
	stop = omp_get_wtime();
	cout << "\nWyznacznik:\t" << det << ". Czas wykonania:\t" << (stop - start) << endl;

	for (int i = 0; i < size; ++i)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

int determinantOMP(int **matrix, int size){
	if (size == 1)return matrix[0][0];
	else{
		int j;
		int result = 0, sign = -1;
		#pragma omp parallel for default(none) shared(size, matrix) private(j, sign)  reduction(+ : result)
		for (j = 0; j < size; j++){

			int **minorMatrix;
			minorMatrix = new int*[size - 1];

			for (int i = 0; i < size - 1; i++){
				minorMatrix[i] = new int[size - 1];
			}

			ijMinor(matrix, minorMatrix, size, 0, j);

			sign = (j % 2) ? -1 : 1;
			result += sign*matrix[0][j] * determinant(minorMatrix, size - 1);

			for (int i = 0; i < size - 1; i++){
				delete[] minorMatrix[i];
			}
			delete[] minorMatrix;
		}

		return result;
	}
}

int determinant(int **matrix, int size){
	if (size == 1)return matrix[0][0];
	else{
		int result = 0, sign = -1;
		for (int j = 0; j < size; j++){

			int **minorMatrix;
			minorMatrix = new int*[size - 1];

			for (int k = 0; k < size - 1; k++){
				minorMatrix[k] = new int[size - 1];
			}

			ijMinor(matrix, minorMatrix, size, 0, j);

			//sign *= -1;
			sign = (j % 2) ? -1 : 1;
			result += sign*matrix[0][j] * determinant(minorMatrix, size - 1);
			for (int i = 0; i < size - 1; i++){
				delete[] minorMatrix[i];
			}
			delete[] minorMatrix;
		}

		return result;
	}
}

void ijMinor(int **matrix, int **minorMatrix, int size, int row, int column){
	int i, j;
	for (i = 0; i < size; i++){
		for (j = 0; j < size; j++){
			if (i < row){
				if (j < column) minorMatrix[i][j] = matrix[i][j];
				else if (j == column) continue;
				else minorMatrix[i][j - 1] = matrix[i][j];
			}
			else if (i == row) continue;
			else{
				if (j < column) minorMatrix[i - 1][j] = matrix[i][j];
				else if (j == column) continue;
				else minorMatrix[i - 1][j - 1] = matrix[i][j];
			}
		}
	}
}

//1 9 8 12 2 3 4 8 5 7 5 8 6 9 5 7 4 5 8 9 4 7 4 5 6 9 8 7 4 2 5 6 9 5 7 4 8 5 6 9 7 4 2 5 4 7 1 5 4 7 4 8 2 4 8 9 6 3 1 5 5 2 4 7 8 5 2 4 8 7 5 6 9 7 2 1 4 7 8 5 5 8 7 9 6 4 5 2 1 4 8 6 8 7 4 1 2 5 7 5
//-4007207

//1 2 3 3 2 1 2 1 3
//-12
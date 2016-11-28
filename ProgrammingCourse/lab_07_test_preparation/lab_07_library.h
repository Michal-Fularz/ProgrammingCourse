#ifndef __LAB_07_LIBRARY_H_INCLUDED__
#define __LAB_07_LIBRARY_H_INCLUDED__

int modulo_1(int value, int dividend);
int modulo_2(int value, int dividend);
float calculate_average(int* values, int number_of_values);
float calculate_standard_deviation(int* values, int number_of_values);
int potega(int liczba, int doPotegi);
void sort(int* arr, int arr_size);
void print_array(int* arr, int arr_size);
float median(int* arr, int arr_size);

#endif
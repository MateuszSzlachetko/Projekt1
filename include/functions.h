#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <chrono>
#include <unistd.h>
#include "sorting_algorithms.h"

enum Order
{
    Ascending,
    Descending
};

void swap(int array[], int index1, int index2);

void print_array(int array[], int num_of_elements);

void Generate_Array(int *arr, int size, double sorted_level, Order type, int range);

void Calculate_time(int elements, double sorted_level, Order o_type, Algo a_type);

void test(double sorted_level, Order type);

#endif // FUNCTIONS_H
#ifndef SORTING_ALGORITHMS_H
#define SORTING_ALGORITHMS_H

#include <iostream>
#include <bits/stdc++.h>

enum Algo
{
    Quicksort,
    Mergesort,
    Introsort
};

int partition(int array[], int left_index, int right_index);

void QuickSort(int array[], int left_index, int right_index);

void MergeSort(int array[], int p, int r);

void Merge(int array[], int p, int q, int r);

void IntrosortUtil(int array[], int begin, int end, int depthLimit, int mod);

void IntroSort(int array[], int begin, int end);

void heapSort(int array[], int n);

void heapify(int array[], int n, int i);

void InsertionSort(int array[], int begin, int end);

#endif // SORTING_ALGORITHMS_H
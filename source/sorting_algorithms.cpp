#include "sorting_algorithms.h"

void QuickSort(int array[], int left_index, int right_index)
{
    if (left_index < right_index)
    {
        int pivot_index = partition(array, left_index, right_index);

        QuickSort(array, left_index, pivot_index - 1);
        QuickSort(array, pivot_index + 1, right_index);
    }
}

int partition(int array[], int left_index, int right_index)
{
    int pivot = array[right_index]; // set right most element as a pivot
    int buff = left_index - 1;

    for (int i = left_index; i < right_index; ++i)
    {
        if (array[i] <= pivot)
        {
            buff++;
            std::swap(array[i], array[buff]);
        }
    }

    std::swap(array[buff + 1], array[right_index]);

    return buff + 1;
}

void MergeSort(int array[], int p, int r)
{
    if (p < r)
    {
        int q = p + (r - p) / 2;

        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);

        Merge(array, p, q, r);
    }
}

void Merge(int array[], int p, int q, int r)
{
    int n = q - p + 1;
    int m = r - q;

    int A[n], B[m];

    for (int i = 0; i < n; i++)
        A[i] = array[p + i];

    for (int j = 0; j < m; j++)
        B[j] = array[q + 1 + j];

    // Po przepisaniu danego zakresu tablicy

    int i, j, k;
    i = 0;
    j = 0;
    k = p;

    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            array[k] = A[i];
            i++;
        }
        else
        {
            array[k] = B[j];
            j++;
        }

        k++;
    }

    while (i < n)
    {
        array[k] = A[i];
        i++;
        k++;
    }

    while (j < m)
    {
        array[k] = B[j];
        j++;
        k++;
    }
}

void InsertionSort(int array[], int begin, int end)
{
    for (int i = begin + 1; i <= end; i++)
    {
        int key = array[i];
        int j = i - 1;

        while (j >= begin && array[j] > key)
        {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }

    return;
}

void IntrosortUtil(int array[], int begin, int end, int depthLimit, int mod)
{
    int size = end - begin;

    if (size < 16)
    {
        InsertionSort(array, begin, end);
        return;
    }

    // If the depth is zero use heapsort
    if (depthLimit == 0)
    {
        heapSort(array, (end - begin) + 1 + mod);
        return;
    }

    // Perform Quick Sort
    if (begin < end)
    {
        int pivot_index = partition(array, begin, end);

        IntrosortUtil(array, begin, pivot_index - 1,
                      depthLimit - 1, mod);
        IntrosortUtil(array, pivot_index + 1, end,
                      depthLimit - 1, mod);

        return;
    }
}

void IntroSort(int array[], int begin, int end)
{
    int depthLimit = 2 * log(end - begin);
    int mod = depthLimit;

    // Perform a recursive Introsort
    IntrosortUtil(array, begin, end, depthLimit, mod);

    return;
}

void heapSort(int array[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(array, n, i);

    for (int i = n - 1; i > 0; i--)
    {
        // Move current root to end
        std::swap(array[0], array[i]);

        // call max heapify on the reduced heap
        heapify(array, i, 0);
    }
}

void heapify(int array[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    // If left child is larger than root
    if (left < n && array[left] > array[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && array[right] > array[largest])
        largest = right;

    // If largest is not root
    if (largest != i)
    {
        std::swap(array[i], array[largest]);

        heapify(array, n, largest);
    }
}
#include "functions.h"

void swap(int array[], int index1, int index2)
{
    int temp = array[index1];

    array[index1] = array[index2];
    array[index2] = temp;
}

void print_array(int array[], int num_of_elements)
{
    std::cout << std::endl;
    for (int i = 0; i < num_of_elements; ++i)
    {
        std::cout << array[i] << " ";

        if (!((i + 1) % 20))
        {
            std::cout << std::endl;
        }
    }

    std::cout << std::endl;
}

void Generate_Array(int arr[], int size, double sorted_level, Order type, int range)
{
    double percentages = 0.01 * sorted_level;

    int sorted_elements = int(size * percentages);

    if (type == 0) // Ascending order
    {
        for (int i = 0; i < sorted_elements; ++i)
        {
            arr[i] = i;
        }

        for (int i = sorted_elements; i < size; ++i)
        {
            arr[i] = rand() % range;
        }
    }
    else // Descending order
    {
        for (int i = 0; i < sorted_elements; ++i)
        {
            arr[i] = (size - 1) - i;
        }

        for (int i = sorted_elements; i < size; ++i)
        {
            arr[i] = rand() % range;
        }
    }
}

void Calculate_time(int elements, double sorted_level, Order o_type, Algo a_type)
{
    int a[elements];
    float time = 0;

    if (a_type == 0) // Quicksort
    {
        for (int i = 0; i < 100; ++i) // badanie dla 100 tablic
        {

            Generate_Array(a, elements, sorted_level, o_type, elements);

            auto start = std::chrono::steady_clock::now();
            QuickSort(a, 0, elements - 1);
            auto end = std::chrono::steady_clock::now();

            time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << std::endl
                  << "Choosen sorting algorithm- Quicksort" << std::endl;
    }
    else if (a_type == 1)
    {
        for (int i = 0; i < 100; ++i) // badanie dla 100 tablic
        {

            Generate_Array(a, elements, sorted_level, o_type, elements);

            auto start = std::chrono::steady_clock::now();
            MergeSort(a, 0, elements - 1);
            auto end = std::chrono::steady_clock::now();

            time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << std::endl
                  << "Choosen sorting algorithm- Mergesort" << std::endl;
    }
    else if (a_type == 2)
    {
        for (int i = 0; i < 100; ++i) // badanie dla 100 tablic
        {

            Generate_Array(a, elements, sorted_level, o_type, elements);

            auto start = std::chrono::steady_clock::now();
            IntroSort(a, 0, elements - 1);
            auto end = std::chrono::steady_clock::now();

            time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        }
        std::cout << std::endl
                  << "Choosen sorting algorithm- Introsort" << std::endl;
    }

    std::cout << "Elapsed time in milliseconds for " << elements << " elements : " << time << " ms" << std::endl;
}

void test(double sorted_level, Order type)
{
    std::cout << sorted_level << "% -----------------------" << std::endl;
    Calculate_time(10000, sorted_level, type, Quicksort);
    Calculate_time(50000, sorted_level, type, Quicksort);
    Calculate_time(100000, sorted_level, type, Quicksort);
    Calculate_time(500000, sorted_level, type, Quicksort);
    Calculate_time(1000000, sorted_level, type, Quicksort);
    std::cout << "-----------------------" << std::endl;
    Calculate_time(10000, sorted_level, type, Mergesort);
    Calculate_time(50000, sorted_level, type, Mergesort);
    Calculate_time(100000, sorted_level, type, Mergesort);
    Calculate_time(500000, sorted_level, type, Mergesort);
    Calculate_time(1000000, sorted_level, type, Mergesort);
    std::cout << "-----------------------" << std::endl;
    Calculate_time(10000, sorted_level, type, Introsort);
    Calculate_time(50000, sorted_level, type, Introsort);
    Calculate_time(100000, sorted_level, type, Introsort);
    Calculate_time(500000, sorted_level, type, Introsort);
    Calculate_time(1000000, sorted_level, type, Introsort);
    std::cout << "--------------------------------" << std::endl;
}
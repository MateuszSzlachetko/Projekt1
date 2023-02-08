#include "functions.h"

int main()
{
    float time = 0;
    int arr[100000];
    for (int i = 0; i < 100; ++i) // badanie dla 100 tablic
    {
        Generate_Array(arr, 100000, 0, Ascending, 100000);
        // print_array(arr, 10000);
        auto start = std::chrono::steady_clock::now();
        IntroSort(arr, 0, 99999);
        auto end = std::chrono::steady_clock::now();
        // print_array(arr, 10000);
        time += std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    }

    std::cout << std::endl
              << time << "ms" << std::endl;
    // test(0, Ascending);
    // test(25, Ascending);
    // test(50, Ascending);
    // test(75, Ascending);
    // test(95, Ascending);
    // test(99, Ascending);
    // test(99.7, Ascending);
    // test(100, Descending);

    // Calculate_time(50000);
    // Calculate_time(100000);
    // Calculate_time(500000);
    // Calculate_time(1000000);

    // print_array(a, 100);
    //  int arr[1000000];
    //  auto start = std::chrono::steady_clock::now();

    // for (int i = 0; i < 1000000; ++i)
    // {
    //     arr[i] = i;
    // }

    // print_array(arr, sizeof(arr) / sizeof(*arr));

    // auto end = std::chrono::steady_clock::now();

    // std::cout << "Elapsed time in milliseconds: "
    //           << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
    //           << " ms" << std::endl;
}
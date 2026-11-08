
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

long long comparisons = 0;
long long swaps = 0;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        comparisons++;

        if(arr[j] < pivot) {
            i++;

            std::swap(arr[i], arr[j]);
            swaps++;
        }
    }

    std::swap(arr[i + 1], arr[high]);
    swaps++;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

int main() {
    int sizes[] = {10, 1000, 10000};

    srand(time(0));

    for(int n : sizes) {
        int arr[n];

        for(int i = 0; i < n; i++) {
            arr[i] = i + 1;
        }

        // BEST CASE
        std::random_shuffle(arr, arr + n);

        comparisons = 0;
        swaps = 0;

        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> runtime = end - start;

        std::cout << "BEST CASE = " << n << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Total Operations: " << comparisons + swaps << std::endl;
        std::cout << "Runtime: " << runtime.count() << " ms\n\n";

        // WORST CASE TEST
        std::reverse(arr, arr + n);

        comparisons = 0;
        swaps = 0;

        start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, n - 1);
        end = std::chrono::high_resolution_clock::now();

        runtime = end - start;

        std::cout << "WORST CASE = " << n << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Total Operations: " << comparisons + swaps << std::endl;
        std::cout << "Runtime: " << runtime.count() << " ms\n\n";
    }

    return 0;
}

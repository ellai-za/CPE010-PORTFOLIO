
#include <iostream>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

void bubbleSort(int arr[], int maxSize, long long &comparisons, long long &swaps) {
    for(int i = 0; i < maxSize; i++) {
        for(int j = i + 1; j < maxSize; j++) {
            comparisons++;
            if(arr[i] > arr[j]) {
                std::swap(arr[i], arr[j]);
                swaps++;
            }
        }
    }
}

int main() {
    int sizes[] = {10, 1000, 10000};

    srand(time(0));

    for(int n : sizes) {
        int arr[n];

        for(int i = 0; i < n; i++) {
            arr[i] = rand() % 50;
        }

        // BEST CASE
        std::sort(arr, arr + n);

        long long comparisons = 0, swaps = 0;

        auto start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n, comparisons, swaps);
        auto end = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double, std::milli> runtime = end - start;

        std::cout << "BEST CASE = " << n << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Total Operations: " << comparisons + swaps << std::endl;
        std::cout << "Runtime: " << runtime.count() << " ms\n\n";

        // WORST CASE
        std::reverse(arr, arr + n);

        comparisons = 0;
        swaps = 0;

        start = std::chrono::high_resolution_clock::now();
        bubbleSort(arr, n, comparisons, swaps);
        end = std::chrono::high_resolution_clock::now();

        runtime = end - start;

        std::cout << "WORST CASE = " << n << std::endl;
        std::cout << "Comparisons: " << comparisons << std::endl;
        std::cout << "Swaps: " << swaps << std::endl;
        std::cout << "Total Operations: " << comparisons + swaps << std::endl;
        std::cout << "Runtime: " << runtime.count() << " ms\n\n";
    }
}

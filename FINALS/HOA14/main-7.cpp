#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "searchingAlgo.h"
#include <chrono>

const int max_size = 100000;
int main(){
    int dataset[max_size];
    srand(time(0));
    for(int i = 0; i < max_size; i++){
        dataset[i] = dataset[i - 1] + (rand() % 100 + 1); 
    }

    std::cout << std::endl;
    std::cout << "Last element: " << dataset[max_size - 1] << std::endl;
    std::cout << "Linear Search: ";

    auto start = std::chrono::high_resolution_clock::now();
    linearSearchArr(max_size, dataset[max_size - 1], dataset);
    

    // Code to measure
    for (int i = 0; i < 1000000; i++);

    auto end = std::chrono::high_resolution_clock::now();

    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);

    std::cout << "Execution Time: "
         << duration.count()
         << " microseconds";
    
    return 0;
}

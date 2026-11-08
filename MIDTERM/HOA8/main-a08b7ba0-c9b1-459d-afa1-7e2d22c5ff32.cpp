#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"

const int max_size = 100;
void display(int list[], int size){
    for(int i = 0; i < size; i++ ){
        std::cout << list[i] << " ";
    }
}

int main(){
    int randArr[max_size];
    srand(time(0));

    for(int i = 0; i < max_size; i++){
        randArr[i] = rand()%10;
    }
    // std::cout << "Array of Values for Sort Algorithm Testing: " << std::endl;
    // display(randArr);
    // std::cout << std:: endl;

    std::cout << "Given Array: " << std::endl;
    int arrGiven[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int shellArr[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int mergeArr[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};
    int quickArr[15] = {4, 34, 29, 48, 53, 87, 12, 30, 44, 25, 93, 67, 43, 19, 74};

    display(arrGiven, 15);
    std::cout << std:: endl;

    std::cout << "Shell Sort: "<< std::endl;
    shellSort(shellArr, 15);
    display(shellArr, 15);
    std::cout << std:: endl;
    
    std::cout << "Merge Sort: "<< std::endl;
    mergeSort(mergeArr, 0, 14);
    display(mergeArr, 15);
    std::cout << std:: endl;
    
    std::cout << "Quick Sort: "<< std::endl;
    quickSort(quickArr, 0, 14);
    display(quickArr, 15);
    std::cout << std:: endl;
    return 0;
}
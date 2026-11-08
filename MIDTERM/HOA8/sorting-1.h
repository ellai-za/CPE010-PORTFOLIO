#ifndef SORTINGARLGO_H
#define SORTINGARLGO_H
#include <iostream>

template <typename T>
void shellSort(T arr[], int arrSize){
    for(int gap = arrSize/2; gap > 0; gap /= 2){
        for(int i = 0; i < arrSize; i++){
            int temp = arr[i];
            int j = i;

            while(j >= gap && arr[j - gap] > temp){
                arr[j] = arr[j - gap];
                j -= gap;
            }

            arr[j] = temp;
        }
    }
}

template <typename T>
void merge(T arr[], int left, int mid, int right){
    int leftSize = mid - left + 1;
    int rightSize = right - mid;

    T leftArray[leftSize];
    T rightArray[rightSize];

    for(int i = 0; i < leftSize; i++){
        leftArray[i] = arr[left + i];
    }

    for(int i = 0; i < rightSize; i++){
        rightArray[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;

    while(i < leftSize && j < rightSize){
        if(leftArray[i] <= rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < leftSize){
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < rightSize){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

template <typename T>
void mergeSort(T arr[], int left, int right){
    if(left < right){
        int middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

template <typename T>
int partition(T arr[], int low, int high){
    T pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[i + 1], arr[high]);

    return i + 1;
}

template <typename T>
void quickSort(T arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

template <typename T>
void quickSortModified(T arr[], int low, int high){
    if(low < high){
        int pivot = partition(arr, low, high);
        mergeSort(arr, low, pivot - 1);
        mergeSort(arr, pivot + 1, high);
    }
}

#endif
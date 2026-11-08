#include <iostream>
#include <thread>

void merge(int arr[], int left, int middle, int right){
    int i = left;
    int j = middle +1;
    int k = 0;

    int size = right - left + 1;
    int* temp = new int[size];

    while (i <= middle && j <= right){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i<=middle){
        temp[k] = arr[i];
        i++;
        k++;
    }
    
    while(j <= right){
        temp[k] = arr[j];
        j++;
        k++;
    }

    for (int x = 0; x < size; x++){
        arr[left + x] = temp[x];
    }

    delete[] temp;
}

void mergeSort(int arr[], int left, int right){

    if (left<right){
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle+1, right);
        merge(arr, left, middle, right);
    }
}

void parallelMergerSort(int arr[], int left, int right){
    if (left < right){
        int middle = (left + right) / 2;

        std::thread t1([&](){
            mergeSort(arr, left, middle);
        });
        std::thread t2([&](){
            mergeSort(arr, middle + 1, right);
        });

        t1.join();
        t2.join();

        merge(arr,left,middle,right);
    }
}

void displayArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}

int main(){

    int arr[] = {8,3,6,2,7,1,5,4};
    int size = sizeof(arr)/sizeof(arr[0]);

    std::cout<<"Original Array: ";
    displayArray(arr, size);

    std::cout<<"Multithreaded Merge Sort: ";
    parallelMergerSort(arr, 0, size - 1);
    displayArray(arr, size);

    return 0;
}
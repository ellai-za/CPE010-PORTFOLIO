#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]){
    for(int i = 0; i < arrSize; i++){
        if (dataFind == list[i]){
            std::cout << "Searching is successful! Found at index "<< i << std::endl;
            return;
        }
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize - 1;

    while (low <= up){
        int mid = int((low + up) / 2);
        if (dataFind == list[mid]){
            std::cout << "Searching is successful! Found at index: " << mid << std::endl;
            return;
        }
        if (dataFind < list[mid]){
            up = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}

#endif
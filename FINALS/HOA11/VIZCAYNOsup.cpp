#include <iostream>
#include <chrono>

int main(){
    int n = 5;
    int arr[n] = {2, 2, 2, 2, 2};

    for(int i = 0; i < n-1; i++){
        for(int j = i+1 ; j < n-1; j++){
            if(arr[i] == arr[j]){
                std::cout<<"FALSE";
            }
        }
    }
    std::cout<<"TRUE";
    

    return 0;
}
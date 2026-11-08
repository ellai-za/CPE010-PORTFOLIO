#include <iostream>
#include <cstdlib>
#include <time.h>
#include "sorting.h"

const int max_size = 100;
void display(int list[]){
    for(int i = 0; i < max_size; i++ ){
        std::cout << list[i] << " ";
        if((i+1) % 10 == 0){ 
            std::cout << std::endl;
        }
    }
}
int countVotes(int list[], int dataFind){
    int count = 0;
    for(int i = 0; i < max_size; i++){
        if(list[i] == dataFind){
            count++;
        }
    }
    return count;
}
void findWinner(int list[]){
    int candidates[5];

    for(int i = 0; i < 5; i++){
        candidates[i] = countVotes(list, (i + 1));
    }
    int highVotes = candidates[0];
    int winner = 0;
    for(int i = 0; i < 5; i++){
        if(candidates[i] > highVotes){
            highVotes = candidates[i];
            winner = (i + 1);
        }
    }
    std::cout << "Winner: Candidate " << winner << std::endl;
}
int findFirst(int list[], int dataFind){
    for(int i = 0; i < max_size; i++){
        if(list[i] == dataFind) return i;
    }
    return -1;
}
int findLast(int list[], int dataFind){
    for(int i = 0; i < max_size; i++){
        if(list[i] > dataFind) return i - 1;
        if(list[i] == dataFind && i == max_size - 1) return i;
    }
    return -1;
}
int findCount(int list[], int dataFind){
    int first = findFirst(list, dataFind);
    if(first == -1) return 0;
    int last = findLast(list, dataFind);
    return (last - first) + 1;
}
void findWinner1(int list[]){
    int candidates[5];
    for(int i = 0; i < 5; i++){
        candidates[i] = findCount(list, (i + 1));
    }
    int highVotes = candidates[0];
    int winner = 0;
    for(int i = 0; i < 5; i++){
        if(candidates[i] > highVotes){
            highVotes = candidates[i];
            winner = (i + 1);
        }
    }
    std::cout << "Winner: Candidate " << winner << std::endl;
}
int main(){
    int randArr[max_size];
    srand(time(0));

    for(int i = 0; i < max_size; i++){
        randArr[i] = rand()%5 + 1;
    }
    display(randArr);

    std::cout << "Insertion Sort: \n";
    insertionSort(randArr, max_size);
    display(randArr);
    std::cout << std::endl;
    std::cout << "Votes for Candidate 1: " << findCount(randArr, 1) << std::endl;
    std::cout << "Votes for Candidate 2: " << findCount(randArr, 2) << std::endl;
    std::cout << "Votes for Candidate 3: " << findCount(randArr, 3) << std::endl;
    std::cout << "Votes for Candidate 4: " << findCount(randArr, 4) << std::endl;
    std::cout << "Votes for Candidate 5: " << findCount(randArr, 5) << std::endl;
    findWinner1(randArr);
    
    return 0;
}
    // std::cout<<"Bubble Sort: \n";
    // bubbleSort(randArr, max_size);
    // display(randArr);

    // std::cout<<"Selection Sort: \n";
    // selectionSort(randArr, max_size);
    // display(randArr);

    



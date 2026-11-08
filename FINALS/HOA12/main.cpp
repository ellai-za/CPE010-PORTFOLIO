#include <iostream>

const int n = 4;

int countPaths(int matrix[n][n], int row, int col, int cost){
    if(row >= n || col >= n){
        return 0;
    }

    cost = cost - matrix[row][col];

    if (cost < 0){
        return 0;
    }

    if (row == n-1 && col == n-1){
        if(cost == 0){
            return 1;
        }
        return 0;
    }

    return countPaths(matrix, row, col + 1, cost) +
    countPaths(matrix, row + 1, col, cost);
}   

int main() {
    int matrix[n][n] = {
        {4,7,1,6},
        {6,7,3,9},
        {3,8,1,2},
        {7,1,7,3}
    };

    int cost;

    std::cout<<"Input target cost: ";
    std::cin>>cost;


    std::cout<<"Target cost: "<<cost<<std::endl;
    std::cout<<"Number of paths: "<<countPaths(matrix, 0, 0, cost)<<std::endl;
}
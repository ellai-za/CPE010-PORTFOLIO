#include <iostream>
#include <cstdlib> //for generating random integers
#include <time.h> //will be used for our seeding function
#include "node.h"
#include "searchingAlgo.h"

// const int max_size = 50;
int main(){
    // PROBLEM 1 & 2

    // int problem1[10] = {15, 18, 2, 19, 18, 0, 8, 14, 19, 14};
    // Node<int>* head = createList<int>();
    // std::cout << "\n\n";
    // int k;

    // std::cout << "What to search for? : ";
    // std::cin >> k;

    // std::cout << "Array LS Result: \n";
    // linearSearchArr(10, k, problem1);
    // std::cout << std::endl;
    // std::cout << "Linked List LS Result: \n";
    // linearSearchLL(head, k);

    // PROBLEM 3 & 4
    Node<int>* node1 = new_node(3);
    Node<int>* node2 = new_node(5);
    Node<int>* node3 = new_node(6);
    Node<int>* node4 = new_node(8);
    Node<int>* node5 = new_node(11);
    Node<int>* node6 = new_node(12);
    Node<int>* node7 = new_node(14);
    Node<int>* node8 = new_node(15);
    Node<int>* node9 = new_node(17);
    Node<int>* node10 = new_node(18);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    node6->next = node7;
    node7->next = node8;
    node8->next = node9;
    node9->next = node10;
    Node<int>* head = node1;

    const int size = 10;
    int problem3[size] = {3, 5, 6, 8, 11, 12, 14, 15, 17, 18};
    std::cout << "Array BS Result: \n";
    binarySearchArr(size, 8, problem3);
    std::cout << "Array BS Recursive Result: \n";
    binarySearchArrRecursive(problem3, 8, 0, size-1);
    
    std::cout << "Linked List BS Result: \n";
    binarySearchLL(head, 8);
    std::cout << "Linked List BS Recursive Result: \n";
    binarySearchLLRecursive<int>(head, nullptr, 8);


    
    return 0;
}
// FOR ARRAY LINEAR SEARCH //

    // // generate random values
    // int dataset[max_size];
    // // because of time(0), everytime the code is run,
    // // the values generated will be RANDOM EVERYTIME
    // srand(time(0));
    // // if you wish to keep the same random set generated
    // // using a fixed value instead of time(0) will do
    // // srand(67);
    // for(int i = 0; i < max_size; i++){
    //     dataset[i] = rand();
    // }
    // // //show your datasets content
    // for(int i = 0; i < max_size; i++ ){
    //     std::cout << dataset[i] << " ";
    //     if((i+1) % 5 == 0 ){ //for easy readability
    //         std::cout << std::endl;
    //     }
    // }
    // std::cout << std::endl;
    // int userInput;
    // std::cout << "What number to search? : ";
    // std::cin >> userInput;
    // std::cout << "Array result LS: ";

    // linearSearchArr(max_size, userInput, dataset);

    // FOR LINKED LIST LINEAR SEARCH //

    // Node<char>* name1 = new_node('E');
    // Node<char>* name2 = new_node('L');
    // Node<char>* name3 = new_node('L');
    // Node<char>* name4 = new_node('A');
    // Node<char>* name5 = new_node('I');
    // Node<char>* name6 = new_node('Z');
    // Node<char>* name7 = new_node('A');

    // name1->next = name2;
    // name2->next = name3;
    // name3->next = name4;
    // name4->next = name5;
    // name5->next = name6;
    // name6->next = name7;

    // listTraversal(name1);

    // char userInput;

    // std::cout << std::endl;
    // std::cout << "What char to search for? : ";
    // std::cin >> userInput;
    // std::cout << "Linked List result LS: "<< std::endl;
    // linearSearchLL(name1, userInput);

    // FOR ARRAY BINARY SEARCH //

    // int dataset[max_size];
    // srand(67);
    // dataset[0] = rand() % 100; 
    // for (int i = 1; i < max_size; i++){
    //     dataset[i] = dataset[i - 1] + (rand() % 100 + 1); 
    // }
    // for(int i = 0; i < max_size; i++ ){
    //     std::cout << dataset[i] << " ";
    //     if((i+1) % 5 == 0 ){ 
    //         std::cout << std::endl;
    //     }
    // }

    // std::cout << std::endl;
    // int userInput;
    // std::cout << "What number to search? : ";
    // std::cin >> userInput;
    // std::cout << "Array result BS: ";
    // binarySearchArr(max_size, userInput, dataset);

    // FOR LINKED LIST BINARY SEARCH

    // int size;
    // int userInput;
    // std::cout << "Creating an ordered linked list\n" 
    //           << "composed of randomly generated values: \n"
    //           << "Enter size of linked list: ";
    // std::cin >> size;
    // Node<int>* head = createOrderedList<int>(size);
    // listTraversal(head);
    // std::cout << "\nLinked List has been created!\n"
    //           << "What to search for? : ";
    // std::cin >> userInput;
    // binarySearchLL(head, userInput);
#include <iostream>
#include "BST.h"

int main(){
    BinarySearchTree<int>* tree = nullptr;
    char choice;
    int value;

    while(true){
        std::cout << "Binary Tree Menu: \n\n"
                  << "A) Insert Value\n"
                  << "B) Pre-Order Traversal\n"
                  << "C) In-Order Traversal\n"
                  << "D) Post-Order Traversal\n"
                  << "E) Exit\n"
                  << "Choice: ";
        std::cin >> choice;
        switch(choice){
            case 'A':
                char userChoice;
                while(true){
                    std::cout << "Creating.. (Enter -1 to stop)" << std::endl;
                    if(tree == nullptr){
                        std::cout << "No root yet\nEnter value: ";
                        std::cin >> value;
                        tree = new BinarySearchTree(value);
                    }else{
                        std::cout << "Enter value: ";
                        std::cin >> value;
                        if(value == -1)break;
                        tree->insert(value);
                    }
                }
                break;
            case 'B':
                std::cout << "Pre-Order Traversal: \n"; 
                tree->preOrder();
                std::cout << std::endl;
                break;
            case 'C':
                std::cout << "In-Order Traversal: \n"; 
                tree->inOrder();
                std::cout << std::endl;
                break;
            case 'D':
                std::cout << "Post-Order Traversal: \n"; 
                tree->postOrder();
                std::cout << std::endl;
                break;
            case 'E':
                return 0;
            default:
                std::cout << "Invalid, Try Again\n";
                break; 
            
        }
    }
    return 0;
}
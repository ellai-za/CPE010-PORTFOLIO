#include <iostream>
#include "listStack.h"

const size_t maxCap = 100;
char stack[maxCap], newData;
int top = -1, elements = 99;
int choice;

//prototyping
void pushA(char newData);
void popA();
void TopA();
bool isFullA();
bool isEmptyA();
void displayAllA();
void checkBalanceA();

int main(){

    while(true){
        char choice;

        std::cout << "Checking for Balanced Symbols..\n"
                << "Test Using: \n"
                << "A ) Stack using Arrays\n"
                << "B ) Stack using Linked Lists\n"
                << "C ) EXIT\n\n"
                << "Choice: ";
        std::cin >> choice;
        
        switch (choice){
            case 'A':
                checkBalanceA();
                break;
            case 'B':
                checkBalanceLL<char>();
                break;
            case 'C':
                std::cout << "Exiting..";
                return 0;
            default:
                std::cout << "Invalid Try Again.";
        }
    }

    return 0;
}

bool isEmptyA(){
    //top is -1
    if(top == -1){
        return true;
    } 
    return false;
}

bool isFullA(){
    //not equal to the maxCap
    if(top >= elements - 1){
        return true;
    }
    return false;
}

void pushA(char newData){

    //check if the stack is full, if yes return an error
    if(isFullA()) return;
    //ask the user for a value to be pushed into the stack
    // std::cout<<"What number you want to add to the stack? ";
    // std::cin >> newData;
    //store inside the stack
    stack[++top] = newData;

}

void popA(){

    //check if there are no more elements inside the stack
    if(isEmptyA()) return;

    //display the element to be popped:
    std::cout<<"Popping: " <<stack[top] <<std::endl;

    //decrement the top
    top--;

}

void Top(){
    //error checking?
    if(isEmptyA()) return;

    //diplay the top element
    std::cout<<"Top element: " <<stack[top]<<std::endl;

}

void displayAllA(){
    if (top == -1) {
        std::cout << "Stack is empty." << std::endl;
        return;
    }

    std::cout << "Displaying all elements (Top to Bottom):" << std::endl;
    for (int i = top; i >= 0; i--) {
        std::cout << stack[i] << std::endl;
    }
}

void checkBalanceA(){
    std::string character;
    std::cout<<"Enter Expression: ";
    std::cin>>character;

    //read each character
    for(int i = 0; i < character.length(); i++){
        //opening symbols
        if(character[i] == '(' || character[i] == '{' || character[i] == '['){
            pushA(character[i]);
        }

        //closing symbols
        if(character[i] == ')' || character[i] == '}' || character[i] == ']'){
            //if the stack is empty error catch
            if(isEmptyA()){
                std::cout<<"Error, unbalanced expression: Stack is empty."<<std::endl;
                return;
            }

            //check if the symbol popped corresponds to the closing symbol
            if((stack[top] == '(' && character[i] != ')') ||
               (stack[top] == '{' && character[i] != '}') ||
               (stack[top] == '[' && character[i] != ']')){
                std::cout<<"Error, unbalanced expression: not corresponding to opening symbol."<<std::endl;
                return;
            }

            //pop the stack
            popA();
        }
    }

    //check if the stack is not empty
    if(top != -1){
        std::cout<<"Error, unbalanced expression: Stack is not empty."<<std::endl;
    }
    else{
        std::cout<<"Valid: Y"<<std::endl;
    }
}
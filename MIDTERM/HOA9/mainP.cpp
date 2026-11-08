#include <iostream>
#include "GenTree.h"

int main(){

    GeneralSearchTree<char>* root = new GeneralSearchTree<char> ('A');

    root->insert('B');
    root->insert('C');
    root->insert('D');
    root->insert('E');
    root->insert('F');
    root->insert('G');

    //D's children
    root->findNode(1, 'D')->insert('H');

    //E's children
    root->findNode(1, 'E')->insert('I');
    root->findNode(1, 'E')->insert('J');

    //J's children
    root->findNode(1, 'J')->insert('P');
    root->findNode(1, 'J')->insert('Q');

    //F's children
    root->findNode(1, 'F')->insert('K');
    root->findNode(1, 'F')->insert('L');
    root->findNode(1, 'F')->insert('M');

    //G's children
    root->findNode(1, 'G')->insert('N');

    //Traversal
    std::cout << "Pre-order:  "; 
    root->preOrder();  
    std::cout << "\n";

    std::cout << "In-order:   "; 
    root->inOrder();   
    std::cout << "\n";

    std::cout << "Post-order: "; 
    root->postOrder(); 
    std::cout << "\n";

    //Finding P
    std::cout<<"Pre-order Location Result: "<<std::endl;
    root->findData(1, 'P');
    std::cout<<"In-order Location Result: "<<std::endl;
    root->findData(2, 'P');
    std::cout<<"Post-order Location Result: "<<std::endl;
    root->findData(3, 'P');

    //Inserting O under node G
    std::cout<<"Pre-order Insertion Result: "<<std::endl;
    root->findNode(1, 'G')->insert('O');
    root->preOrder();
    std::cout << "\n";

    // std::cout<<"In-order Insertion Result: "<<std::endl;
    // root->findNode(2, 'G')->insert('O');
    // root->inOrder(); 
    // std::cout << "\n";

    // std::cout<<"Post-order Insertion Result: "<<std::endl;
    // root->findNode(3, 'G')->insert('O');
    // root->postOrder(); 
    // std::cout << "\n";

}
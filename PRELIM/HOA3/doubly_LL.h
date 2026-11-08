#ifndef DOUBLY_LL_H
#define DOUBLY_LL_H

template <typename T>
class DoubleList{
    public:
    T data;
    DoubleList<T>* prev = nullptr;
    DoubleList<T>* next = nullptr;
};

// create a new node;
template <typename T>
DoubleList<T>* createNode(T newData){
    //dynamically allocate memory for the new node:
    DoubleList<T> *newNode = new DoubleList<T>;

    newNode->data = newData;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    //Return the address of the newly created node
    return newNode;

}

template <typename T>
void dllTraverse(DoubleList<T> *currentNode){
    DoubleList<T> *tail;

    //checking if the list empty
    if(currentNode == nullptr){
        std::cout<<"The list is empty";
        return;
    }

    //forward traversing:
    std::cout<<"Forward: "<<std::endl;
    //moves towards the last node (till it becomes nullptr)
    while(currentNode != nullptr){
        //printed the data
        std::cout<<currentNode->data<<" ";
        //saved the current ndoe as the last visited node
        tail = currentNode;
        //move to the next node
        currentNode = currentNode->next;
    }
    std::cout<<std::endl;

    //backward traversing:
    std::cout<<"Backward: "<<std::endl;
    //move toward the head
    while(tail != nullptr){
        //printed the data
        std::cout<<tail->data<<" ";
        //move towards the previous node
        tail = tail->prev;
    }
    std::cout<<std::endl;
}

template <typename T>
void dllInsertHead(T newData, DoubleList<T>** currentHead){
    //create a new node
    DoubleList<T> *newNode = createNode(newData);

    //new node should point to the current head
    newNode->next = *currentHead;

    //current head should point back to the new
    (*currentHead)->prev = newNode;

    //update the header pointer
    *currentHead = newNode;
}

template <typename T>
void dllInsertAny(T newData, DoubleList<T> *prevNode){
    //check if it is the head node (previous node is null)
    if (prevNode == nullptr){
        std::cout << "Previous node cannot be null!" << std::endl;
        return;
    }
    //create a new node
    DoubleList<T>* newNode = createNode(newData);

    //point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //point previous node to the new node
    newNode->prev = prevNode;

    //if there is a node after prevNode
    //make it point back to the new node
    if (prevNode->next != nullptr){
        prevNode->next->prev = newNode;
    }

    //prevNode now points to the newNode
    prevNode->next = newNode;
}

template <typename T>
void dllInsertEnd(T newData, DoubleList<T> **currentHead, DoubleList<T> **currentNode){
    //create new node
    DoubleList<T> *newNode = createNode(newData);

    //if the list is empty
    if(*currentHead == nullptr){
        *currentHead = newNode;
        *currentNode = newNode;

        //the only node points to itself
        newNode->next = newNode;
        newNode->prev = newNode;

        return;
    }

    //the previous node of head is the last node
    DoubleList<T>* tail = (*currentHead)->prev;

    //connect the new node to the head and tail
    newNode->next = *currentHead;
    newNode->prev = tail;

    //connect the old tail to the new node
    tail->next = newNode;

    //connect the head back to the new node
    (*currentHead)->prev = newNode;

}

template <typename T>
void dllDeleteNode(T findData, DoubleList<T> **currentHead, DoubleList<T> **currentNode){
    //check if list is empty
    if(*currentHead == nullptr) return;

    //find the node to be deleted
    DoubleList<T>* currNode = *currentHead;

    do{
        if(currNode->data == findData){
            break;
        }

        currNode = currNode->next;
    }while(currNode != *currentHead);

    //data was not found
    if(currNode->data != findData){
        return;
    }

    //if there is only one node
    if(currNode->next == currNode){
        delete currNode;
        *currentHead = nullptr;
        *currentNode = nullptr;

        return;
    }

    //connect the previous node to the next node
    currNode->prev->next = currNode->next;

    //connect the next node back to the previous node
    currNode->next->prev = currNode->prev;

    //if the head is being deleted, move head to the next node
    if(currNode == *currentHead){
        *currentHead = currNode->next;
    }

    //if the current song is being deleted, move to the next song
    if(currNode == *currentNode){
        *currentNode = currNode->next;
    }

    //we have to delete node
    delete currNode;

    //deletion complete
}

#endif
#ifndef SINGLY_LL_H
#define SINGLY_LL_H

template <typename T>
class SimplyList{
    public:
        T data;
        SimplyList<T> *next = nullptr;
};

template <typename T>
void listTraversal(SimplyList<T>* head){
    //checks if list is empty
    if(head == nullptr){
        std::cout<<"List is empty."<<std::endl;
        return;
    }
    //while current node is not empty
    //print current data
    //if current next node is not equal to null,
    //print arrow
    //assign current node to current's next node
    while(head != nullptr){
        std::cout<<head->data;
        if(head->next != nullptr){
            std::cout<<"->";
        }
        head = head->next;
    }
}

template <typename T>
void sllinsertHead(T newData, SimplyList<T>** currentHead){
    //1. Allocate memory for new node
    SimplyList<T>* newNode = new SimplyList<T>;

    //2. Put our data into the new node
    newNode->data = newData;

    //3. Set NExt of the new node to point to the previous head
    newNode->next = *currentHead;

    //4. Reset head to point to the new node
    *currentHead = newNode; 
}

template <typename T>
void sllGeneralInsert(T newData, SimplyList<T>* prevNode){
    if (prevNode == nullptr){
        std::cout<<"Previous Node cannot be Null."<<std::endl;
        return;
    }
    //ALlocate a new node
    SimplyList<T>* newNode = new SimplyList<T>;

    //store data in the new node
    newNode->data = newData;

    //point new node to the node previous node was pointing to
    newNode->next = prevNode->next;

    //point previous node
    prevNode->next = newNode;
}

template <typename T>
void sllinsertEnd(T newData, SimplyList<T>** head){
    //allocate new node
    SimplyList<T>* newNode = new SimplyList<T>;

    //dereference to the head node
    SimplyList<T>* currentNode = *head;

    //store data in new node
    newNode->data = newData;

    //point next of new node to NULL
    newNode->next = nullptr;

    //traverse unil next node is null
    while(currentNode->next != nullptr){
        currentNode = currentNode->next;
    }
    //point the next of the current node to the new node
    currentNode->next = newNode;
}
template <typename T>
void sllDeleteNode(T findData, SimplyList<T>** head){
    //check if there is no list to be deleted
    if (*head == nullptr) return;

    //find previous node of the node to be deleted
    SimplyList<T>* currNode = *head;
    SimplyList<T>* prevNode = nullptr;

    //create searching algorithm/loop
    while(currNode != nullptr && currNode->data != findData){
        prevNode = currNode;
        currNode = currNode->next;
    }
    //data was not found
    if (currNode == nullptr) return;

    //if node is to be deleted is the head node
    if(prevNode == nullptr){
        *head = currNode->next;
    }else{
        prevNode->next = currNode->next;
    }

    //we have to delete node
    delete currNode;
}

template <typename T>
void sllDeleteList(SimplyList<T>** head){
    SimplyList<T>* current = *head;

    while(current != nullptr){
        SimplyList<T>* temp = current;
        current = current->next;

        delete temp;
    }
    *head = nullptr;
}

#endif
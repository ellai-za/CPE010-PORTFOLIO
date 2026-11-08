#ifndef NODE_H
#define NODE_H

template <typename T>
class Node{
    public:
        T data;
        Node *next;
};

template <typename T>
Node<T> *new_node(T newData){
    Node<T> *newNode = new Node<T>;
    newNode->data = newData;
    newNode->next = nullptr;
    return newNode;
}

template <typename T>
void listTraversal(Node<T>* head){
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
Node<T>* createOrderedList(int size){
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;

    int value = rand() % 100;

    for(int i = 0; i < size; i++){
        Node<T>* newNode = new_node(value);
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        value += (rand() % 100 + 1);
    }
    return head;
}

template <typename T>
Node<T>* createList(){
    char choice = 'y'; int count = 1; int newData;
    Node<T> *temp, *head, *node;
    while (choice == 'y'){
        std::cout << "Enter data: ";
        std::cin >> newData;
        if (count==1){
            head = new_node(newData);
            std::cout << "Successfully added " << head->data << " to the list.\n";
            count++;
        } else if (count==2) {
            node = new_node(newData);
            head->next = node;
            node->next = nullptr;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        } else {
            temp = head;
            while (true){
                if(temp->next == nullptr) break;
                temp = temp->next;
            }
            node = new_node(newData);
            temp->next = node;
            std::cout << "Successfully added " << node->data << " to the list.\n";
            count++;
        }
        //when to end
        std::cout << "Continue? (y/n)";
        std::cin >> choice;
        if (choice == 'n') break;
    }
    return head;
}


#endif
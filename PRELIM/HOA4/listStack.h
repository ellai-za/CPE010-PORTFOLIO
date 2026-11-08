#ifndef LIST_STACK_H
#define LIST_STACK_H

template <typename T>
class Node{
    public:
    T data;
    Node<T>* next = nullptr;
};

template <typename T>
Node<T>* head = nullptr;

template <typename T>
void push(T newData){
    //create new node
    Node<T>* newNode = new Node<T>;

    //assign the data to the newnode
    newNode->data = newData;

    //link the new node to head
    newNode->next = head<T>;

    //assign the new top to the new node
    head<T> = newNode;
}
template <typename T>
bool isEmpty(){
    return head<T> == nullptr;
}

template <typename T>
T pop(){
    //if the stack is empty error catch
    if(isEmpty<T>()){
        std::cout<<"Stack Underflow"<<std::endl;
    } 

    // saving a current top to a temporary variable
    Node<T>* temp = head<T>;
    
    //store the data of the top node to a temporary var
    T tempVal = temp->data;

    //move the head to next node
    head<T> = head<T>->next;

    //free up the memory
    delete temp;

    //return the temporary variable data
    return tempVal;
}

template <typename T>
void Top(){
    if(isEmpty<T>()) return;

    std::cout<<"The top is: "<<head<T>->data<<std::endl;
}

template <typename T>
void displayStack(){
    if(isEmpty<T>()) return;
    while(head<T> != nullptr){
        std::cout<<head<T>->data;
        if(head<T>->next != nullptr){
            std::cout<<"->";
        }
        head<T> = head<T>->next;
    }
}

template <typename T>
T peek(){
    return head<T>->data;
}

template <typename T>
void checkBalanceLL(){
    std::string character;
    std::cout<<"Enter Expression: ";
    std::cin>>character;

    //read each character
    for(int i = 0; i < character.length(); i++){
        //opening symbols
        if(character[i] == '(' || character[i] == '{' || character[i] == '['){
            push(character[i]);
        }

        //closing symbols
        if(character[i] == ')' || character[i] == '}' || character[i] == ']'){
            //if the stack is empty error catch
            if(isEmpty<T>()){
                std::cout<<"Error, unbalanced expression: Stack is empty."<<std::endl;
                return;
            }

            //pop the stack
            char temp = pop<T>();

            //check if the symbol popped corresponds to the closing symbol
            if((temp == '(' && character[i] != ')') ||
               (temp == '{' && character[i] != '}') ||
               (temp == '[' && character[i] != ']')){
                std::cout<<"Error, unbalanced expression: not corresponding to opening symbol."<<std::endl;
                return;
            }
        }
    }

    //check if the stack is not empty
    if(!isEmpty<T>()){
        std::cout<<"Error, unbalanced expression: Stack is not empty."<<std::endl;
    }
    else{
        std::cout<<"Valid: Y"<<std::endl;
    }
}
#endif
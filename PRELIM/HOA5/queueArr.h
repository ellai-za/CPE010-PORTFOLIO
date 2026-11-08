#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>

template <typename T>
class queueArr{
    private:
        T* q_array;
        size_t q_capacity;
        size_t q_size;
        int q_front;
        int q_back;

    public:
        queueArr(size_t capacity);
        ~queueArr();

        bool Empty();
        bool Full();

        size_t Size();

        void Clear();

        T Front();
        T Back();

        void Enqueue(T newData);
        void Dequeue();

        queueArr(const queueArr& other);
        queueArr& operator = (const queueArr& other);
};

template <typename T>
queueArr<T>::queueArr(size_t capacity){
    //define capacity of the array
    q_capacity = capacity;
    //set the size to 0 
    q_size = 0;
    //set the front and back to 0 and -1 respectively
    q_front = 0;
    q_back = -1;
    //allocate a new space for the q_array that was created
    q_array = new T[q_capacity];
}

template <typename T>
queueArr<T>::~queueArr(){
    delete[] q_array;
}

template <typename T>
bool queueArr<T>::Empty(){
    return q_size == 0;
}

template <typename T>
bool queueArr<T>::Full(){
    return q_size == q_capacity;
}

template <typename T>
size_t queueArr<T>::Size(){
    return q_size;
}

template <typename T>
void queueArr<T>::Clear(){
    //queue size to 0
    q_size = 0;
    //restores q_front and q_back to their initial values
    q_front = 0;
    q_back = -1;
    return;
}

template <typename T>
T queueArr<T>::Front(){
    //check if the queue is not empty
    if(Empty()){
        std::cout<<"The Queue is Empty.\n";
        return T(); //alternative std::optional
    }

    //return the front of the queue
    return q_array[q_front];
}

template <typename T>
T queueArr<T>::Back(){
    //check if the queue is not empty
    if(Empty()){
        std::cout<<"The Queue is Empty.\n";
        return T(); //alternative std::optional
    }

    //return the front of the queue
    return q_array[q_back];
}

template <typename T>
void queueArr<T>::Enqueue(T newData){
    //check if full
    if(Full()){
        std::cout<<"The Queue is Full.\n";
        return;
    }
    //compute for the back index
    q_back = (q_back + 1) % q_capacity;
    //store the newData to the back
    q_array[q_back] = newData;
    //increment size
    q_size++;
}

template <typename T>
void queueArr<T>::Dequeue(){
    //check if full
    if(Empty()){
        std::cout<<"The Queue is Empty.\n";
        return;
    }
    //compute for the back index
    q_front = (q_front + 1) % q_capacity;
    
    //decrement size
    q_size--;

    if(q_size == 0){
        Clear();
        return;
    }
}

#endif

#include "node.h"

#ifndef SEARCHINGALGO_H
#define SEARCHINGALGO_H

template <typename T>
void linearSearchArr(int arrSize, T dataFind, T list[]){
    for(int i = 0; i < arrSize; i++){
        int j = i;
        std::cout << "Count: " << j+1 << std::endl;
        if (dataFind == list[i]){
            std::cout << "Searching is successful!" << std::endl;
            return;
        }
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}

template <typename T>
void linearSearchLL(Node<T> *head, T dataFind){
    int i = 0;
    while (head != nullptr){
        i++;
        std::cout << "Count: " << i << std::endl;
        if(head->data == dataFind){
            std::cout << "Searching is successful!" << std::endl;
            return;
        }
        head = head->next;
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}

template <typename T>
Node<T>* getMiddle(Node<T>* start, Node<T>* last){
    Node<T>* slow = start;
    Node<T>* fast = start;

    while (fast != last && fast->next != last){
        //move slow one step
        slow = slow->next;

        //move fast two steps
        fast = fast->next->next;
    }

    return slow;
}

template <typename T>
void binarySearchArr(int arrSize, T dataFind, T list[]){
    int low = 0, up = arrSize - 1;
    int count = 0;

    while (low <= up){
        int mid = int((low + up) / 2);
        count++;
        std::cout << "\nCount: " << count
                  << "\nLow: Index " << low
                  << "\nMid: Index " << mid
                  << "\nUp: Index " << up << std::endl;
        if (dataFind == list[mid]){
            std::cout << "Searching is successful! Found at index: " << mid << std::endl;
            return;
        }
        if (dataFind < list[mid]){
            up = mid - 1;
        }else{
            low = mid + 1;
        }
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}
template <typename T>
void binarySearchArrRecursive(T list[], T dataFind, int low, int up){
    if (low > up){
        std::cout << "Searching is unsuccessful.." << std::endl;
        return;
    }
    int mid = (low + up) / 2;
    if (dataFind == list[mid]){
        std::cout << "Searching is successful! Found at index: " << mid << std::endl;
        return;
    }
    if (dataFind < list[mid]){
        binarySearchArrRecursive(list, dataFind, low, mid - 1); 
    } else {
        binarySearchArrRecursive(list, dataFind, mid + 1, up); 
    }
}

template <typename T>
void binarySearchLL(Node<T>* start, T dataFind){
    Node<T>* last = nullptr;
    int count = 0;
    while (start != last){
        count++;
        Node<T>* mid = getMiddle(start, last);
        std::cout << "\nCount: " << count
                  << "\nLow: " << start->data
                  << "\nMid: " << mid->data;
        if (last != nullptr){
            std::cout << "\nUp: " << last->data << std::endl;
        }else {
            std::cout << "\nUp: nullptr" << std::endl;
        }
        if (mid->data == dataFind){
            std::cout << "Searching is successful!" << std::endl;
            return;
        }else if (mid->data > dataFind){
            last = mid;
        }else if (mid->data < dataFind){
            start = mid->next;
        }
    }
    std::cout << "Searching is unsuccessful.." << std::endl;
}
template <typename T>
void binarySearchLLRecursive(Node<T>* start, Node<T>* last, T dataFind){
    if (start == last){
        std::cout << "Searching is unsuccessful.." << std::endl;
        return;
    }
    Node<T>* mid = getMiddle(start, last);
    if (mid->data == dataFind){
        std::cout << "Searching is successful!" << std::endl;
        return;
    } else if (mid->data > dataFind){
        binarySearchLLRecursive(start, mid, dataFind);
    } else {
        binarySearchLLRecursive(mid->next, last, dataFind);
    }
}


#endif
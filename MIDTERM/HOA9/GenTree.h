#ifndef GENT_H
#define GENT_H

template <typename T>
class GeneralSearchTree{
    private:
        T key;
        GeneralSearchTree<T>* firstChild;
        GeneralSearchTree<T>* nextSibling;

    public:
        //constructor:
        GeneralSearchTree(T value);

        //insertion
        void insert(T value);

        //traversal:
        void preOrder();
        void inOrder();
        void postOrder();

        //search
        GeneralSearchTree<T>* preFind(T key);
        GeneralSearchTree<T>* inFind(T key);
        GeneralSearchTree<T>* postFind(T key);
        GeneralSearchTree<T>* findNode(int choice, T key);
        void findData(int choice, T key);

};

template <typename T>
GeneralSearchTree<T>::GeneralSearchTree(T value){
    key = value;
    firstChild = nullptr;
    nextSibling = nullptr;
}

template <typename T>
void GeneralSearchTree<T>::insert(T value){
    if(firstChild == nullptr){
        firstChild = new GeneralSearchTree(value);
        return;
    }
    GeneralSearchTree<T>* current = firstChild;
    while(current->nextSibling != nullptr){
        current = current->nextSibling;    
    }
    current->nextSibling = new GeneralSearchTree(value);
}

template <typename T>
void GeneralSearchTree<T>::preOrder(){
    std::cout << key << " ";
    if(firstChild != nullptr){
        firstChild->preOrder();
    }
    if(nextSibling != nullptr){
        nextSibling->preOrder();
    }
}

template <typename T>
void GeneralSearchTree<T>::inOrder(){
    if(firstChild != nullptr){
        firstChild->inOrder();
    }
    std::cout << key << " ";
    if(firstChild != nullptr){
        GeneralSearchTree<T>* current = firstChild->nextSibling;
        while(current != nullptr){
            current->inOrder();
            current = current->nextSibling;
        }
    }
}

template <typename T>
void GeneralSearchTree<T>::postOrder(){
    if(firstChild != nullptr){
        firstChild->postOrder();
    }
    std::cout << key << " ";
    if(nextSibling != nullptr){
        nextSibling->postOrder();
    }
}

template <typename T>
GeneralSearchTree<T>* GeneralSearchTree<T>::preFind(T key){
    if(this->key == key){
        return this;
    }
    if(firstChild != nullptr){
        GeneralSearchTree<T>* result = firstChild->preFind(key);
        if(result != nullptr) return result;
    }
    if(nextSibling != nullptr){
        GeneralSearchTree<T>* result = nextSibling->preFind(key);
        if(result != nullptr) return result;
    }
    return nullptr;
}

template <typename T>
GeneralSearchTree<T>* GeneralSearchTree<T>::inFind(T key){
    if(firstChild != nullptr){
        GeneralSearchTree<T>* result = firstChild->inFind(key);
        if(result != nullptr) return result;
    }
    if(this->key == key){
        return this;
    }
    if(firstChild != nullptr){
        GeneralSearchTree<T>* current = firstChild->nextSibling;
        while(current != nullptr){
            GeneralSearchTree<T>* result = current->inFind(key);
            if(result != nullptr) return result;
            current = current->nextSibling;
        }
    }
    return nullptr;
}

template <typename T>
GeneralSearchTree<T>* GeneralSearchTree<T>::postFind(T key){
    if(firstChild != nullptr){
        GeneralSearchTree<T>* result = firstChild->postFind(key);
        if(result != nullptr) return result;
    }
    if(this->key == key){
        return this;
    }
    if(nextSibling != nullptr){
        GeneralSearchTree<T>* result = nextSibling->postFind(key);
        if(result != nullptr) return result;
    }
    return nullptr;
}

template <typename T>
GeneralSearchTree<T>* GeneralSearchTree<T>::findNode(int choice, T key){
    GeneralSearchTree<T>* found = nullptr;
    switch (choice){
        case 1:
            found = preFind(key);
            break;
        case 2:
            found = inFind(key);
            break;
        case 3:
            found = postFind(key);
            break;
        default:
            break;
    }
    return found;
}

template <typename T>
void GeneralSearchTree<T>::findData(int choice, T key){
    GeneralSearchTree<T>* found = nullptr;

    switch (choice){
        case 1:
            found = preFind(key);
            break;
        case 2:
            found = inFind(key);
            break;
        case 3:
            found = postFind(key);
            break;
        default:
            break;
    }
    if(found != nullptr){
        std::cout<<key<<" was found!"<<std::endl;
    }
}

#endif
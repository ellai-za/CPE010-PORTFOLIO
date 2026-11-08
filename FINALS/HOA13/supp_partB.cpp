#include <iostream>
#include <thread>

int globalVar = 0;
void add(int n){
    globalVar += n;
}
int main(){
    std::thread t1(add, 10000);
    std::thread t2(add, 10000);
    std::thread t3(add, 10000);

    std::cout<<"Global Variable = "<<globalVar<<std::endl;
    t1.join();

    std::cout<<"Global Variable = "<<globalVar<<std::endl;
    t2.join();

    std::cout<<"Global Variable = "<<globalVar<<std::endl;
    t3.join();

    std::cout<<"Global Variable = "<<globalVar<<std::endl;

    return 0;
}
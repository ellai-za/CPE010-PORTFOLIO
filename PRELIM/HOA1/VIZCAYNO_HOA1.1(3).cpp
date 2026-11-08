#include <iostream>
#include <cmath>

void swapNum(int& a, int& b);
float convertKtoF(float k);
float distanceBetTwo(float x1, float y1, float x2, float y2);

int main(){
	int userInput;
	int num1, num2;
	float kelvin;
	float x1, y1, x2, y2;

	do{
		std::cout<<"=== >OPERATIONS< ===\n"
					"0) Exit\n"
					"1) Swap 2 Numbers\n"
					"2) Convert Kelvin to Fahrenheit\n"
					"3) Distance Between 2 Points\n\n"
					"Input number from menu: ";
		std::cin>>userInput;
		switch(userInput){
			case 0:
				break;
			case 1:
				std::cout<<"\n=== >SWAP 2 NUMBERS< ===\n";
				std::cout<<"Enter first number: ";
				std::cin>>num1;
				std::cout<<"Enter second number: ";
				std::cin>>num2;
				std::cout<<"Before swap: "<<num1<<" "<<num2<<std::endl;
				swapNum(num1, num2);
				std::cout<<"After swap: "<<num1<<" "<<num2<<std::endl;
				std::cout<<"\n==================\n";
				break;
			case 2:
				std::cout<<"\n=== >KELVIN TO FAHRENHEIT< ===\n";
				std::cout<<"Enter temperature in Kelvin: ";
				std::cin>>kelvin;
				std::cout<<kelvin<<" K = "<<convertKtoF(kelvin)<<" F"<<std::endl;
				std::cout<<"\n==================\n";
				break;
			case 3:
				std::cout<<"\n=== >DISTANCE BETWEEN 2 POINTS< ===\n";
				std::cout<<"Enter x1: ";
				std::cin>>x1;
				std::cout<<"Enter y1: ";
				std::cin>>y1;
				std::cout<<"Enter x2: ";
				std::cin>>x2;
				std::cout<<"Enter y2: ";
				std::cin>>y2;
				std::cout<<"Distance = "<<distanceBetTwo(x1, y1, x2, y2)<<std::endl;
				std::cout<<"\n==================\n";
				break;
			default:
				std::cout<<"\nINVALID\n"<<std::endl;
		}
	}while(userInput!=0);

	return 0;
}
void swapNum(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}
float convertKtoF(float k){
    float f = (k - 273.15)*(1.8)+32;
    return f;
}
float distanceBetTwo(float x1, float y1, float x2, float y2){
    float distance = sqrt(pow(x2-x1, 2) + pow(y2-y1, 2)); 
    return distance;
}
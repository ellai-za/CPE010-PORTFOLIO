#include <iostream>

double sumOFtwo(double num1, double num2);
void valueCompare(double val1, double val2);
bool logicalOperations(bool boolA, bool boolB);

int main(){
	int userInput;
	double num1, num2;
	bool boolA, boolB;

	do{
		std::cout<<"=== >OPERATIONS< ===\n"
					"0) Exit\n"
					"1) Sum of 2 Numbers\n"
					"2) Compare 2 Values\n"
					"3) Boolean Logical Operations\n\n"
					"Input number from menu: "; 
		std::cin>>userInput;
		switch(userInput){
			case 0:
				break;
			case 1:
				std::cout<<"\n=== >SUM OF 2 NUMBERS< ===\n";
				std::cout<<"Enter number for value 1: ";
				std::cin>>num1;
				std::cout<<"Enter number for value 2: ";
				std::cin>>num2;
				std::cout<<num1<<" + "<<num2<<sumOFtwo(num1, num2)<<std::endl;
				std::cout<<"\n==================\n";
				break;
			case 2:
				std::cout<<"\n=== >COMPARE 2 VALUES< ===\n";
				std::cout<<"Enter number for value 1: ";
				std::cin>>num1;
				std::cout<<"Enter number for value 2: ";
				std::cin>>num2;
				valueCompare(num1, num2);
				std::cout<<"\n==================\n";
				break;
			case 3:
                std::cout<<"\n=== >BOOLEAN LOGICAL OPERATIONS< ===\n";
				std::cout<<"Enter 1st Boolean Value(1 = true, 0 = false): ";
				std::cin>>boolA;
				std::cout<<"Enter 2nd Boolean Value(1 = true, 0 = false): ";
				std::cin>>boolB;
				logicalOperations(boolA, boolB);
				std::cout<<"\n==================\n";
				break;
			default:	
				std::cout<<"\nINVALID\n"<<std::endl;
		}
	}while(userInput != 0);

	return 0;
}

double sumOFtwo(double num1, double num2){
	double sum=num1+num2;
	return sum;
}
void valueCompare(double val1, double val2){
	if(val1 > val2){
		std::cout<<val1<<" is greater than "<<val2<<std::endl;	
	}
	else if(val1 < val2){
		std::cout<<val2<<" is greater than "<<val1<<std::endl;	
	}
	else{
		std::cout<<"Both are equal."<<std::endl;
	}
}
bool logicalOperations(bool boolA, bool boolB){
	std::cout<<"A && B = "<<(boolA && boolB)<<std::endl;
	std::cout<<"A || B = "<<(boolA || boolB)<<std::endl;
	std::cout<<"!A = "<<(!boolA)<<std::endl;
	std::cout<<"!B = "<<(!boolB)<<std::endl;

	return true;
}

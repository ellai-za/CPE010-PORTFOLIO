#include <iostream>
#include <string>

class Student{
  private:
    std::string studentName;
    int studentAge;
  
  public:
    //constructor
    Student(std::string newName = "JohnDoe", int newAge = 18){
      studentName = newName;
      studentAge = newAge;
      std::cout<<"The constructor was called."<<std::endl;
    };
    //destructor
    ~Student(){
      std::cout<<"The destructor was called."<<std::endl;
    }
    
    //copy constructor
    Student (const Student &copyStudent){
      std::cout<<"The copy constructor was called."<<std::endl;
      studentName = copyStudent.studentName;
      studentAge = copyStudent.studentAge;
    }
    
    //display attributes
    void printDetails(){
      std::cout<<this->studentName<<" "<<this->studentAge<<std::endl;
    }
    
};


int main() {
	const size_t j = 5;
	
	Student studentList[j] = {};
	std::string nameList[j] = {"Angel", "Ellaiza", "Ninya" ,"Fenzie", "Joma" };
	int ageList[j] = {18, 19, 19, 19, 19};
      
    for (int i = 0; i < j; i++){ //loop A
    	Student *ptr = new Student(nameList[i], ageList[i]);
    	studentList[i] = *ptr;
      delete ptr; //was added to release heap memory in line 44
	}
	
	for(int i = 0; i < j; i++){ //loop B
		studentList[i].printDetails();
	}
	
  return 0;
}
//Ellaiza C. Vizcayno
//CPE21S3
//Thank you sir
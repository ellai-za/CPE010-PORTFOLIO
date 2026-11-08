#include <iostream>

//naming convention for class name: PascalCase
class Triangle{
	private:
		double totalAngle, angleA, angleB, angleC;
		double base, height;
		double side1, side2, side3;
	public:
		//constructor
		Triangle(double A, double B, double C, double Ba,
			 double H, double S1, double S2, double S3);
		void setAngles(double A, double B, double C);
		void setDimensions(double Ba, double H, double S1,
						 double S2, double S3);
		double findArea();
		double findPerimeter();
		void triangleTypeAngles();
		void triangleTypeSides();
		//triangle validation
		const bool validateTriangle();
};
int main(){

    Triangle triangle(60, 60, 60, 10, 8, 10, 10, 10);

    std::cout<<"Area: "<<triangle.findArea()<<std::endl;
    std::cout<<"Perimeter: "<<triangle.findPerimeter()<<std::endl;

    std::cout<<"Triangle Type by Angles: ";
    triangle.triangleTypeAngles();

    std::cout<<"Triangle Triangle by Sides: ";
    triangle.triangleTypeSides();

    return 0;
}
Triangle::Triangle(double A, double B, double C, double Ba, 
				double H, double S1, double S2, double S3){
	angleA=A;
	angleB=B;
	angleC=C;
	totalAngle=A+B+C;
	base=Ba;
	height=H;
	side1=S1;
	side2=S2;
	side3=S3;
}
void Triangle::setAngles(double A, double B, double C){
	angleA=A;
	angleB=B;
	angleC=C;
	totalAngle=A+B+C;
} 
void Triangle::setDimensions(double Ba, double H, double S1,
						 	double S2, double S3){
	base=Ba;
	height=H;
	side1=S1;
	side2=S2;
	side3=S3;
}
double Triangle::findArea(){
	return (base * height) / 2;
}
double Triangle::findPerimeter(){
	return side1 + side2 + side3;
}
void Triangle::triangleTypeAngles(){
	if(angleA < 90 && angleB < 90 && angleC < 90){
		std::cout<<"Acute"<<std::endl;
	}else if(angleA == 90 || angleB == 90 || angleC == 90){
		std::cout<<"Right"<<std::endl;
	}else if(angleA > 90 || angleB > 90 || angleC > 90){
		std::cout<<"Obtuse"<<std::endl;
	}else{
		std::cout<<"Invalid"<<std::endl;
	}
}
void Triangle::triangleTypeSides(){
	if (validateTriangle()){
		if(side1 == side2 && side1 == side3){
			std::cout<<"Equilateral"<<std::endl;
		}else if((side1 == side2 && side2 != side3)||
				(side2 == side3 && side3 != side1) ||
			 	(side3 == side1 && side1 != side2)){
			std::cout<<"Isosceles"<<std::endl;
		}else if(side1 != side2 && side1 != side3 &&
				side2 != side3){
			std::cout<<"Scalene"<<std::endl;
		}else{
		std::cout<<"Invalid"<<std::endl;
	}
	}else{
		std::cout<<"Invalid"<<std::endl;
	}
}
const bool Triangle::validateTriangle(){
	return(totalAngle<=180);
}

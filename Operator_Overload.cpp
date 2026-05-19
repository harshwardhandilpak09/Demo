//Design a C++ class Complex with data members to store the real and imaginary parts. 
// Provide default and parameterized constructors. Implement operator overloading
// for +, -, and * to perform arithmetic operations on complex numbers. Write a program 
// that creates two complex objects and displays the results of these operations

#include<iostream>
using namespace std;

class Complex{
	public:
	float real;
	float imag;

	Complex(){
		real = 0;
		imag = 0;
	}

	Complex(float real, float imag){
		this->real = real;
		this->imag = imag;
	}

	void input(){
		cout<<"Enter real value:"<<endl;
		cin>>real;

		cout<<"Enter imag part:"<<endl;
		cin>>imag;
	}

	void display(){
		cout << real << " + "<<imag<<endl;
	}

	Complex operator + (const Complex &c){
		return Complex(real + c.real, imag + c.imag);
	}

	Complex operator - (const Complex &c){
		return Complex(real - c.real, imag - c.imag);
	}

	Complex operator * (const Complex &c){
		float r = real * c.real - imag * c.imag;
		float i = real * c.real + imag * c.imag;
		return Complex(r,i);
	}
};

int main(){
	Complex c1,c2;
	Complex add, sub, mul;

	cout<<"Enter the values for first complex number :"<<endl;
	c1.input();

	cout<<"Enter the values for second complex number :"<<endl;
	c2.input();

	add = c1 + c2;
	sub = c1 - c2;
	mul = c1 * c2;

	cout<<"First Complex number:"<<endl;
	c1.display();

	cout<<"Second Complex number:"<<endl;
	c2.display();

	cout<<"Sum :"<<endl;
	add.display();

	cout<<"Sub :"<<endl;
	sub.display();

	cout<<"Mul :"<<endl;
	mul.display();


	return 0;
}
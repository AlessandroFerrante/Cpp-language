/*
 author Alessandro Ferrante
 * complex.cpp
*/
? to manage the algebra of complex numbers;
/*
 ? The example shows the redefinition of the operators + - \ *
 ? to manage the algebra of complex numbers;
 ? If I define an operator inside a class it becomes a method
*/
#include <iostream>

using namespace std;

class Complex{
    private:
        // attributes
        float real, imaginary;
    public: 
        // constructor
        Complex(float r, float i){
            real = r;
            imaginary = i;
        }   
        // default constructor
        Complex() : Complex(0 ,0){}
        // copy constructor
        Complex(const Complex & c) : Complex(c.real, c.imaginary){ }

        friend ostream& operator <<(ostream& output_stream, Complex & c){
            output_stream << c.real;
            if(c.imaginary < 0)
                output_stream << c.imaginary;
            else
                output_stream << "+" << c.imaginary;
            output_stream << "i";
            return output_stream;
        }

        Complex operator+(Complex & rhs); //? sum between complex numbers
        Complex operator+(double rhs); //? sum of complex numbers and reals
        Complex operator-(Complex & rhs); // ? subtraction between complex numbers
        Complex operator-(double rhs); // ? subtraction between complex numbers and reals
        Complex operator*(Complex & rhs); // ? multiplication between complex numbers
        Complex operator/(Complex & rhs);// ? division between complex numbers
};

Complex Complex::operator+(Complex & rhs){
    // ? Initializes the complex number complex object
    //* result.real = this->real + rhs.real;
    //* resutl.imaginary = this->imaginary + rhs.imaginary;
    // ? calls the constructor and initializes the complex number object
    Complex result(real + rhs.real, imaginary + rhs.imaginary);
    return result;
}

Complex Complex::operator+(double rhs){
    // ? Initializes the complex number complex object
    Complex result(real + rhs, imaginary);
	return result;
} 

Complex Complex::operator-(Complex & rhs){
    // ? Initializes the complex number complex object
    //* result.real = this->real - rhs.real;
    //* resutl.imaginary = this->imaginary - rhs.imaginary;
    // ? calls the constructor and initializes the complex number object
    Complex result(real - rhs.real, imaginary - rhs.imaginary);
    return result;
}

Complex Complex::operator-(double rhs){
    // ? Initializes the complex number complex object
    Complex result(real - rhs, imaginary);
	return result;
} 

Complex Complex::operator*(Complex & rhs){
	Complex result(real*rhs.real - imaginary*rhs.imaginary, real*rhs.imaginary + imaginary*rhs.real);
	return result;
}

Complex Complex::operator/(Complex & rhs){
	float den = rhs.real * rhs.real + rhs.imaginary * rhs.imaginary;
	
	Complex result( (real*rhs.real + imaginary*rhs.imaginary) / den,(imaginary*rhs.real - real*rhs.imaginary) / den );
	return result;
}

int main (int agrc, char ** argv){
    
    Complex a, b(1,2), c(3,4);
	
	cout << a << ", " << b << ", " << c << endl;
	
	Complex d = b + c;
	// Complex d = b.operator+(c);
	cout << d << endl;
	
	d = b - c;
	cout << d << endl;
	
	d = c + 3;
	cout << d << endl;
	
	d = c - 3.5;
	cout << d << endl;
	
	d = b * c;
	cout << d << endl;

	d = b / c;
	cout << d << endl;
}
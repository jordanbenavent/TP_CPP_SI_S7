#include "Complex.h"
#include <math.h>

std::ostream& operator<<(std::ostream& os, const Complex& c){
    os << c.real << "+ i" << c.imaginary << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, Complex& c){
    std::cout<< "Enter the real part :" << std::endl;
    is >> c.real;
    std::cout<< "Enter the imaginary part :" << std::endl;
    is >> c.imaginary;
    return is;
}

Complex Complex::operator+(const Complex& other){
    Complex result;
    result.real = real+other.real;
    result.imaginary = imaginary+other.imaginary;
    return result;
}

double Complex::module(){
    return sqrt(real*real + imaginary*imaginary);
}
#pragma once
#include <iostream>

class Complex {

    double real;
    double imaginary;

    public :

    Complex(double a=0, double b=0) : real(a), imaginary(b) {};

    friend std::ostream& operator<< (std::ostream& os, const Complex& c);

    friend std::istream& operator>> (std::istream& is, Complex& c);

    Complex operator+(const Complex& other);

    double module();

};
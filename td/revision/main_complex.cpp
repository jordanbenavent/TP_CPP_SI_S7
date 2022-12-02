#include "Complex.h"
#include "PureImaginary.h"

int main (){
    Complex c;
    std::cout << c;
    std::cin >> c;
    std::cout << c;
    Complex c1(1,1);
    Complex c2(3,3);
    std::cout << c1+c2;
    std::cout << c2.module() << std::endl;
    PureImaginary p(6);
    std::cout<<p;
    std::cout<<p.module() << std::endl;

}
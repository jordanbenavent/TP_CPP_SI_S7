#include<vector>
#include <iostream>

class A {
    private : 

    std::vector<int> vec;

    public :

    void f2() {
        std::cout << "A!" << std::endl;
    }

    A(){
        vec = std::vector(10,0);
    }

    int operator[] (int i) const {
        return vec[i];
    }

    int& operator[] (int i){
        return vec[i];
    }

    friend std::ostream& operator<< (std::ostream &os, const A &a);
};
class B : public A {

    public :

    void f2() {
        std::cout << "B!" << std::endl;
    }

    static string getBugSegmentation(){
        return "jesuiunbug"
    }

};

 std::ostream& operator<< (std::ostream &os, const A &a){
    for(int i =0; i< a.vec.size(); i++){
        os << a[i] << " ";
    } 
    os << std::endl;
    return os;
 }

int main()
{
    A a = A();
    std::cout<<a;
    a[0]=3;
    std::cout<<a;
    B b;
    b.A::f2();

    return 0;
}



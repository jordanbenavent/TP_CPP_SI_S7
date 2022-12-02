#include "pile.h"
/*
std::ostream& operator<<(std::ostream &os,Stack &s){
    Stack copy = Stack(s);
    while(!copy.is_empty()){
        os << copy.get_first() << " ";
    }
    os << std::endl;
    return os;
}*/

void Stack::push(int n){
    (*this).prepend(n);
}
#include <iostream>
#include "list-copy.h"

template <typename T>
class Stack : private List<T>
{
    public:
    Stack() :  List<T>() {};
    void push(T n);
    T pop(){ return (*this).get_first();}
    bool is_empty(){ return List<T>::is_empty();}
    friend std::ostream& operator<<(std::ostream &os,Stack<T> &s){return os << (List<T>)s << std::endl;};
};

template <typename T>
void Stack<T>::push(T n){
    (*this).prepend(n);
}
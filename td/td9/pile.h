#include <iostream>
#include "list-copy.h"

class Stack : private List
{

    public:
    Stack() :  List() {};
    void push(int n);
    int pop(){ return (*this).get_first();}
    bool is_empty(){ return List::is_empty();}
    friend std::ostream& operator<<(std::ostream &os,Stack &s){return os << (List)s << std::endl;};
};
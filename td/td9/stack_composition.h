#pragma once
#include <iostream>
#include "list-copy.h"

class Stack {
    List l;

    public:
    void push(int n){
        l.prepend(n);
    }
    int pop(){
        return l.get_first();
    }
    bool is_empty(){
        return l.is_empty();
    }
    friend std::ostream& operator<< (std::ostream& os, Stack& sc){
        return os << sc.l;
    }

};
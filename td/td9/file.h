#pragma once
#include "list-copy.h"
#include <iostream>

class Queue : protected List {

    public:
    Queue(): List(){}
    void put(int n);
    int get(){ return (*this).get_first();}
    bool is_empty(){ return List::is_empty();}
    friend std::ostream& operator<<(std::ostream &os,Queue &q){return os << (List)q << std::endl;};

};
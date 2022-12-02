#pragma once
#include "list-copy.h"
#include <iostream>

template <typename T>
class Queue : protected List<T> {

    public:
    Queue(): List<T>(){}
    void put(T n);
    T get(){ return (*this).get_first();}
    bool is_empty(){ return List<T>::is_empty();}
    friend std::ostream& operator<<(std::ostream &os,Queue<T> &q){return os << (List<T>)q << std::endl;};

};

template <typename T>
void Queue<T>::put(T n){
    (*this).append(n);
}
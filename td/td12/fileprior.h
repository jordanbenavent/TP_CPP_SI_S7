#pragma once
#include "file.h"
#include <iostream>

template <typename T>
class Priority_Queue : public Queue<T> {

    public:
    void put(T n);

};

template <typename T>
void Priority_Queue<T>::put(T n){
    (*this).insert(n);
}
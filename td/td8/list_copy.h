#pragma once
#include <iostream>


class List {
    
    class Cell { 
    
    public:
    int value;
    Cell *next{nullptr};

    Cell(int n): value(n){}
    };

    Cell *start;
    Cell *end;
    int size;

    public:
    List(): start(nullptr), end(nullptr), size(0){}
    void append(int n);
    void prepend(int n);
    int get_first();
    bool is_empty();
    void insert(int n);
    void sort();
    int get_middle_value();
    int& max();
    int get_last();
    int get_size(){return size;}
    void mirror();

    friend std::ostream& operator<<(std::ostream& os, const List& list); 

    //td8
    List(const List &other);
    List &operator=(const List &other);
    ~List();
    friend List operator+(const List &l1,const List &l2);
    friend List operator*(const List &l1,const List &l2);
};
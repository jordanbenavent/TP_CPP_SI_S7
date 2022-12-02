//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Specification
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: List-final.h,v 1.3 2004/11/20 16:16:05 jpr Exp $
//=======================================================================

#ifndef _LIST_H_
#define _LIST_H_

#include <iostream>
#include <cassert>
using namespace std;

#include "common_defs.h"

template <typename T>
class List
{
private:
    
   // The list Cell type 
    
    struct Cell
    {
        T val;
        Cell *next;
        Cell(T v, Cell *n = 0) : val(v), next(n) {}
        ~Cell() {delete next;} // Recursive destructor
    };

    // 
    Cell *head;         // Pointer to first cell
    Cell *tail;         // Pointer to last cell

public:
    // Exception

    class Empty {};

    // Construction

    List() : head(0), tail(0) {}

    ~List()
    { 
	cout << "*** List destructor ***" << endl; 
	delete head; // Destroy first cell (recursive destruction) 
	// another solution is, of course, to loop other the cells 
	// (see the corresponding --- commented --- code in List-final.cpp 
    } 

    // Copy constructor and copy assignment
    List(const List<T>&);
    List<T>& operator=(const List<T>&);

    // Accessor ?
    
    bool is_empty() const {return head == 0;}

    // Adding elements to the list
    
    void append(T);   // at the end
    void prepend(T);  // at the beginning
	void insert(T);	// for sorted lists : at the right place !

    // Removing elements from the list en tete de liste
    
    T get_first();

    // Display
    template <typename U>
    friend ostream& operator<<(ostream&, const List<U>&);

	T get_middle_value() const
	{
		Cell *pp;	// previous pointer
		Cell *p;	// (fast) pointer

		for (pp=p=head; p!=0 && p->next !=0; pp=pp->next, p=p->next->next) ;  // nothing in the loop
		return pp->val;
	}
};

template <typename T>
List<T>::List(const List<T>& l)
    : head(0), tail(0)
{
    for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
        append(pcell->val);
}

template <typename T>
List<T>& List<T>::operator=(const List<T>& l)
{
    if (this != &l)
    {
        delete head; head = tail = 0;
        for (Cell *pcell = l.head; pcell != 0; pcell = pcell->next)
            append(pcell->val);
    }
    return *this;       
}

//-----------------------------------------------------------------------
// Adding elements to the list
//-----------------------------------------------------------------------

template <typename T>
void List<T>::append(T v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        tail->next = p;
        tail = p;
    }
}

// Au debut
template <typename T>
void List<T>::prepend(T v)
{
    Cell *p = new Cell(v);
    if (head == 0) head = tail = p;
    else
    {
        p->next = head;
        head = p;
    }
}
template <typename T>
void List<T>::insert(T e)
{
    Cell *p, *pprev;

    for (p = head, pprev = 0; p != 0 && p->val < e; pprev = p, p = p->next) {}

    if (pprev != 0) // inserting in the middle or at the end
    {
        Cell *ptemp = new Cell(e, pprev->next);
        pprev->next = ptemp;
        if (p == 0) tail = ptemp;
    }
    else prepend(e);   // inserting in front
}

//-----------------------------------------------------------------------
// Removing elements from the list
//-----------------------------------------------------------------------

template <typename T>
T List<T>::get_first()
{
    if (head == 0) throw Empty();
    T v = head->val;
    if (tail == head) tail = 0;
    Cell *p = head;
    head = head->next;
    p->next = 0; // needed: otherwise the next line destroy the whole list!
    delete p;
    return v;
}

//-----------------------------------------------------------------------
// Display
//-----------------------------------------------------------------------

template <typename T>
ostream& operator<<(ostream& os, const List<T>& l)
{

    typename List<T>::Cell *p;
    for (p = l.head; p != 0; p = p->next) cout << p->val << ' ';
    return os;
}




#endif

#include "list_copy.h"

/*
outils valgrid --tool memcheck
*/


std::ostream& operator<<(std::ostream& os, const List& list){
    List::Cell *tmp = list.start;
    while(tmp != nullptr) {
        os << tmp->value << " ";
        tmp = tmp->next;
    }
    return os;
}

void List::append(int n){
    Cell *c = new Cell(n);
    if(start == nullptr){
        start = c;
        end = c;
    } else {
        end->next = c;
        end = c;
    }
    size++;
}

void List::prepend(int n){
    Cell *c = new Cell(n);
    if(start == nullptr){
        start = c;
        end = c;
    } else {
        c->next = start;
        start = c;
    }
    size++;
}

int List::get_first(){
    int result = start->value;
    Cell *tmp = start->next;
    delete start;
    start = tmp;
    size--;
    return result;
}

bool List::is_empty(){
    if(start == nullptr ) return true;
    return false;
}

void List::insert(int n){
    Cell *c = new Cell(n);
    if(start == nullptr ){
        start = c;
        end = c;
    } else {
        if(start->value > n){ // début
            c->next = start;
            start = c;

        } else {
            Cell *current = start;
            while(current->next != nullptr && current->next->value < n){
                current = current->next;
            }
            c->next = current->next;
            current->next = c;

        }
    }
    size++;
}

void List::sort(){
    if(is_empty()) return;
    List listSorted;
    while(!is_empty()){
        listSorted.insert(get_first());
    }
    start = listSorted.start;
    end = listSorted.end;
    size = listSorted.size;
}

int List::get_middle_value(){
    Cell *tmp = start;
    for(int i=0; i<size/2; i++){
        tmp = tmp->next;
    }
    return tmp->value;
}

int& List::max(){
    if(is_empty()) {
        throw -1;
    }
    Cell *maxCell = start;
    Cell *current = start->next;
    while(current != nullptr){
        if(current->value > maxCell->value){
            maxCell = current;
        }
        current = current->next;
    }
    return maxCell->value;
}

int List::get_last(){
    if(is_empty()){
        throw -1;
    } else if(size == 1) {
        return get_first();
    } else {
        Cell *previous = start;
        Cell *current = start->next;
        while(current->next != nullptr){
            previous = current;
            current = current->next;
        }
        end = previous;
        end->next = nullptr;
        size--;
        int result = current->value;
        delete current;
        return result;
    }
}

void List::mirror(){
    List tmp;
    while(start){
        tmp.prepend(get_first());
    }
    *(this) = tmp;
}

//td8

List::List(const List &other){
    if(other.start != nullptr){
        Cell *current = other.start;
        Cell *newCell = new Cell(current->value);
        start = newCell;
        Cell *currentCopy = start;
        current = current->next;
        while(current != nullptr) {
            newCell = new Cell(current->value);
            currentCopy->next = newCell;
            currentCopy = currentCopy->next;
            current = current->next;
        }
        end = newCell;
    }
}

List &List::operator=(const List &other){
    if(&other != this){
        if(other.start != nullptr){
            Cell *current = other.start;
            Cell *newCell = new Cell(current->value);
            start = newCell;
            Cell *currentCopy = start;
            current = current->next;
            while(current != nullptr) {
                newCell = new Cell(current->value);
                currentCopy->next = newCell;
                currentCopy = currentCopy->next;
                current = current->next;
            }
            end = newCell;
        }
    }
    return *this;
}

List::~List(){
    if(start != nullptr){
        Cell *previous = start;
        Cell *current = start->next;
        while(current != nullptr){
            delete previous;
            previous = current;
            current = current->next;
        }
    }
}

List operator+(const List &l1, const List &l2){
    /*
    List copy1 = l1;
    List copy2 = l2;
    copy1.end->next = copy2.start;
    std::cout << "1" << std::flush;
    copy1.end = copy2.end;
    */
    List r;
    List::Cell *current1 = l1.start;
    List::Cell *current2 = l2.start;
    while(current1 != nullptr){
        r.append(current1->value);
        current1 = current1->next;
    }
    while(current2 != nullptr){
        r.append(current2->value);
        current2 = current2->next;
    }
    return r;
}

List operator*(const List &l1,const List &l2){
    List result;
    List::Cell *current1 = l1.start;
    List::Cell *current2 = l2.start;
    while((current1 != nullptr) && (current2 != nullptr)){
        result.append(current1->value);
        result.append(current2->value);
        current1 = current1->next;
        current2 = current2->next;
    }
    while(current1 != nullptr){
        result.append(current1->value);
        current1 = current1->next;
    }
    while(current2 != nullptr){
        result.append(current2->value);
        current2 = current2->next;
    }
    return result;
}
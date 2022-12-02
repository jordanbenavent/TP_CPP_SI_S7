#include "list_simple.h"


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
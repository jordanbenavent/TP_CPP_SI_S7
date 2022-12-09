
#include <iostream>


class Movable {

    static int movable;
    int id;

    public:

    Movable(){
        id = movable;
        std::cout << "Default constructor "<<  id << " called"<< std::endl;
        movable++;
    }

    Movable(const Movable &c){
        id = movable;
        std::cout << "Copy constructor "<<  id << " called"<< std::endl;
        movable++;
    }

    ~Movable(){
        if(id != 0){
            std::cout << "Destructor "<<  id << " called"<< std::endl;
        }
    }

    Movable& operator=(Movable &c){
        id = movable;
        std::cout << "Copy assignment "<<  id << " called"<< std::endl;
        movable++;
        return *this;
    }

    Movable& operator=(Movable &&c){
        id = c.id;
        c.id = 0;
        std::cout << "Move assignment "<<  id << " called"<< std::endl;
        return *this;
    }

    Movable(Movable &&c){
        id = c.id;
        c.id = 0;
        std::cout << "Move constructor "<<  id << " called"<< std::endl;
    }

};

int Movable::movable = 1;
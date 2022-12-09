#include <iostream>


class Copiable {

    static int copiable;
    int id;

    public:

    Copiable(){
        id = copiable;
        std::cout << "Default constructor "<<  id << " called"<< std::endl;
        copiable++;
    }

    Copiable(const Copiable &c){
        id = copiable;
        std::cout << "Copy constructor "<<  id << " called"<< std::endl;
        copiable++;
    }

    ~Copiable(){
        std::cout << "Destructor "<<  id << " called"<< std::endl;
    }

    Copiable& operator=(const Copiable &c){
        id = copiable;
        std::cout << "Copy assignment "<<  id << " called"<< std::endl;
        copiable++;
        return *this;
    }

};

int Copiable::copiable = 1;
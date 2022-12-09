


#include <iostream>

template <typename T>
class UniquePtr {

    int id;
    int static unique;
    T *p;

    public:

    UniquePtr(){
        id = unique;
        unique++;
        p = new T();
        std::cout << "Default constructor "<<  id << " called"<< std::endl;
    }

    UniquePtr(const UniquePtr<T> &c) = delete;

    ~UniquePtr() = delete;

    UniquePtr<T>& operator=(UniquePtr<T> &c)= delete;

    UniquePtr<T>& operator=(UniquePtr<T> &&c){
        p = new T(p);
        c.p = nullptr;
        std::cout << "Move assignment "<<  id << " called"<< std::endl;
        return *this;
    }

    UniquePtr<T>(UniquePtr<T> &&c){
        p = c.p;
        c.p = nullptr;
        std::cout << "Move constructor "<<  id << " called"<< std::endl;
    }

    T& operator*() const {
        return *p;
    }

};

template <typename U> UniquePtr<U>::unique = 1;
#pragma once

#include "string"

class Menu_Item {
    std::string name;

    public:
    Menu_Item(std::string n): name(n){}
    virtual std::string getName() const{
        return name;
    }
    virtual ~Menu_Item(){}
    virtual void execute() const = 0;
};
#pragma once

#include "menu_item.h"
#include "string"

class Simple_Menu_Item : public Menu_Item
{
    typedef void (*foncPtr)();
    foncPtr fonc;

    public:
    Simple_Menu_Item(std::string n, foncPtr fct): Menu_Item(n), fonc(fct){

    }

     void execute() const override {
        fonc();
     }
};
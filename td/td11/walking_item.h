#pragma once

#include "menu_item.h"
#include "menu.h"
#include "string"
#include <vector>

class Walking_Menu : public Menu_Item, public Menu {

    public:
    Walking_Menu(std::string n, std::vector<Menu_Item*> i):  Menu_Item(n), Menu(n,i){
    }

    std::string getName() const override {
        return Menu_Item::getName() + " -> ";
    }
    void execute() const override {
        activate();
    }
};
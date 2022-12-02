#pragma once

#include <vector>
#include <string>
#include <iostream>

#include"menu_item.h"

class Menu
{
    std::string name;
    std::vector<Menu_Item*> items;

    public:
    Menu(std::string n, std::vector<Menu_Item*> v): name(n), items(v){}
    virtual void activate(void) const {
            std::cout<<"      " <<name << std::endl;
            int size = items.size();
            for(int i =0; i< size; i++){
                std::cout<< i <<" : " << items[i]->getName() << std::endl;
            }
            std::cout <<"Your choice? ";
            int choice;
            std::cin>> choice;
            items[choice]->execute();
    }
};
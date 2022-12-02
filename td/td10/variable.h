#pragma once
#include "expr-abstract.h"
#include <iostream>
#include <string>
#include <map>

std::map<std::string, int> myMap;

class Variable_Ref : public Expr {

    std::string name;

    public:
    Variable_Ref(std::string nom) : name(nom){
        myMap[nom] = 0;
    }

    int eval() const override{
        return myMap[name];
    }

    std::string getName(){
        return name;
    }



};

class Assignment : public Expr {

    Variable_Ref *_ref;

    public:
    Assignment(Variable_Ref *ref, Expr *exp): _ref(ref){
         myMap[ref->getName()] = exp->eval();
    }

    int eval() const override{
       
        return _ref->eval();
    }
};
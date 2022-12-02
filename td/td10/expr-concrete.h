#pragma once

#include "expr-abstract.h"

class Constant: public Expr {

    int value;

    public:
    Constant(int val): value(val){} 
    virtual int eval() const override {
        return value;
    }
};

class Factoriel: public Unary_Expr {

    public:
    Factoriel(Expr *exp): Unary_Expr(exp){}
    int eval() const override{
        int fac = op->eval();
        int result = 1;
        for(int i = fac; i>0; i--){
            result *= i;
        }
        return result;
    }
};

class Unary_Minus: public Unary_Expr {

    public:

    Unary_Minus(Expr *exp) : Unary_Expr(exp){}

    int eval() const override{
        return -1 * op->eval();
    }
};

class Binary_Mult: public Binary_Expr {

    public:

    Binary_Mult(Expr *exp1, Expr *exp2): Binary_Expr(exp1,exp2){}
    int eval() const override{
        return opl->eval() * opr->eval();
    }
};

class Binary_Minus: public Binary_Expr {

    public:

    Binary_Minus(Expr *exp1, Expr *exp2): Binary_Expr(exp1,exp2){}
    int eval() const override{
        return opl->eval() - opr->eval();
    }
};

class Binary_Plus: public Binary_Expr {

    public:

    Binary_Plus(Expr *exp1, Expr *exp2): Binary_Expr(exp1,exp2){}
    int eval() const override{
        return opl->eval() + opr->eval();
    }
};

class Binary_Div: public Binary_Expr {

    public:

    Binary_Div(Expr *exp1, Expr *exp2): Binary_Expr(exp1,exp2){}
    int eval() const override{
        if(opr->eval() == 0 ) throw ZeroDivide();
        return opl->eval() / opr->eval();
    }
};

class Binary_Mod: public Binary_Expr {

    public:

    Binary_Mod(Expr *exp1, Expr *exp2): Binary_Expr(exp1,exp2){}
    int eval() const override{
        if(opr->eval() == 0 ) throw ZeroDivide();
        return opl->eval() % opr->eval();
    }
};

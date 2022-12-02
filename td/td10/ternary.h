#pragma once

#include "expr-abstract.h"

class Ternary_Exp : public Expr{

    protected:
    Expr *cond, *exp1, *exp2;

    public:
    Ternary_Exp(Expr *c, Expr *e1, Expr *e2): cond(c), exp1{e1}, exp2(e2){
    }
};

class Ternary_Conditional: public Ternary_Exp {

    public:
    Ternary_Conditional(Expr *cond, Expr *exp1, Expr *exp2): Ternary_Exp(cond, exp1, exp2){}

    int eval() const override{
        int c = cond->eval();
        if(c){
            return exp1->eval();
        } else {
            return exp2->eval();
        }
    }
};


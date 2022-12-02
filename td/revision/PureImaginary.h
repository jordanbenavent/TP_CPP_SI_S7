#pragma once
#include "Complex.h"

class PureImaginary : public Complex {

    public:
    PureImaginary(double value=0) : Complex(0,value){}
};
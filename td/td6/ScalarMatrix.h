#pragma once

#include "DiagonalMatrix.h"

class ScalarMatrix : public DiagonalMatrix {

    public:
    ScalarMatrix() = default;
    ScalarMatrix(int n):DiagonalMatrix(n){};
    ScalarMatrix(int n, double value);
    friend ScalarMatrix operator+(const ScalarMatrix& sm1,const ScalarMatrix& sm2);
    friend ScalarMatrix operator*(const ScalarMatrix& sm1,const ScalarMatrix& sm2);

};
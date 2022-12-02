#pragma once
#include "Matrix.h"

class SquareMatrix : public Matrix {
    
    public:
    SquareMatrix() = default;
    SquareMatrix(int n):Matrix(n,n){};
    SquareMatrix(int n, double value):Matrix(n,n, value){};
    SquareMatrix(const Matrix& mat);
    double det();
};
#pragma once
#include "SquareMatrix.h"

class DiagonalMatrix : public SquareMatrix {

    public:
    DiagonalMatrix() = default;
    DiagonalMatrix(int n):SquareMatrix(n){};
    DiagonalMatrix(const MVector &mv);
    /*
    DiagonalMatrix(const Matrix& mat);
    bool isDiagonal(const Matrix& mat);
    class Not_DiagonalMatrix {};*/
};
#include "DiagonalMatrix.h"

DiagonalMatrix::DiagonalMatrix(const MVector &mv): SquareMatrix(mv.size()){
    for(int i=0; i < nlines(); i++){
        (*this)[i][i]= mv[i];
    }
}

/*
DiagonalMatrix::DiagonalMatrix(const Matrix& mat): Matrix(mat){
    if(ncols() != nlines()) throw Bad_Dimensions();
    if(!isDiagonal(mat)) throw Not_DiagonalMatrix();
}

bool DiagonalMatrix::isDiagonal(const Matrix& mat){
    if(mat.ncols() <= 1 ) return true;
    double valueNotDiag = mat[0][1];
    for( int i=0; i<mat.ncols(); i++ ){
        for( int j=0; j<mat.ncols(); j++ ){
            if(i==j) continue;
            if(mat[i][j]!=valueNotDiag) return false;
        }
    }
    return true;
}*/
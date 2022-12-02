#include "ScalarMatrix.h"

ScalarMatrix::ScalarMatrix(int n, double value):DiagonalMatrix(n){
    for(int i=0; i < this->nlines(); i++){
        (*this)[i][i]= value;
    }
}

ScalarMatrix operator+(const ScalarMatrix& sm1,const ScalarMatrix& sm2){
    if(sm1.nlines()!= sm2.nlines()) throw ScalarMatrix::Bad_Dimensions();
    ScalarMatrix result = ScalarMatrix(sm1.ncols());
    for(int i=0; i < sm1.nlines(); i++){
        result[i][i]= sm1[i][i] + sm2[i][i];
    }
    return result;
}

ScalarMatrix operator*(const ScalarMatrix& sm1,const ScalarMatrix& sm2){
    if(sm1.nlines()!= sm2.nlines()) throw ScalarMatrix::Bad_Dimensions();
    ScalarMatrix result = ScalarMatrix(sm1.ncols());
    for(int i=0; i < sm1.nlines(); i++){
        result[i][i]= sm1[i][i] * sm2[i][i];
    }
    return result;
}
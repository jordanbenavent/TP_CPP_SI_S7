#pragma once
#include <vector>
#include "MVector.h"

class Matrix
{
    private:
    int lign;
    int col;
    std::vector<MVector> m;

    public:
    Matrix()  = default;
    Matrix(int ligne, int column, double value=0);
    Matrix(MVector vector);
    int getNbLigne(){ return lign;}
    int getNbColumn(){ return col;}
    friend ostream& operator<<(ostream& os, const Matrix& m);
    friend bool operator==(const Matrix& m1, const Matrix& m2);
    Matrix& operator+=(const Matrix& matrice);
    Matrix& operator-=(const Matrix& matrice);
    Matrix operator*=(const Matrix& matrice);
    friend Matrix operator*(const Matrix& m1, const Matrix& m2);
    friend Matrix operator+(const Matrix& m1, const Matrix& m2);
    friend Matrix operator-(const Matrix& m1, const Matrix& m2);
    Matrix transpose();
    double& operator()(int i, int j){ return m[i][j];}
    friend Matrix operator~(Matrix &m);
    MVector line(int i){ return m[i];}
    MVector column(int i);
    double det();

    class Bad_Dimensions {};

};
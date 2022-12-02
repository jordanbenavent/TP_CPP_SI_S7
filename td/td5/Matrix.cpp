#include <iostream>
#include "Matrix.h"
#include <cmath>


Matrix::Matrix(int ligne, int column, double value):lign(ligne), col(column), m(ligne, MVector(column,value)){}

ostream& operator<<(ostream& os, const Matrix& matrice){
    int nbligne = matrice.lign;
    os << " [ " << std::endl; ;
    for(int i=0; i<nbligne; i++){
        os << matrice.m[i] << std::endl;
    }
    return os;
}

bool operator==(const Matrix& m1, const Matrix& m2){
    if(m1.lign != m2.lign) return false;
    if(m1.col != m2.col) return false;
    int nbligne = m1.lign;
    for(int i=0; i<nbligne; i++){
        if(m1.m[i]!=m2.m[i]) return false;
    }
    return true;
}

Matrix& Matrix::operator+=(const Matrix& matrice) {
    (*this)=(*this)+matrice;
    return (*this);
}

Matrix& Matrix::operator-=(const Matrix& matrice) {
    (*this)=(*this)-matrice;
    return (*this);
}

Matrix Matrix::operator*=(const Matrix& matrice){
    (*this)=(*this)*matrice;
    return (*this);
}

Matrix operator*(const Matrix& m1, const Matrix& m2){
    int nbcolom1 = m1.col;
    int nbligne1 = m1.lign;
    int nbcolom2 = m2.col;
    int nbligne2 = m2.lign;
    if(nbcolom1!=nbligne2) throw Matrix::Bad_Dimensions();
    Matrix result = Matrix(nbligne1, nbcolom2, 0);
    for(int i=0; i<nbligne1; i++){
        for(int j=0; j<nbcolom2; j++){
            for(int k=0; k<nbligne2; k++){
                result.m[i][j] += m1.m[i][k]*m2.m[k][j];
            }
        }
    }
    return result;    
}

Matrix operator+(const Matrix& m1, const Matrix& m2){
    int nbligne = m1.lign;
    int nbligne2 = m2.col;
    int nbcolom = m1.lign;
    int nbcolom2 = m1.col;
    if(nbligne!=nbligne2 || nbcolom != nbcolom2) throw Matrix::Bad_Dimensions();
    Matrix result = Matrix(nbligne, nbcolom, 0);
    for(int i=0; i<nbligne; i++){
        result.m[i]+=(m1.m[i]+ m2.m[i]);
    }
    return result;
}

Matrix operator-(const Matrix& m1, const Matrix& m2){
    int nbligne = m1.lign;
    int nbligne2 = m2.lign;
    int nbcolom = m1.col;
    int nbcolom2 = m1.col;
    if(nbligne!=nbligne2 || nbcolom != nbcolom2) throw Matrix::Bad_Dimensions();
    Matrix result = Matrix(nbligne, nbcolom, 0);
    for(int i=0; i<nbligne; i++){
        result.m[i]-=(m1.m[i]- m2.m[i]);
    }
    return result;
}

Matrix Matrix::transpose(){
    Matrix result = Matrix(col, lign);
    for(int i=0; i<lign; i++){
        for(int j=0; j<col; j++){
            result.m[j][i] = m[i][j];
        }
    }
    return result;
}

Matrix operator~(Matrix &m){
    return m.transpose();
}

MVector Matrix::column(int i){
    MVector result = MVector(lign);
    if(i>col) throw Matrix::Bad_Dimensions();
    int nb = 0;
    for( int j=0;j<lign; j++){
        result[nb]=(m[j][i]);
        nb++;
    }
    return result;
}

Matrix::Matrix(MVector vector):lign(1), col(vector.size()){
    m = std::vector<MVector>();
    m.push_back(vector);
}

double Matrix::det(){
    if(col!=lign) throw Bad_Dimensions();
    if(col==2){
        return line(0)[0]*line(1)[1] - line(0)[1]* line(1)[0];
    }
    int deter = 0;
    Matrix result = Matrix(lign-1, col-1);
    for (int i= 0; i<col; i++){//ligne avec laquelle on calcul le det
        int subi =0;
        for(int j=1; j<col; j++){ // on récupère les sous-matrice à partir de la ligne 2
            int subj =0;
            for(int k=0; k<lign; k++){
                if(k==i) continue;
                result.m[subi][subj] = m[j][k];
                subj++;
            }
            subi++;
        }
        deter += (pow(-1,i)*m[0][i] * result.det());
    }
    return deter;
}

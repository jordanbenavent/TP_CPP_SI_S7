#include "mvector.h"
#include <tgmath.h> 


MVector::MVector(int nb, double value): v(nb,value){}

MVector::MVector(std::vector<double> other) : v(other[0], other[1]){
    //v = std::vector<double>(vector[0],vector[1]);
}

std::ostream& operator<<( std::ostream& os,const  MVector &mv){
    int size = mv.v.size();
    os << "[";
    for(int i=0; i<size; i++){
        os << mv.v[i];
        if(i != size - 1) {
            os << ", ";
        }
    }
    os << "]";
    return os;
}

MVector& MVector::operator+=(const MVector &other){
    int size = other.v.size();
    for(int i=0; i<size; i++){
        v[i] += other[i];
    }
    return (*this);
}

MVector& MVector::operator-=(const MVector &other){
    int size = other.v.size();
    for(int i=0; i<size; i++){
        v[i] -= other[i];
    }
    return (*this);
}

double operator*(const MVector v1, const MVector v2){
    int size1 = v1.v.size();
    int size2 = v2.v.size();
    if(size1 != size2) {return 0;}
    double sum;
    for(int i = 0; i< size1; i++){
        sum += (v1[i]*v2[i]);
    }
    return sum;
}

double MVector::norm() {
    return sqrt((*this)*(*this));
}

MVector MVector::operator+(const MVector &other)const {
    int size1 = v.size();
    int size2 = other.v.size();
    MVector result;
    if(size1 != size2) { throw Bad_Dimensions();}
    for(int i = 0; i< size1; i++){
        result.v.push_back(v[i]+other[i]);
    }
    return result;
}

MVector MVector::operator-(const MVector &other)const {
    int size1 = v.size();
    int size2 = other.v.size();
    MVector result;
    if(size1 != size2) { throw Bad_Dimensions();}
    for(int i = 0; i< size1; i++){
        result.v.push_back(v[i]-other[i]);
    }
    return result;
}


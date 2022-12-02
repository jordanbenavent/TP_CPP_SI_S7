#pragma once
#include <vector>
#include <iostream>

class MVector {

    std::vector<double> v;

    public:
        MVector() = default;
        MVector(int nb, double value);
        MVector(std::vector<double> other);
        friend std::ostream& operator<<(std::ostream& os, const MVector &v);
        bool operator==(MVector &other) const { return v==other.v;}
        double operator[](int i) const { return v[i];}
        double &operator[](int i){ return v[i];}
        MVector &operator+=(const MVector &);
        MVector &operator-=(const MVector &);
        friend double operator*(const MVector v1, const MVector v2);
        double norm();
        MVector operator+(const MVector &other) const;
        MVector operator-(const MVector &other) const;

        class Bad_Dimensions: public std::exception{};
};

//double operator*(const MVector v1, const MVector v2);

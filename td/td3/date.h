#pragma once
#include <iostream>
/**
 * Jordan Benavent
 * 
 **/

class Date {
    int day, month, year;

    public :

        Date(int annee=2016, int mois=11, int jour=21);
        friend std::ostream& operator<<(std::ostream& os, Date d);
        friend std::istream& operator>>(std::istream& is, Date& d);
        int calculNbrJour(Date date);
        Date operator+(int i);
        Date operator++(int);
        Date operator-(int i);
        Date operator--(int);
        Date operator+=(int);
        Date operator-=(int );
        bool operator==(Date);
        bool operator!=(Date);
        bool operator<=(Date);
        bool operator>=(Date);
        bool operator<(Date);
        bool operator>(Date);
        int operator-(Date);
};
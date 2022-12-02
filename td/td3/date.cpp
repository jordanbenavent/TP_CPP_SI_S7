#include "date.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
//using namespace std;

Date::Date(int annee, int mois, int jour) : year(annee), month(mois), day(jour) {
}

const std::string month[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

std::ostream& operator<<( std::ostream& os, Date d){
    
    os << month[d.month -1] << " " << d.day << "," << d.year;
    return os;
}

std::istream& operator>>( std::istream& is, Date& d){
    std::string chaine;
    std::cin >> chaine;
    std::stringstream split(chaine);
    std::vector<std::string> tokens;
    for (std::string each; std::getline(split, each, '/'); tokens.push_back(each));
    if(tokens.size() != 3 ) throw std::runtime_error("Mauvais format");
    d.year = std::stoi(tokens[0]);
    d.month = std::stoi(tokens[1]);
    d.day = std::stoi(tokens[2]);
    return is;
}

bool yearsBissextile(int years){
    if( years % 4 == 0){
        if( years % 100 == 0 ){
            if( years % 400 == 0){
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}


int Date::calculNbrJour(Date date){
    if(date.month==1 || date.month==3 || date.month==5 || date.month==7 || date.month==8 || date.month==10 || date.month==12 ){
        return 31;
    } else {
        if(date.month==4 || date.month==6 || date.month==9 || date.month==11){
            return 30;
        } else {
            if(yearsBissextile(date.year)){
                return 29;
            }
            return 28;
        }
    }
}

Date Date::operator++(int ){
    Date res = Date(year, month, day);
    int dayPerMonth = calculNbrJour(res);
    if(month == 12 && day == 31){
        day = 1;
        month = 1;
        year++;
    } else {
        if(day == dayPerMonth){
            day = 1;
            month++;
        } else {
            day++;
        }
    }
    return res;
}

Date Date::operator+(int i){
    Date result(year,month, day);
    int nbj = i;
    while(nbj--){
        result++;
    }
    /*
    int jour;
    jour = i;
    while ((jour+result.day)>calculNbrJour(result))
    {       
        jour -= calculNbrJour(result.month)-result.day+1;
        if(result.month == 12 ){
            result.day = 1;
            result.month = 1;
            result.year++;
        } else {
            result.day = 1;
            result.month++;
        }
    }
    result.day+=jour;
    return result;
    */
   return result;
}

Date Date::operator--(int ){
    if(day==1 && month==1){
        day = 31;
        month = 12;
        year--;
    } else {
        if(day == 1){
            month--;
            day = calculNbrJour(*this);
        } else {
            day--;
        }
    }
    return *this;
}

Date Date::operator-(int i){
    Date res = Date(year, month, day);
    while(i--){
        res--;
    }
    return res;
}

Date Date::operator+=(int i){
    int nbj = i;
    while(nbj--){
        (*(this))++;
    }
    return *this;
}

Date Date::operator-=(int i){
    int nbj = i;
    while(nbj--){
        (*(this))--;
    }
    return *this;
}

bool Date::operator==(Date d){
    return day==d.day && month==d.month && year==d.year;
}

bool Date::operator!=(Date d){
    return ! ((*this)==d);
}

bool Date::operator<(Date d){
    if(year < d.year){ return true; }
    if(month < d.month && year==d.year){ return true; }
    if(day < d.day && month==d.month && year==d.year){ return true; }
    return false;
}

bool Date::operator>(Date d){
    if(year > d.year){ return true; }
    if(month > d.month && year==d.year){ return true; }
    if(day > d.day && month==d.month && year==d.year){ return true; }
    return false;
}

bool Date::operator<=(Date d){
    return ! ((*this)>d);
}

bool Date::operator>=(Date d){
    return ! ((*this)<d);
}

int Date::operator-(Date d){
    Date tmp = Date(d.year,d.month,d.day);
    int ecart = 0;
    if(*(this)<=d){
        while(*(this)!=tmp){
            tmp--;
            ecart--;
        }
    } else {
        while(*(this)!=tmp){
            tmp++;
            ecart++;
        }
    }
    return ecart;
}
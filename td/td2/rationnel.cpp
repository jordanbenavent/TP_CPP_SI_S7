#include <iostream>
#include <numeric>
#include <stdexcept>
using namespace std;

int mypgcd(int a, int b){
    int pgcd = 0;
 
    while(1)
    {
        pgcd = a % b;
        if(pgcd == 0)
        {
            pgcd = b;
            break;
        }
        a = b;
        b = pgcd;
    }
 
    return pgcd;
}

class Rationnel 
{
    int num;
    unsigned int denom;

    public :
    
    Rationnel(int n=0): num(n),denom(1){}
    
    Rationnel(int a, int b){
        if( b == 0 ) {
            throw runtime_error("Denominateur == 0 !");
        }
        num = a;
        denom = b;
        simplifier();
    }

    void affiche(){
        cout << "Nombre : " << num << " / " << denom << endl;
    }

    void simplifier(){
        int pgcd = std::gcd(num,denom);
        num=num/pgcd;
        denom=(denom/pgcd);
    }

    friend ostream& operator<<(ostream& os, const Rationnel& rat);   

    friend istream& operator>>(istream& is, Rationnel& rat);  

    Rationnel operator*(const Rationnel &);
    //complexe &operator+=(const complexe &)

    Rationnel operator+(const Rationnel &); //ok

    Rationnel operator-(Rationnel &); //ok
    
    Rationnel operator-(); //ok

    Rationnel operator+=(const Rationnel &);

    Rationnel operator-=(const Rationnel &);

    /*
    Rationnel operator+=( Rationnel &r){
        num = (*(this)+r).num;
        denom = (*(this)+r).denom;
        return *(this);
    }

    Rationnel operator-=( Rationnel &other){
        Rationnel r(num, denom);
        r = r-other;
        return r;
    }
    */

    Rationnel operator/(const Rationnel &); //ok

    bool operator==( Rationnel &r){
        simplifier();
        r.simplifier();
        return num==r.num && r.denom==r.denom;
    }
    
    bool operator!=( Rationnel &r){
        return !(*(this)==r);
    }

    bool operator<( Rationnel &r){
        return ((float)num/denom - (float)r.num/r.denom) <0;
    }

    bool operator>( Rationnel &r){
        return ((float)num/denom - (float)r.num/r.denom) >0;
    }

    bool operator>=( Rationnel &r){
        return !((*this)<r);
    }

    bool operator<=( Rationnel &r){
        return !((*this)>r);
    }

    void inverse(){
        int tmp = denom;
        denom = num;
        num = tmp;
    }



};

ostream& operator<<(ostream& os, const Rationnel& rat)
{
    os << rat.num << " / " << rat.denom << endl;
    return os;
}

istream& operator>>(istream& is, Rationnel& rat){
    //cout << "Entrer numérateur : " << flush;
    is >> rat.num;
    is >> rat.denom;
    rat.simplifier();
    return is;
}
//complexe &complexe::operator+=(const complexe &c)

Rationnel Rationnel::operator*(const Rationnel &r1)
{
    //cout << num << r1.num << denom << r1.denom ;
    int a = num * r1.num;
    int b = denom * r1.denom;
    return Rationnel(a,b);
}

Rationnel Rationnel::operator/(const Rationnel &r1)
{
    //cout << num << r1.num << denom << r1.denom ;
    Rationnel r(r1.num, r1.denom);
    r.inverse();
    return *(this)*r;
}

Rationnel Rationnel::operator+(const Rationnel &r1)
{
    int a = num * r1.denom + r1.num * denom;
    int b = denom * r1.denom;
    return Rationnel(a,b);
}

Rationnel Rationnel::operator-(){
    return Rationnel(-num,denom);
}

Rationnel Rationnel::operator-(Rationnel &r1)
{
    return *(this)+(-r1); 
}

Rationnel Rationnel::operator+=(const Rationnel &r1){
    num = num*r1.denom + denom*r1.num;
    denom *= r1.denom;
    (this)->simplifier();
    return *(this);
}

Rationnel Rationnel::operator-=(const Rationnel &r1){
    num = num*r1.denom - denom*r1.num;
    denom *= r1.denom;
    (this)->simplifier();
    return *(this);
}


int main(){
    cout << boolalpha;
    Rationnel r1(8,3);
    Rationnel r2(1,1);
    Rationnel r3(9,3);
    r1.affiche();
    r2.affiche();
    /*
    r3.affiche();
    cout << r1 << endl;
    cin >> r1;
    cout << r1<< endl;
    */
    cout<< "r1 = " << r1;
    cout << "Ici test r1+=r1 : " << (r1+=r1);
    cout<< "r1 = " << r1;
    cout << "Ici test r1-=r1 : " << (r1-=r1);
    cout<< "r1 = " << r1;
    r1 = Rationnel(8,3);
    cout<< "r1 = " << r1 << "et r2 = " << r2;
    Rationnel r4 = r1+r2;
    cout << "r1 + r2 = "<< r4 << endl;
    cout<< "r4 = " << r4 << "et r1 = " << r1;
    r4 = r4-r1;
    cout << "r4 - r1 = "<< r4;
    cout << "r1 = " <<r1 << "-r1 = " <<(-r1);
    Rationnel r(8,3);
    cout << "r= " << r;
    r.inverse();
    cout << "1/r = " << r;
    cout << "r= " << r;
    r4 = Rationnel(7,2);
    cout << "r4= " << r4;
    cout << "r/r4= " << r/r4;
    cout << "r1==r1 " << (r1==r1) << endl;
    cout << "r1!=r1 " <<(r1!=r1) << endl;
    cout << "r1==r4 " << (r1==r4) << endl;
    cout << "r1!=r4 " <<(r1!=r4) << endl;
    r1= Rationnel(2,1);
    r2= Rationnel(3,1);
    cout << r1;
    cout << r3;
    cout << "Inférieur " << (r3<r1) << endl;
    cout << "Inférieur " << (r1<r3) << endl;
    cout << "Supérieur ou égal " << (r3>=r1) << endl;
    cout << "Supérieur ou égal " << (r1>=r3) << endl;
    cout << "Supérieur ou égal " << (r1>=r1) << endl;
    cout << "Supérieur " << (r3>r1) << endl;
    cout << "Supérieur " << (r1>r3) << endl;
    cout << "Supérieur " << (r1>r1) << endl;
    cout << "Inférieur ou égal " << (r3<=r1) << endl;
    cout << "Inférieur ou égal " << (r1<=r3) << endl;
    cout << "Inférieur ou égal " << (r1<=r1) << endl;

    try {
        Rationnel rExeption (1,0);
    } catch ( runtime_error& e){
        cout << e.what() << endl;
    }

    return 0;
}
#include <iostream>
using namespace std;

class toto
{
private:
    int x;
public:
    int y;
    toto (int a=0, int b=0){
        x=a;
        y=b;
    }
    void test();
    int getX(){
        return x;
    }

};

void toto::test(){
    cout << "Fonction à l'extérieur" << endl;
}


int main(){
    cout << "Hello world" << endl;
    toto t;
    cout << t.getX() << t.y << endl;
    toto t2(1,1);
    cout << t2.getX() << t2.y << endl;
    toto t3(1);
    cout << t3.getX() << t3.y << endl;
    toto t4 = 2;
    cout << t4.getX() << t4.y << endl;
    t.test();
    return 0;
}



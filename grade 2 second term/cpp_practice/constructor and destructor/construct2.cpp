#include<iostream>
using namespace std;
class B
{
    int x;

public:
    B() { cout << "B construction" << endl; }
    B(int x) : x(x){};
};

class A{
    B b;

public:
    A(int x){cout<<"A construction"<<endl;b=B(x);}
};



int main(void)
{
    A a(1);
    return 0;
}
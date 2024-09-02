#include<iostream>
using namespace std;
class A
{
public:
    void f() { cout << "class A function" << endl; }
};
class B
{
public:
    void f() { cout << "class B function" << endl; }
    void g() {cout << "g func in B" << endl;}
};

class C: public A, public B{
public:
    void g(){cout << "g func in C" << endl;}
};
int main(void)
{
    C c;
    // c.f();   // error
    c.g();   // redefining
    c.A::f();
    c.B::f();
    return 0;
}

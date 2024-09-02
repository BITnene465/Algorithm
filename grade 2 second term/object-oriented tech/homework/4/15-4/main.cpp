#include<iostream>
using namespace std;
class A
{
    int i;

public:
    A(int ii) : i(ii) {}
    ~A() {}
    void f() const {cout << "A::f()" << endl;}
};

class B
{
    int i;

public:
    B(int ii) : i(ii) {}
    ~B() {}
    virtual void f() const {cout << "B::f()" << endl;}
};

class C : public B
{
    A a;

public:
    C(int ii) : B(ii), a(ii) {}
    ~C() {} // Calls ~A() and ~B()
    void f() const
    { // overriding
        a.f();
        B::f();
        cout << "C::f()" << endl;
    }
};

int main(void)
{
    // upcasting demo
    cout << "upcasting" << endl;
    B b1 = C(10);
    b1.f();
    
    // virtual call demo
    cout << "virtual call" << endl;
    B* pb1 = new C(10);
    pb1->f();

    return 0; 
}
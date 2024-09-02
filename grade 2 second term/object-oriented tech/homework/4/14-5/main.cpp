//: C14:Combined.cpp
// Inheritance & composition
#include<iostream>
using namespace  std;
class A
{
    int i;

public:
    A(int ii) : i(ii) { cout << "A::A() : " << ii << endl;}
    ~A() { cout << "A::~A()" << endl; }
    void f() const {}
};

class B
{
    int i;

public:
    B(int ii) : i(ii) { cout << "B::B() : " << ii << endl; }
    ~B() { cout << "B::~B()" << endl; }
    void f() const {}
};

class C : public B
{
    A a;

public:
    C(int ii) : B(ii), a(ii) { cout << "C::C() : " << ii << endl ;}
    ~C() { cout << "C::~C()" << endl; } // Calls ~A() and ~B()
    void f() const
    { // Redefinition
        a.f();
        B::f();
    }
};
// new code
class D : public B{
    C c;
public:
    D(int ii): B(ii), c(ii){cout << "D::D() : " << ii << endl;}
    ~D() { cout << "D::~D()" << endl; }
};
int main()
{
    D d(47);
    return 0;
} 

// 销毁时，先销毁数据成员，再销毁自身
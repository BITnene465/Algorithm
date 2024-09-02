#include <iostream>
using namespace std;
class Base
{
public:
    virtual void func() { cout << "Base::func()" << endl; }
    virtual void func(int) { cout << "Base::func(int)" << endl; }
    virtual void func(int, int) { cout << "Base::func(int, int)" << endl; }
};
class Derived : public Base
{
public:
    // remove overriding 
    // void func() { cout << "Derived::func()" << endl; }
};

int main(void)
{
    // use Derived class object
    Derived d;
    d.func();
    d.func(10);
    d.func(10, 10);

    return 0;
}
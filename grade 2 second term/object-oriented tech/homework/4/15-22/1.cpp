#include<iostream>
using namespace std;
class Base{
public:
    virtual void func() { cout << "Base::func()" << endl; }
    virtual void func(int) { cout << "Base::func(int)" << endl; }
    virtual void func(int, int) { cout << "Base::func(int, int)" << endl; }
};
class Derived: public Base{
public:
    // overriding & redefining -> name hiding
    void func(){cout << "Derived::func()" << endl;}
};

int main(void)
{
    // use Derived class object
    Derived d;
    d.func();
    d.Base::func();

    //! d.func(1);   
    //! d.func(1, 2);   error： 重定义后隐藏基类中所有的同名成员函数

    //  use upcasting
    Base* pb = new Derived;
    pb->func();
    pb->Base::func();
    pb->func(1);
    pb->func(1, 2);


    return 0;
}
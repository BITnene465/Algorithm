#include<iostream>
using namespace std;
class A{
public:
    A(){cout << "A::A()" << endl;}
    virtual ~A(){ cout << "A::~A()" << endl;}  
    // 此处不使用虚函数，那么main中将会无法删除B中A没有的部分内存，造成内存泄漏
};
class B: public A{
    char* buf;
public:
    B(int i){
        buf = new char[i];
        cout << "B::B(int)" << endl;
        }
    virtual ~B(){
        delete [] buf;
        cout << "B::~B()" << endl;
    }
};
int main()
{
    B b(15);
    A& a = b;
    delete &a;
}
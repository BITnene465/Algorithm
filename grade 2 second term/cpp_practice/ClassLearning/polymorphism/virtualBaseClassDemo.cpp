#include<iostream>
using namespace std;
class A0{
public:
    A0(int i){
        cout << "A0: " << i << endl;
    }
};
class A1
{
public:
    A1(int i)
    {
        cout << "A1: " << i << endl;
    }
};
class A{
public:
    A(int i){
        cout << "A: " << i << endl;
    }
};
class B: virtual public A{
public:
    B(int j, int i) : A(i)
    {
        cout << "B: " << j << endl;
    }
};
class C: virtual public A{
public:
    C(int j, int i) : A(i)
    {
        cout << "C: " << j << endl;
    }
};
class D: public B, public C{
    A0 a;
    A1 aa;
public:
    D(int i, int j, int k, int l, int m, int n): B(j, 0), C(k, 0), A(l), a(m), aa(n){
        cout << "D: " << i << endl;
    } 
};

int main(void)
{
    D d(1, 2, 3, 4, 5, 6);
    return 0;
}
#include<iostream>
using namespace std;
class X{
    int a;
public:
    X(int i=0): a(i){cout << "constructor X:" << a << endl;}
};
class Y: public X{
    int b;
    X x1, x2;
public:
    Y(int i, int j, int m, int n): b(i), x2(j), x1(m), X(n){cout << "constructor Y:" << b << endl;} 
};
int main(void)
{
    Y y(1, 2, 3, 4);
    return 0;
}
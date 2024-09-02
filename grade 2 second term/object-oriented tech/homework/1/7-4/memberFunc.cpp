#include<iostream>
using namespace std;
class A{
public:
    void printAll0(){
        cout << "There is no number." << endl;
    }
    void printAll1(int a)
    {
        cout << "one number: " << a << endl;
    }
    void printAll2(int a, int b)
    {
        cout << "two number: " << a << ", " << b << endl;
    }
    void printAll3(int a, int b, int c)
    {
        cout << "three number: " << a << ", " << b << ", " << c << endl;
    }
};
int main(void)
{
    A a;
    a.printAll0();
    a.printAll1(1);
    a.printAll2(1, 2);
    a.printAll3(1, 2, 3);
    return 0;
}
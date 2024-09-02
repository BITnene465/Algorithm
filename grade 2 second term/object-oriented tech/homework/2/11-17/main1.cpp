#include <iostream>
using namespace std;
class X
{
    double *ptr;

public:
    X(double val);
    X(const X &x); // copy constructor   不写编译器会自动加上一个默认的copy constructor
    ~X();
    void printValue();
};

X::X(double val)
{
    ptr = new double(val);
}
X::~X()
{
    printValue();
    *ptr = -1;
    delete ptr;
    ptr = nullptr;
}
void X::printValue()
{
    cout << "value: " << *ptr << endl;
}

void func(X x)
{
    cout << "test function." << endl;
    x.printValue();
}
int main(void)
{
    X x(10);
    func(x);
    return 0;
}
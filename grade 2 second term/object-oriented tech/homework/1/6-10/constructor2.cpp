#include <iostream>
using namespace std;
class A
{
    int data = 465;

public:
    int getdata();
    A(int data):data(data){};
};
int A::getdata() { return data; }
int main(void)
{
    A a(100);
    cout << a.getdata() << endl;
    return 0;
}

// explain
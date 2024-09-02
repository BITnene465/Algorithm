#include<iostream>
using namespace std;
class A{
    int data = 465;
public:
    int getdata();
};
int A::getdata(){return data;}
int main(void)
{
    A a;
    cout << a.getdata() << endl;
    return 0;
}
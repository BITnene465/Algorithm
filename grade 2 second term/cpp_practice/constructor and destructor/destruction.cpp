#include<iostream>
using namespace std;
class X{
    int i;
public:
    X(int i=0):i(i){
        cout << "X()" << this->i << endl;
    };
    ~X(){
        cout << "~X()" << i << endl;
    }
};
void f(){
    static X x1(47);
    static X x2;
}
int main(void)
{
    X x(10);
    f();
    return 0;
}

// 先析构栈上的内存，再析构静态内存
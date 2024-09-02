#include<iostream>
using namespace std;
int a = 1;
void f(){cout<<"全局函数"<<endl;};

class A{
    public:
    int a = -1;   // 实例变量
    void f();
};

void A::f(){
    a--;  // 操作类内变量 a
    ::a++;   // 操作全局变量 a
    cout<< "类内函数" << endl;
}

int main(void)
{
    A obj;
    f();  // 全局函数
    obj.f();  // 类内函数
    cout << obj.a << endl;  // 类内变量
    return 0;
}

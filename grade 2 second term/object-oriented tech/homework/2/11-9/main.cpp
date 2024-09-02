#include<iostream>
using namespace std;
class X{
public:
    void memfunc1() const{
        cout << "this is a const function" << endl;
    };
    void memfunc2(){
        cout << "this is a non-const function" << endl;
    };
};

void func1(X x){
    cout << "value" << endl;
    x.memfunc1();
    x.memfunc2();
};
void func2(X& x){
    cout << "reference" << endl;
    x.memfunc1();
    x.memfunc2();
};
void func3(const X& x){
    cout << "const reference" << endl;
    x.memfunc1();
    // x.memfunc2();   error: const对象无法调用 non-const 的成员函数
};

int main(void)
{
    X x;
    func1(x);
    func2(x);
    func3(x);
    return 0;
}
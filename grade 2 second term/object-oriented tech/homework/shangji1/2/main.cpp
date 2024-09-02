#include<iostream>
using namespace std;
int _factor(int n){
    if(n<=1)return 1;
    return n*_factor(n-1);
}
int main(void)
{
    int (*funcptr)(int) = _factor;
    int n =7;
    // 函数名调用
    cout << "7! = " << _factor(n) << endl;
    // 指针调用
    cout << "7! = " << funcptr(n) << endl;
    return 0;
}
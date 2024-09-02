#include<iostream>
using namespace std;
class Data{
public:
    int a, b, c;
    void Print(){
        cout << a << ' ' << b << ' ' << c << endl;
    }
};
int main(void)
{
    Data d;
    Data* dp = &d;    // 常规的对象指针
    
    int Data::*ptr = &Data::a;   
    // 这个指针并没有指定某一个特定的对象，可以理解为Data类中多了一个成员 ptr

    // 利用该指针调用数据成员
    d.Print();
    dp->*ptr = 10;
    d.Print();
    d.*ptr = 20;
    d.Print();
    return 0;
}
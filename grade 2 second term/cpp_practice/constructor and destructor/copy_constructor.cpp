#include<iostream>
using namespace std;
class Date{
    int y, m, d;
public:
    // constructor
    Date(int y, int m, int d): y(y), m(m), d(d){cout << "constructor is called" << endl;};
    Date() = default;
    // copy constructor
    Date(const Date& date){    // 必须使用该类的 const reference 作为参数
        y = date.y;
        m = date.m;
        d = date.d;
        cout << "copy constructor is called" << endl;
    }
    // destructor
    ~Date(){
        cout << "destructor is called" << endl;
    }
};

int main(void)
{
    Date d1(2024, 3, 21);
    Date d2 = d1;   // 调用 copy constructor
    Date d3;
    d3 = d1;    // 不会调用 copy constructor
    return 0;
}
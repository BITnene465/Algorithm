// 常成员函数不可改变任何数据成员（除了用mutable修饰的数据变量）
#include<iostream>
using namespace std;
class Date{
private:
    int year;
    int month;
    int day;
    mutable int isRun;
public:
    Date(int y, int m, int d):year(y), month(m), day(d){isRun=1;}
    int Year() const{return year;}
    int Month() const{return month;}
    int Day() const{return day;}       // 常成员函数不可改变数据成员
    
    void Change() const{isRun^=1;}      // 常成员函数可以改变 mutable 数据成员
};
int main(void)
{
    
}
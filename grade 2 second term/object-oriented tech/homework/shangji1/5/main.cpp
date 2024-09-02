#include<iostream>
#include "Circle.h"
using namespace std;
int main(void)
{
    const Circle c1(10);
    Circle c2(10);
    
    // c1.getArea();   error: 常对象只能调用常成员函数
    c1.printArea();
    c2.getArea();
    c2.printArea();

    return 0;
}
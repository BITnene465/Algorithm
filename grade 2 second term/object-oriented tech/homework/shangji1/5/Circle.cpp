#include<iostream>
#include "Circle.h"
const double Circle::Pi = 3.1415926;  // 初始化不可指定存储类型
double Circle::getArea() {
    return s = Pi*r*r;
}
void Circle::printArea() const{
    std::cout << "面积为" << s << std::endl;
}
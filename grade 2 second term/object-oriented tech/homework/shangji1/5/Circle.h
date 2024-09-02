#ifndef CIRCLE_H
#define CIRCLE_H
class Circle
{
private:
    const static double Pi;
    double r;
    double s;

public:
    double getArea();
    void printArea() const;
    Circle(double r): r(r){};
};
#endif
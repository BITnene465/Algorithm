#include<bits/stdc++.h>
using namespace std;
class Triangle{
private:
    double x, y, z;
public:
    Triangle(double x, double y, double z): x(x), y(y), z(z){};
    bool isTrig();
    double Area();
    friend double SumArea(Triangle&, Triangle&);
};
bool Triangle::isTrig(){
    if(x+y>z&&y+z>x&&z+x>y)return 1;
    return 0;
}
double Triangle::Area(){
    return sqrt((x+y-z)*(y+z-x)*(z+x-y)*(x+y+z))/4.0;
}
double SumArea(Triangle& a, Triangle& b){
    if(a.isTrig() && b.isTrig()){
        double sum = a.Area() + b.Area();
        cout<<"面积之和为: "<< sum << endl;
        return sum;
    }
    cout << "error" << endl;
    return -1;
}
int main(void)
{
    Triangle a(1, 2.1, 3), b(3, 4, 5), c(1, 2, 3);
    SumArea(a, b);
    SumArea(b, c);
    return 0;
}
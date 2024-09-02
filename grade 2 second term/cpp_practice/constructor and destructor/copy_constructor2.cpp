#include<iostream>
using namespace std;
class TPoint{
    double x, y;
public:
    double Xcoord(){
        return x;
    }
    double Ycoord(){
        return y;
    }
    TPoint(double x=0, double y=0){
        this->x = x;
        this->y = y;
        cout << "TPoint: " << x << " " << y << endl; 
    };
    TPoint(const TPoint& p){
        x = p.x;
        y = p.y;
        cout << "copy TPoint: " << x << ' ' << y << endl;
    }
    ~TPoint(){
        cout << "~TPoint: " << x << ' ' << y << endl;
    }
};

TPoint f(TPoint Q){
    double x, y;
    cout << "OK" << endl;
    x = Q.Xcoord() + 10;
    y = Q.Ycoord() + 10;
    TPoint R(x, y);
    return R;

    // 返回一个对象，编译器会默认进行返回值优化
    // 使用 -fno-elide-constructors  关闭返回值优化， 会发现多出一个临时返回对象的拷贝
}

int main(void)
{
    TPoint M(10, 10), P(0, 100);
    TPoint N = M;
    
    P = f(N);   // 此处只是赋值，并不会调用 copy constructor

    return 0;
}
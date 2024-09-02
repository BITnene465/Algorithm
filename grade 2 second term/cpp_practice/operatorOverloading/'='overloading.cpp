#include<iostream>
using namespace std;
class Position{
    double X, Y;
public:
    double getX(){return X;}
    double getY(){return Y;}
    Position(double X=0.0, double Y=0.0): X(X), Y(Y){}
    // ¡®=¡¯ overloading
    Position& operator=(const Position& other){
        X = other.X;
        Y = other.Y;
        std::cout << "= overloading is called" << std::endl; 
        return *this;
    }

    // copy constructor
    Position(const Position& other){
        X = other.X;
        Y = other.Y;
        std::cout << "copy constructor is called" << std::endl;
    }
    
};

int main(void)
{
    Position l1(10, 10);
    Position l2(l1);   // copy constructor
    Position l3 = l1;  // copy constructor
    Position l4;  l4 = l1;   // '=' overloading
    
    return 0;
}
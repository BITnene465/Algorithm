#include<bits/stdc++.h>
using namespace std;
class Fraction{
    int numerator, denominator;
    int gcd(int x, int y){
        int t;
        x = (x>0)?x:-x;
        y = (y>0)?y:-y;
        if(x<y)swap(x, y);
        while(y){
            t = y;
            y = x%y;
            x = t;
        }
        return x;
    }
    void cvt(){
        int factor = gcd(numerator, denominator);
        numerator = numerator / factor;
        denominator = denominator / factor;
        if(denominator>=0) return;
        denominator = -denominator;
        numerator = -numerator;
    }
public:
    Fraction(int x=1, int y=1): numerator(x), denominator(y){
        cvt();
    }
    Fraction operator+(const Fraction &other)
    {
        return Fraction(numerator * other.denominator + denominator * other.numerator, denominator * other.denominator);
    }
    operator double(){
        return (double)numerator / denominator;
    }
    friend ostream& operator<<(ostream& o, const Fraction& f){
        o << f.numerator << " / " << f.denominator;
        return o;
    }
};

int main(void)
{
    Fraction R1(1, 2), R2(2, 3), R3;
    R3 = R1 + R2;
    double number = R3;
    cout << R3 << endl;
    cout << number << endl;
    return 0; 
}
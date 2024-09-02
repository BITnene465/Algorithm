#include<iostream>
using namespace std;
class Number{
    double data;
public:
    Number(double x): data(x){}
    // + - * / overloading
    const Number operator+(const Number &other)
    {
        return Number(data + other.data);
    }
    const Number operator-(const Number &other)
    {
        return Number(data - other.data);
    }
    const Number operator-()
    {
        return Number(-data);
    }
    const Number operator*(const Number &other)
    {
        return Number(data * other.data);
    }
    const Number operator/(const Number &other)
    {
        return Number(data / other.data);
    }
    // auto type conversion
    operator double(){
        return data;
    }
    // 
    friend ostream& operator<<(ostream& ost, const Number& x){
        ost << x.data << ' ';
        return ost;
    }
};

int main(void)
{
    Number a(1.0), b(2.8);
    Number c1 = 1 + b;
    Number c2 = a + b;
    cout << c1 << '\n' << c2 << '\n';
    return 0;
}
// complex number class Demo
#include<iostream>
#include<cmath>
using namespace std;
class Complex{
    double real, imag;
public:
    double Real()const{return real;}
    double Imag()const{return imag;}
    double Modulus()const{return std::sqrt(real*real + imag*imag);}
    Complex Conjugate()const{return Complex(real, -imag);} 
    Complex(double r=0, double i=0): real(r), imag(i){}
    // 该版本执行 1.0 + c 时会有问题，可以使用友元函数解决 (此类二元运算的重载建议使用友元函数进行重载)
    Complex operator+(const Complex &other) const  // 加法
    {
        return Complex(real + other.real, imag + other.imag);
    }
    Complex operator-(const Complex &other) const  // 减法
    {
        return Complex(real - other.real, imag - other.imag);
    }
    Complex operator*(const Complex &other) const  // 乘法
    {
        return Complex(real*other.real-imag*other.imag, real*other.imag+imag*other.real);
    }
    Complex operator/(const Complex &other) const  // 除法
    {
        if(other.real == 0 && other.imag == 0){
            throw std::invalid_argument("divided by 0");
        }
        Complex res = (*this)*other.Conjugate();
        double val = other.Modulus();
        res.real /= val;
        res.imag /= val;
        return res;
    }
    Complex operator-() const // 相反数
    {
        return Complex(-real, -imag);
    }
    Complex& operator++() // 前自增  ++c
    {
        ++real;
        return *this;
    }
    Complex operator++(int) // 后自增 c++
    {
        Complex res(*this);
        ++real;
        return res;
    }
    Complex& operator+=(const Complex& other){
        real+=other.real;
        imag+=other.imag;
        return *this;
    }

    // 类型转换运算符重载
    operator int(){return int(real);}
    operator double(){return double(real);}

    void Print(){
        std::cout << "(" << real << "," << imag << ")" << std::endl;
    }
};

int main(void)
{
    Complex a(1, 1);
    Complex b(10, -9);
    a.Print();
    b.Print();
    (a+b).Print();
    (a-b).Print();
    (a*b).Print();
    (a/b).Print();

    Complex c1(1.0, 2.9);
    Complex c2(c1);
    (++c1).Print();
    (c2++).Print();
    c1.Print();
    c2.Print();

    Complex c3(1.0, 2.8), c4(1.9, 2.0);
    c3.Print();
    c4.Print();
    c3+=c4;
    c3.Print();
    return 0;

}
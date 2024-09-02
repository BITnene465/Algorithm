#include<bits/stdc++.h>
using namespace std;
class CQuadEq{
private:
    double a, b, c;
    double d;
    double x1_real, x1_imag, x2_real, x2_imag;
    int flag;

public:
    void FindRoot();
    void Show();
    CQuadEq() = default;
    CQuadEq(double a, double b, double c): a(a), b(b), c(c){ d = b*b-4*a*c; flag=0;}
};
void CQuadEq::FindRoot(){
    if(a==0){
        if(b==0){
            flag = 2;
            return;
        }
        flag=1;
        x1_real = -c/b;
        return;
    }
    if(d>=0){
        x1_real = (b-sqrt(d))/(2*a);
        x2_real = (b+sqrt(d))/(2*a);
        x1_imag = x2_imag = 0;
        return;
    }
    x1_real = x2_real = b/(2*a);
    x1_imag = -sqrt(-d) / (2 * a);
    x2_imag = sqrt(-d) / (2 * a);
}
void CQuadEq::Show(){
    if(flag)
    {
        cout<< "方程的根为: x = " << x1_real << endl;
        return;
    }
    if (d > 0)
    {
        cout << "方程的根为: x1 = " << x1_real << " x2 = " << x2_real << endl;
        return;
    }
    if (d == 0)
    {
        cout << "方程的根为: x1=x2=" << x1_real << endl;
        return;
    }
    cout << "方程的根为: x1 = " << x1_real << x1_imag << "i" << " x2 = " << x2_real << "+" << x2_imag << "i" << endl;
}
int main(void)
{
    int a=1, b=3, c=2;
    CQuadEq eq1(a, b, c);
    CQuadEq eq2(1, 2, 3);
    cout<< "a=" << a << " b=" << b << " c=" << c <<endl;
    eq1.FindRoot();
    eq1.Show();
    cout << "a=" << 1 << " b=" << 2 << " c=" << 3 << endl;
    eq2.FindRoot();
    eq2.Show();
    return 0;
}
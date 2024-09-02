#include<iostream>
using namespace std;
void swap1(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}
void swap2(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int main()
{
    int x=1, y=2;
    cout << "x=" << x << ","
         << "y=" << y << endl;
    cout<<"进行引用交换"<<endl;
    swap1(x, y);
    cout << "x=" << x << ","
         << "y=" << y << endl;
    cout<<"进行指针交换"<<endl;
    swap2(&x, &y);
    cout << "x=" << x << ","
         << "y=" << y << endl;
    return 0;
}
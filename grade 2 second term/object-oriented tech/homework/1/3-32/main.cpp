#include<bits/stdc++.h>
using namespace std;
int double2int(double x);
int main(void)
{
    int (*funcptr)(double) = double2int;
    double x = 10.1;
    cout<< funcptr(x) << endl;
    return 0; 
}
int double2int(double x){
    return (int)x;
}
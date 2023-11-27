#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
const double a = 1./3.0;
int main(void)
{
    int T;
    scanf("%d",&T);
    double b , g;
    for(int i=0;i<T;i++)
    {
        double cost = 0.;
        double k;
        scanf("%lf %lf",&b,&g);
        k = b>0?pow(b,a):-pow(-b,a);
        while(fabs(b-g)>1+fabs(k-g))
        {
           
            cost = cost + 1;
            b = k;
            k = b>0?pow(b,a):-pow(-b,a);
        }
        cost = cost + fabs(b-g);
        printf("%.9f\n",cost);
    }
    return 0;
}
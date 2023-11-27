#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const double pi = acos(-1);
int main()
{
    int n,r;
    int i,j;
    scanf("%d %d",&n,&r);
    scanf("%d %d",&i,&j);
    int k = abs(i-j);
    if(k>n/2)   k = n-k;

    double l = 2*k*r*sin(pi/n);
    printf("%.6lf\n",l);
    return 0; 
}
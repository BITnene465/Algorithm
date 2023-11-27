/*
有n个物品的重量和价值分别是wi和vi，从中选出k个物品使得单位重量价值最大。
*/
#include<bits/stdc++.h>
using namespace std;
int n,k;
int w[1001],v[1001];
double t[1001];
bool cmp(double x,double y)
{
    return x>y;
}
bool check(double mid)
{
    double sum = 0.;
    for(int i=1;i<=n;i++)
        t[i] = v[i] - w[i]*mid;
    sort(t+1,t+n+1,cmp);   // 降序排列
    for(int i=1;i<=k;i++)
        sum+=t[i];
    if(sum<0)   return true;
    else        return false;
}
int main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d %d",w+i,v+i);
    double r,l;
    l = 0, r= 100;
    for(int i=1;i<=1000;i++)
    {
        double mid = (r+l)/2;
        if(check(mid))  r=mid;
        else    l=mid;
    }
    double mid = (r+l)/2.0;
    printf("%d-最大平均值为：%.8lf\n",k,mid);
    return 0;
}
// 经典第k大 , 可转化为有k-1个值比目标值val大 ,二分搜索-> 看有多少值比c大 ,单调性-> 若有大于k-1个比值比c大,那么 c<val , 反之同理 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,k;
double a[50005],b[50005],c[50005],d[50005];
double t2[50005];
bool check(double cc)
{
    for(ll i=1;i<m;i++)
        t2[i] = c[i] - cc*d[i]/(1-cc);
    sort(t2+1,t2+1+m);   // 升序排列
    ll cnt = 0;
    for(ll i=1;i<=n;i++)
    {
        double temp = -(a[i] - cc*b[i]/(1-cc));
        cnt += t2+m+1 - upper_bound(t2+1,t2+m+1,temp);   // 二分查找函数
    }
    if(cnt>=k)    
    {printf("check(%.5lf) OK\n",cc);
    return true;}   // 说明 cc < val
    else return false;
}
int main(void)
{
    cin>>n>>m>>k;
    for(ll i=1;i<=n;i++)
        scanf("%lf %lf",a+i,b+i);
    for(ll i=1;i<=m;i++)
        scanf("%lf %lf",c+i,d+i);
    double r,l,mid;
    l = 0.,r = 1.;
    for(ll i=1;i<=100;i++)
    {
        mid = (l+r)/2.0;
        if(check(mid))  l = mid;
        else    r = mid;
    }
    printf("%.15lf\n",100*l);
    return 0;
}
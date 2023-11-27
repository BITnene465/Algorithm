// 答案具有单调性，可以二分答案 //
// 每次判断使用单调队列： 判断长度在 [S,T] 的连续子序列的和的最大值（最小值） //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
const double eps = 1e-7;
ll n,s,t;
double a[maxn],sum[maxn],l,r,mid;
bool check(double c)
{
    deque<ll> q;
    sum[0]=0.0;
    for(ll i=1;i<=n;++i)sum[i]=sum[i-1]+a[i]-c;
    for(ll cur=0;cur<=n-s;++cur)
    {
        while(!q.empty()&&q.front()+t-s<cur)q.pop_front();
        while(!q.empty()&&sum[q.back()]-sum[cur]>eps)q.pop_back();
        q.push_back(cur);
        if(sum[cur+s]-sum[q.front()]>eps){return 1;}
    }
    return 0;
}
int main(void)
{
    scanf("%lld",&n);
    scanf("%lld %lld",&s,&t);
    for(ll i=1;i<=n;++i)scanf("%lf",a+i);
    l=-10000.0,r=10000.0;
    while(r-l>eps)
    {
        mid=(r+l)/2.0;
        if(check(mid))l=mid;
        else r=mid;
    }
    printf("%.3lf\n",l);
    return 0;
}
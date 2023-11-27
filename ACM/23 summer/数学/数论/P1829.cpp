// 一种最小公倍数求和 //
// AC //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=20101009;
const int maxn=1e7+5;
ll n,m,ans,mu[maxn],g[maxn];
void pre()
{
    // 先预处理g
    g[0]=0;
    for(ll i=1;i<=m;++i)   
        g[i]=(g[i-1]+i)%mod;
    return;
}
ll sum(ll n,ll m)    // sum(n,m)
{
    ll res=0;
    for(ll d=1;d<=n;++d)
        if(mu[d])res=(res+(mu[d]*d*d%mod+mod)%mod*(g[n/d]*g[m/d]%mod))%mod;
    return res;
}
void solve()
{
    // 解决ans , 二维数论分块
    ans=0;
    ll l=1,r;
    while(l<=n)  // n<=m
    {
        r=min(n/(n/l),m/(m/l));  // 计算当前区间的右端点
        ans=(ans+(l+r)*(r-l+1)/2%mod*sum(n/l,m/l)%mod)%mod;
        l=r+1;
    }
    return;
}
// Mobius函数线性筛 
bool isnp[maxn];int pri[maxn],cnt;
void linear(int n)
{
    mu[1]=1;cnt=0;
    for(int i=2;i<=n;++i)
    {
        if(!isnp[i]){pri[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else    mu[i*pri[j]]=-mu[i];
        }
    }
}
int main(void)
{
    cin>>n>>m;
    if(n>m)swap(n,m);   // 保证n<=m
    linear(n);
    pre();
    solve();
    cout<<ans<<endl;
}

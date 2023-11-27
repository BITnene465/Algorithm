// 莫反2 //
//  复杂度大概O(n) TLE   //
#include<bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
const ll mod=(ll)1<<64;
const ll maxn=5e6+5;
ll n,m,cnt,pri[maxn],mu[maxn];
ll sum[maxn];
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=10*x+ch-'0';ch=getchar();}
    return f*x;
}
bool vis[maxn];
ll qpow(ll x,ll power,ll mod)    // 求逆元函数,费马小定理+快速幂
{
    x=x%mod;
    ll ans = 1;
    for (; power; power >>= 1, x=x*x%mod)
    	if(power & 1) ans=ans*x%mod;
    return ans;
}
void linear(ll n)
{
    mu[1]=1;cnt=0;
    sum[0]=0;sum[1]=1;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i])pri[++cnt]=i,mu[i]=-1;
        for(ll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j])mu[i*pri[j]]=-mu[i];
            else
            {
                mu[i*pri[j]]=0;
                break;
            }
        }
        sum[i]=sum[i-1]+mu[i];
    }
}
map<ll,ll> mp;
ll du_mu(ll n)
{
    if(n<maxn)return sum[n];
    if(mp.count(n))return mp[n];
    // 数论分块
    ll res=1;
    for(ll l=2,r;l<=n;l=r+1){r=n/(n/l);res-=(r-l+1)*du_mu(n/l);}
    return mp[n]=res; // 记忆化搜索 
}
ll func(ll m)
{
    ll res=0;
    for(ll l=1,r;l<=m;l=r+1)
    {
        r=m/(m/l);
        res+=(du_mu(r)-du_mu(l-1))*qpow(m/l,n,mod);
    }
    return res%mod;
}
int main(void)
{
    n=read();m=read();
    linear(maxn-1);
    ll ans=0;
    for(ll l=1,r;l<=m;l=r+1)
    {
        r=m/(m/l);
        ans+=(r+l)*(r-l+1)/2*func(m/l)%mod;
    }
    ans=ans%mod;
    printf("%lld\n",(unsigned long long)ans);
    return 0;
}
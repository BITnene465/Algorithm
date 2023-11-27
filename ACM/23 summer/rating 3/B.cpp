#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e6+5;
const ll mod=1e9+7;
ll D[maxn],fac[maxn],n,m;
ll qpow(ll x,ll power,ll mod)    // 求逆元函数,费马小定理+快速幂
{
    x=x%mod;
    ll ans = 1;
    for (; power; power >>= 1, x=x*x%mod)
    	if(power & 1) ans=ans*x%mod;
    return ans;
}
void pre(ll n)
{
    D[0]=1,D[1]=0;
    fac[0]=fac[1]=1;
    for(ll i=2;i<=n;i++)
    {
        D[i]=(i-1)*(D[i-1]+D[i-2])%mod;
        fac[i]=fac[i-1]*i%mod;
    }
    return;
}
ll C(ll n,ll m)
{
    return (n<m)?0:fac[n]*qpow(fac[n-m],mod-2,mod)%mod*qpow(fac[m],mod-2,mod)%mod;
}
int main(void)
{
    int T;
    ll num=1e6+1;
    pre(num);
    scanf("%d",&T);
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",C(n,m)*D[n-m]%mod);
    }
    return 0;
}


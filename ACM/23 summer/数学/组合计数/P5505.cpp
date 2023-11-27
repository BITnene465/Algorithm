// 容斥原理 数学题 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll n,m;
ll a[1005],fac[2005];
void pre()
{
    fac[0]=1;
    for(ll i=1;i<=2004;i++)
        fac[i]=fac[i-1]*i%mod;
    return;
}
ll fpm(ll x,ll power,ll mod)    // 求逆元函数,费马小定理+快速幂
{
    x=x%mod;
    ll ans = 1;
    for (; power; power >>= 1, x=x*x%mod)
    	if(power & 1) ans=ans*x%mod;
    return ans;
}
ll C(ll n,ll m)
{
    return n<m?0:fac[n]*fpm(fac[m],mod-2,mod)%mod*fpm(fac[n-m],mod-2,mod)%mod;
}
int main(void)
{
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=m;i++)
        scanf("%lld",a+i);
    pre();
    ll ans=0;
    for(ll i=0;i<=n-1;i++)
    {
        ll temp;
        if(i%2==0)  temp=C(n,i);
        else        temp=-C(n,i);
        for(ll j=1;j<=m;j++)
            temp=temp*C(a[j]+n-i-1,a[j])%mod;
        ans=(ans+temp+mod)%mod;    // 要加mod防止负数
    }
    cout<<ans<<endl;
    return 0;
}

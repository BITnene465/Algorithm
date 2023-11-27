#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=11;
// ½ÓÊÜ x>=0 //
ll euler_phi(ll x)
{
    if(x==0)return 0;
    ll ans=x;
    for(ll i=2;i<=sqrt(x+0.5);i++)
    {
        if(x%i==0)
        {
            while(x%i==0)   x=x/i;
            ans=ans/i*(i-1);
        }
    }
    if(x>1){ans=ans/x*(x-1);}
    return ans;
}
ll qpow(ll x,ll power,ll mod)
{
    ll ans=1;
    x=x%mod;
    for(;power;power=power>>1,x=x*x%mod)
        if(power&1) ans=ans*x%mod;
    return ans;
}
// x \equive b_i mod a_i //
ll n,a[maxn],b[maxn];
ll CRT(ll* a, ll* b,ll n)
{
    ll A=1,AA[maxn],inv[maxn];
    for(ll i=1;i<=n;i++)
        A*=a[i];
    for(ll i=1;i<=n;i++)
    {
        AA[i]=A/a[i];
        inv[i]=qpow(AA[i],euler_phi(a[i])-1,a[i]);
    }
    ll ans=0;
    for(ll i=1;i<=n;i++)
        ans=(ans+b[i]*AA[i]*inv[i])%A;
    return ans;
}
int main(void)
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld %lld",a+i,b+i);
    ll ans=CRT(a,b,n);
    printf("%lld\n",ans);
    return 0;
}
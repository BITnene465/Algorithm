#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x,y,k,phi;
ll qpow(ll x,ll power,ll mod)   
{
    x=x%mod;
    ll ans = 1;
    for (; power; power >>= 1, x=x*x%mod)
    	if(power & 1) ans=ans*x%mod;
    return ans;
}
ll gcd(ll x,ll y)
{
    ll t;
    if(x<y)swap(x,y);
    while(y)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
ll euler_phi(ll x)
{
    ll ans=x;
    for(ll i=2;i<=sqrt(x+0.5);i++)
    {
        if(x%i==0)
        {
            while(x%i==0)   x/=i;
            ans=ans/i*(i-1);
        }
    }
    if(x!=1)    ans=ans/x*(x-1);
    return ans;
}
ll dig(ll i)
{
    i=i%phi+phi;  // ??i-1???
    return 10*((qpow(10,i-1,y)*x)%y)/y;
}
int main(void)
{
    cin>>x>>y>>k;
    ll g=gcd(x,y);
    x=x/g;y=y/g;
    x=x%y;
    phi=euler_phi(y);
    
    printf("%d%d%d\n",dig(k),dig(k+1),dig(k+2));
    return 0;
}
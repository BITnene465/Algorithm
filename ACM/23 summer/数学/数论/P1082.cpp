// 解法： 欧拉函数 + 快速幂 //
// 本题当然也可以使用拓展欧几里得来解决 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a,b;
ll qpow(ll x,ll power,ll mod)
{
    x=x%mod;
    ll ans = 1;
    for (; power; power >>= 1, x=x*x%mod)
    	if(power & 1) ans=ans*x%mod;
    return ans;
}
ll euler_phi(ll x)
{
    ll ans=x;
    for(ll i=2;i<=sqrt(x);i++)
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
int main(void)
{
    cin>>a>>b;
    printf("%lld\n",qpow(a,euler_phi(b)-1,b));
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll maxn = 2e5+10;
ll n, m;
ll fac[maxn];
void pre() // 预处理阶乘
{
    fac[0] = 1; // 一定要从0开始，血的教训
    for (ll i = 1; i <= maxn-1; i++)
        fac[i] = fac[i - 1] * i % mod;
}
ll qpow(ll x, ll power, ll mod)
{
    x = x % mod;
    ll ans = 1;
    for (; power; power >>= 1, x = x * x % mod)
        if (power & 1)
            ans = ans * x % mod;
    return ans;
}
ll solve(ll n, ll m)
{
    pre();
    ll ans = fac[2*n]*fac[n-m]%mod;
    ans = ans*qpow(fac[m], mod-2, mod)%mod;
    ans = ans*qpow(2, mod-1-m, mod)%mod;
    return ans;
}
int main(void)
{
    scanf("%lld %lld",&n,&m);
    printf("%lld\n", solve(n, m));
    return 0;
}
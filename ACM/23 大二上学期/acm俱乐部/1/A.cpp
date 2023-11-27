#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
ll n;
ll a[505], b[505], cnt_a, cnt_b;
ll qpow(ll x, ll power, ll mod) // 求逆元函数,费马小定理+快速幂
{
    x = x % mod;
    ll ans = 1;
    for (; power; power >>= 1, x = x * x % mod)
        if (power & 1)
            ans = ans * x % mod;
    return ans;
}
int main(void)
{
    scanf("%lld", &n);
    for(int i=1;i<=n;++i)
    {
        ll x,f;
        scanf("%lld %lld", &f, &x);
        if(f==1)a[++cnt_a] = x;
        else b[++cnt_b] = x;
    }
    ll sum1=0, sum2=0;
    for(int i=1;i<=cnt_a;++i)sum1+=a[i];
    for(int i=1;i<=cnt_b;++i)sum2+=b[i];

    if(cnt_a==0){printf("-1\n");return 0;}
    printf("%lld\n", (sum1+sum2)*qpow(cnt_a, mod-2, mod)%mod);
    return 0;
}
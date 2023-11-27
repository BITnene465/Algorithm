// Lucas 定理 //
// 模板题 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+4;
ll n,m,T,p;
// 阶乘 factory //
ll fac[maxn];
void pre()   // 预处理阶乘
{
    fac[0]=1;   // 一定要从0开始，血的教训
    for(ll i=1;i<=p;i++)    fac[i]=fac[i-1]*i%p;   // p-1之后都是0
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
ll C(ll n,ll m){return n<m?0:fac[n]*fpm(fac[m],p-2,p)%p*fpm(fac[n-m],p-2,p)%p;}  // n个物品取m个
ll Lucas(ll n,ll m,ll p){return !m?1:C(n%p,m%p)*Lucas(n/p,m/p,p)%p;}
int main(void)
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld %lld %lld",&n,&m,&p);
        pre();
        printf("%lld\n",Lucas(n+m,n,p));
    }
    return 0;
}
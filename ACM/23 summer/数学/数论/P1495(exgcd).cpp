#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=11;
void exgcd(ll a, ll b, ll& x, ll& y) {
  if (b == 0) {
    x = 1, y = 0;
    return;
  }
  exgcd(b, a % b, y, x);
  y -= a / b * x;
}
// x \equive b_i mod a_i //
ll n,a[maxn],b[maxn];
ll CRT(ll* a, ll* b,ll n)
{
    ll A=1,AA,inv,ans=0;
    for(ll i=1;i<=n;i++)
        A*=a[i];
    for(ll i=1;i<=n;i++)
    {
        AA=A/a[i];
        ll x,y;
        exgcd(AA,a[i],x,y);
        inv=x;
        ans=(ans+b[i]*AA*inv%A)%A;
    }   
    return (ans+A)%A;    // 拓展欧几里得可能得到负数
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
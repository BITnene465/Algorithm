// 本题有多种方法，可以使用前缀和，也可以直接dp //
// dp[i]表示以第i个数结尾的，最大子段和 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e5+5;
ll n,a[maxn],dp[maxn];
int main(void)
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;++i)scanf("%lld",a+i);
    dp[1]=a[1];
    for(ll i=2;i<=n;++i)dp[i]=max(a[i],a[i]+dp[i-1]);
    ll ans=-0x3f3f3f3f3f3f3f3f;
    for(ll i=1;i<=n;++i)ans=max(ans,dp[i]);
    printf("%lld\n",ans);
    return 0;
}
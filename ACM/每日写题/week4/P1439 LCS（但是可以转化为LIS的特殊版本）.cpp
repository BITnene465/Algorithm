#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
map<ll,ll> m;
ll n,len,dp[maxn],a[maxn],c[maxn];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    ll tmp;
    for(ll i=1;i<=n;++i)cin>>tmp,m[tmp]=i;
    for(ll i=1;i<=n;++i)cin>>a[i],a[i]=m[a[i]];
    // DP
    dp[1]=1,len=1,c[1]=a[1];
    for(ll i=2;i<=n;++i)
    {
        if(a[i]>=c[len])                               // 如果 a[i] >= c[len] 直接把 a[i] 补在 c数组后面
        {
            c[++len]=a[i];
            dp[i]=len;
        }
        else
        {
            ll k = upper_bound(c+1,c+len+1,a[i])-c;    // 否则，找到第一个大于 a[i]的c[k] ，更新 len = k , c[k]=a[i]
            c[k] = a[i];
            dp[i]=k;
        }
    }
    // print
    ll ans=0;
    for(ll i=1;i<=n;++i)ans=max(ans,dp[i]);
    cout<<ans<<'\n';
    return 0;
}
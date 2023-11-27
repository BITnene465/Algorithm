#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
// a为原数组，dp[i]表示以i结尾的最长不减子序列的长
// c数组记录当前的最长子序列（不记录idx而记录值是为了方便使用upper_bound函数，len为c数组长度; c[i]表示长度为i的LIS的最小末尾元素
// 时间复杂度 O(nlogn)
// 二分 + 贪心
// 如果还想要记录一个最长不下降子序列，可以使用pre数组记录转移的索引
ll n,len,dp[maxn],a[maxn],c[maxn];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>a[i];
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
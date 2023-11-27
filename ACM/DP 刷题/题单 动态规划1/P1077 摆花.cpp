// DP 类背包 dp[i][j]表示考虑前i种花，共摆j盆的方方法数 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int mod=1e6+7;
int dp[maxn],n,m,a[maxn];    // 滚动数组省略第一维
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    // DP
    dp[0]=1;
    for(int i=1;i<=n;++i)
        for(int j=m;j>=0;--j)
            for(int k=1;k<=min(a[i],j);++k)dp[j]=(dp[j]+dp[j-k])%mod;
    cout<<dp[m]<<endl;
    return 0;
}
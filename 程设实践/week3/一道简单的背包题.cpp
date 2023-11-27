// 计数dp，即找 \sum p_i mod V == 0 的方案个数 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=2005;
const int maxV=2005;
const int mod=(int)1e7;
int n,V,p[maxn],dp[maxV][maxn];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>V;
    for(int i=1;i<=n;++i)cin>>p[i];
    dp[0][0]=1;
    for(int j=1;j<=n;++j)
    {
        for(int i=0;i<=V;++i)
        {
            int oldi;
            oldi=(i-p[j]%V+V)%V;
            dp[i][j]=(dp[i][j-1]+dp[oldi][j-1])%mod;
        }
    }
    // for(int j=0;j<=n;++j){for(int i=0;i<=V-1;++i)cout<<dp[i][j]<<' ';cout<<endl;}
    cout<<dp[V][n]<<endl;
    // cout<<dp[0][n]<<endl;
    return 0;
}
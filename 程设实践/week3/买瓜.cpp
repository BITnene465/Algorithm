// 二维费用的背包问题 ，但是数据比较小可以直接暴力dp //
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int maxW=505;
const int maxV=505;
int n,T,dp[maxW][maxV];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>T;
    memset(dp,-1,sizeof(dp));
    dp[0][0]=0;
    // DP   
    for(int k=1;k<=n;++k)
    {
        int w,v,g;
        cin>>w>>v>>g;
        for(int i=500;i>=0;--i)
        {
            for(int j=500;j>=0;--j)
            {
                if(dp[i][j]>=0&&i+w<=500) dp[i+w][min(500,j+v)]=max(dp[i+w][min(500,j+v)],dp[i][j]+g);
            }
        }
    }
    // query
    while(T--)
    {
        int a,b;
        cin>>a>>b;
        int ma=0;
        for(int j=0;j<=a;++j)for(int i=b;i<=500;++i)if(dp[j][i]>ma)ma=dp[j][i];
        if(ma)cout<<ma<<endl;
        else cout<<"-1"<<'\n';
    }
    return 0;
}
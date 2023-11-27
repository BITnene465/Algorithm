
//  转移方程 ： dp[i][j] = dp[i-1][j-w[i][k]] + v[i][k]  其中, 1<=k<=s
//  本质仍然是背包问题
#include<bits/stdc++.h>
using namespace std;
int s,n,m;  // s个玩家，n座城堡，m个士兵
int sod[102][102];  // s[i][j] 为第j个玩家在第i座城堡的驻军
int dp[101][200005];   // dp[i][j] 表示前i座城堡，总兵力j能拿到的最高分数
int w[101][101],v[101][101];   // 分别是重量 & 价值
int len[101];   // 对应第 i 个城堡有多少种拿分策略
int main(void)
{
    cin>>s>>n>>m;
    for(int i=1;i<=s;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&sod[j][i]);
    for(int i=1;i<=n;i++)
        sort(sod[i]+1,sod[i]+1+s);
    for(int i=1;i<=n;i++)
    {
        int k = 0;
        sod[i][s+1] = INT_MAX;   // 哨兵
        for(int j=1;j<=s;j++)
        {
            if(sod[i][j+1]!=sod[i][j])
            {
                w[i][++k] = 2*sod[i][j]+1;
                v[i][k] = i*j;
            }
        }
        len[i] = k;
    }
    /*
    // debug
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=len[i];j++)
        {
            printf("w[%d][%d]=%d v[%d][%d]=%d ",i,j,w[i][j],i,j,v[i][j]);
        }
        printf("\n");
    }
    */
    // 暴力DP
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j] = dp[i-1][j];   // 初始化
            for(int k=1;k<=len[i];k++)
            {
                if(j>=w[i][k])
                {
                    dp[i][j] = max(dp[i][j],dp[i-1][j-w[i][k]]+v[i][k]);
                }
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
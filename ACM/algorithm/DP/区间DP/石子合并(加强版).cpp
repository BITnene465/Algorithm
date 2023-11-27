// 环形石子合并 ， 求最大和最小花费 //
// 看作长为2*n的链即可 //
#include<bits/stdc++.h>
using namespace std;
int stone[250];
int n;
int dp[250][250];  // 记录最小花费
int dp2[250][250]; // 记录最大花费
int ans1, ans2;
int sum[250];  // 用来记录前缀和
int dfs(int i,int j)
{
    if(i==j)
        return 0;   // 最小区间
    else if(dp[i][j]>0)
        return dp[i][j]; // 记忆，已经计算过了
    else   
    {
        int Min = INT_MAX;
        for(int k=i;k<=j-1;k++)
        {
            dp[i][k] = dfs(i,k);
            dp[k+1][j] = dfs(k+1,j);
            if(Min>dp[i][k]+dp[k+1][j]) Min = dp[i][k]+dp[k+1][j];
        }
        return dp[i][j] = Min + sum[j]-sum[i-1];
    } 
}
int dfs2(int i,int j)
{
    if(i==j)    return 0;
    else if(dp2[i][j]>0) return dp2[i][j];
    else
    {
        int Max = 0;
        for(int k=i;k<=j-1;k++)
        {
            dp2[i][k] = dfs2(i,k);
            dp2[k+1][j] = dfs2(k+1,j);
            if(Max<dp2[i][k]+dp2[k+1][j]) Max = dp2[i][k]+dp2[k+1][j];
        }
        return dp2[i][j] = Max + sum[j] - sum[i-1];
    }
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",stone+i);
        stone[n+i] = stone[i];
    }
    // 计算前缀和
    sum[0] = 0;
    for(int i=1;i<=2*n;i++)
        sum[i] = sum[i-1]+stone[i];
    // end
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    dfs(1,2*n);
    dfs2(1,2*n);
    ans1 = INT_MAX;
    ans2 = 0;
    for(int i=1;i<=n;i++)
    {
        ans1 = min(ans1,dp[i][n-1+i]);
        ans2 = max(ans2,dp2[i][n-1+i]);
    }
    cout<<ans1<<endl<<ans2<<endl;
    return 0;
}
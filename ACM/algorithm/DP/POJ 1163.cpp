#include<bits/stdc++.h>
using namespace std;
int a[106][106];   // 序号从1开始
int n;  // 层数
int dp[106][106];
// dp全部初始化为-1 ！！
int dfs(int i,int j)     // 探索从点(i,j)到底层的最大路径和
{
    if(i==n)
        return a[i][j];    // 到达底层
    if(dp[i][j]>=0)
        return dp[i][j];   // 记忆！计算过了就不计算了！
    else
        return dp[i][j]=max(dfs(i+1,j),dfs(i+1,j+1))+a[i][j];
}    
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=i;j++)
            scanf("%d",&a[i][j]);
    memset(dp,-1,sizeof(dp));
    cout<<dfs(1,1)<<endl;   // 递归简单直接
   
    return 0;
}
/*
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5

ans = 30
*/
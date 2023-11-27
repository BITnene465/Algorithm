// 石子合并(链状) ,求最小花费//
// 循环 + 平行四边形优化 //
#include<bits/stdc++.h>
using namespace std;
int dp[301][301];
int n;
int stone[301];
int sum[301]; 
int s[301][301];  // s[i][j]用来记录区间[i,j]的最佳分割点
int Minval()
{
    // 初始化
    for(int i=1;i<=n;i++)
    {
        dp[i][i] = 0;
        s[i][i] = i;
    }
    //
    for(int len=1;len<n;len++)
    {
        for(int i=1;i<=n-len;i++)
        {
            int j = i + len;
            dp[i][j] = INT_MAX;
            for(int k=s[i][j-1];k<=s[i+1][j];k++)   // 平行四边形优化
            {
                if(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]<dp[i][j])
                {
                    dp[i][j] = dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1];
                    s[i][j] = k;    // 记录最佳分割点
                }
            }
        }
    }
    //
    return dp[1][n];
}
int main(void)
{
    cin>>n;
    sum[0] = 0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",stone+i);
        sum[i] = sum[i-1] + stone[i];
    }
    cout<<Minval()<<endl;
    return 0;
}
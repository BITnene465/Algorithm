/**
 * @file E.cpp
 * @author TJY 
 * @brief 
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// DP题 + 优化 //
// 思路一：我们尝试将 dp[·][j] 集体转移到 dp[j][·] ，时间复杂度 O(n^2)
// 思路二：(i,j) --> (j,k) 我们枚举 j ,两边各自排序，然后用双指针 ，时间复杂度 O(n^2logn)
// 此处采用思路二
#include<bits/stdc++.h>
using namespace std;
int n, ans, h[5005], dp[5005][5005];  // dp[i][j]表示以h[i],h[j]结尾的最长长度，O(n^3)的解法很简单
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",h+i);
    // init
    for(int i=1;i<=n-1;++i)for(int j=i+1;j<=n;++j)dp[i][j] = 2;
    // dp
    for(int k=2;k<=n;++k)
    {
        for(int j=1;j<=k-1;++k)
        {   
            if()
        }
    }
    // find ans
    for(int i=1;i<=n-1;++i)for(int j=i+1;j<=n;++j)ans=max(ans, dp[i][j]);
    printf("%d\n", ans);
    return 0;
}
/**
 * @file 运动员最佳配对问题2.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 采用 DP + 状态压缩， 时间复杂度 O(n^2*2^n)
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;
int man[13][13], feman[13][13], n, mat[13][13], dp[13][(1<<13)+5], ans;
int main(void)
{
    // data processing
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &man[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            scanf("%d", &feman[i][j]);
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            mat[i][j] = man[i][j] * feman[j][i];
    // DP
    int m = 1<<n;    // 状态数
    for(int i=1;i<=n;++i)
        for(int j=0;j<m;++j)
            for(int k=1, exp=1;k<m;k<<=1, exp+=1)
                if(k&j)dp[i][j] = max(dp[i][j], dp[i-1][j^k] + mat[i][exp]);
    ans = dp[n][m-1];
    printf("%d\n", ans);
    return 0;
}
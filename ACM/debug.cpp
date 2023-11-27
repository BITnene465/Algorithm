#include <bits/stdc++.h>
using namespace std;
int n, m, cost[105][33], val[105][32], dp[105][105][32];
// dp[i][j][state]  表示前i个套餐，最多花费j元，使用state所代表的元素所得到的最大权值，最终答案为 dp[n][m][31]
int main(void)
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            scanf("%d %d", &val[i][1 << j], &cost[i][1 << j]);
        }
        scanf("%d", &cost[i][32]);
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < 32; ++j)
        {
            for (int k = 1; k < j; k <<= 1)
            { // 用 < 而不是 <= 可以防止加重
                if (j & k)
                {
                    cost[i][j] += cost[i][k];
                    val[i][j] += val[i][k];
                }
            }
        }
    }
    // DP
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            for (int k = 0; k < 32; ++k)
            {
                for (int from = 0; from <= k; ++from)
                {
                    if ((k | from) != k)
                        continue;       // 无法从 from 转移到 k
                    int dif = k ^ from; // 此时，相当于 k - from
                    int min_cost = min(cost[i][dif], cost[i][32]);
                    if (j >= min_cost) // 判断是否可以更新
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - min_cost][from] + val[i][dif]);
                }
            }
        }
    }
    for (int i = 0; i <= n; ++i)
    {
        for (int j = 0; j <= m; ++j)
        {
            printf("dp[%d][%d][31]=%d ", i, j, dp[i][j][31]);
            printf("\n");
        }
    }
    printf("%d\n", dp[n][m][31]);
    return 0;
}

// 也是DP入门题
#include <bits/stdc++.h>
using namespace std;
const int maxN = 201; // 序号从1开始
typedef long long ll;
ll dp[maxN];
ll dis[maxN][maxN];
int n;
void solve()
{
    memset(dp, 1000000, sizeof(dp)); // 足够大的数据即可
    dp[1] = 0;                       // 初始化
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
            dp[i] = min(dp[i], dp[j] + dis[j][i]);
    }
    return;
}
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n - 1; i++)
        for (int j = i + 1; j <= n; j++)
            scanf("%lld", &dis[i][j]);
    solve();
    cout << dp[n] << endl;
    return 0;
}
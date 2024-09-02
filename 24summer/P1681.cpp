#include<bits/stdc++.h>
using namespace std;
int tab[2000][2000], dp[2000][2000], m, n;  // dp[i][j] 表示以(i,j)为右下角的最大正方形边长
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for(int i=1;i<=m;++i)
        for(int j=1;j<=n;++j)
            cin >> tab[i][j];
    // 初始化
    for(int i=1;i<=m;++i)
        dp[i][1] = 1;
    for(int j=1;j<=n;++j)
        dp[1][j] = 1;
    // dp
    int ans = 1;
    for(int i=2;i<=m;++i)
    {
        for(int j=2;j<=n;++j)
        {
            if(tab[i][j]!=tab[i-1][j] && tab[i][j]!=tab[i][j-1])
                dp[i][j] = 1 + min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1]));
            else dp[i][j] = 1;
            ans = max(ans, dp[i][j]);
        }
    }
    cout << ans << endl;
    return 0;
}
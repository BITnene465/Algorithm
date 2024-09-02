// 我曾经的题解： 第一条路爆搜 + 第二条路dp
// 此题解采用 3维dp
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, dp[22][11][11], table[10][10]; // dp[i][j][k] 表示一共走了i步,第一条路向下了j步，第二条路向下了k步能得到的最大和
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    while (1)
    {
        ll x, y, v;
        cin >> x >> y >> v;
        if (!x && !y && !v)
            break;
        table[x - 1][y - 1] = v;
    }
    // dp
    dp[0][0][0] = table[0][0];
    for (ll i = 1; i <= 2 * (n - 1); i++)
    {
        for (ll j = 0; j <= i && j < n; j++)
        {
            for (ll k = 0; k <= i && k < n; k++)
            {
                if (j == k)
                    dp[i][j][k] = table[j][i - j];
                else
                    dp[i][j][k] = table[j][i - j] + table[k][i - k];
                
                ll ma = 0;
                if(j<=i-1 && k<=i-1 && ma < dp[i-1][j][k]) ma = dp[i-1][j][k];
                if(j-1>=0 && k-1>=0 && ma < dp[i-1][j-1][k-1]) ma = dp[i-1][j-1][k-1];
                if(j-1>=0 && k<=i-1 && ma < dp[i-1][j-1][k]) ma = dp[i-1][j-1][k];
                if(j<=i-1 && k-1>=0 && ma < dp[i-1][j][k-1]) ma = dp[i-1][j][k-1];
                dp[i][j][k] += ma; 
            }
        }
    }
    cout << dp[2 * (n - 1)][n - 1][n - 1] << endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, m;
double dp[505][505];
int main(void)
{
    scanf("%d %d", &n, &m);
    dp[0][0] = 0.;
    for(int i=1;i<=n;++i)
    {
        for(int j=0;j<=m;++j)
        {
            dp[i][j] = dp[i-1][j];
            for(int k=1;k<=j;++k) dp[i][j] = max(dp[i][j], dp[i-1][j-k] + (double)k/(m+k-j));
        }
    }
    printf("%.9lf\n", dp[n][m]);
    return 0;
}
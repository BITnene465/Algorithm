// TLE
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e8;
const int N = 2e3+1;
const int max_r = 2e6+1;
int n,d,ans;
int r[N],dp[max_r];
int sum[N];    // 记录前缀和
void solve()
{
    dp[0] = 1;
    int lim = n*d;
    for(int i=1;i<=n;i++)
        for(int j=sum[i];j>=r[i];j--)
            dp[j] = (dp[j] + dp[j-r[i]])%mod;
    for(int i=1;i<=sum[n]/d;i++)
        ans = (ans+dp[i*d])%mod;
    return;
}
int main(void)
{
    scanf("%d %d",&n,&d);
    int temp;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        r[i] = (temp-1)%d+1;   // 使得能力范围在1~d
    }
    sum[0] = 0;
    for(int i=1;i<=n;i++)
        sum[i] = sum[i-1] + r[i];
    solve();
    printf("%d\n",ans);
    return 0;
}
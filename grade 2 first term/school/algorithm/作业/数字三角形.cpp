// 动态规划经典入门题
#include<bits/stdc++.h>
using namespace std;
int n;
int arr[105][105], dp[105][105];
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)for(int j=1;j<=i;++j)cin>>arr[i][j];
    // DP
    for(int i=1;i<=n;++i)dp[n][i] = arr[n][i];
    for(int i=n-1;i>=1;--i){
        for(int j=1;j<=i;++j){
            dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + arr[i][j];
        }
    }
    cout<<dp[1][1]<<endl;
    return 0;
}

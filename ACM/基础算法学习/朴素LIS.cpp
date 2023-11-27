#include<bits/stdc++.h>
using namespace std;
int n,a[5005],dp[5005],ans;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    ans=0;
    for(int i=1;i<=n;++i)cin>>a[i];
    dp[0]=0;
    for(int i=1;i<=n;++i)
    {
        dp[i]=1;
        for(int j=1;j<=i-1;++j)if(a[j]<a[i])dp[i]=max(dp[j]+1,dp[i]);
        ans=max(ans,dp[i]);
    }
    cout<<ans<<endl;
    return 0;
}
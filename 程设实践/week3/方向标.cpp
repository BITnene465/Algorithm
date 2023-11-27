#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=2147483647;
ll n,dp[3005][2005],head[2005],sum[2005],sum2[2005];
// sum[i] = f[1][i] + ... + f[head[i]-1][i]
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    ll tmp;
    cin>>tmp;
    dp[tmp][1]=1;
    sum[1]=1;
    for(ll i=1;i<=n;++i)cin>>head[i];
    for(ll i=2;i<=n;++i)
    {
        if(head[i]==head[i-1])
        {
            for(ll j=1;j<=head[i]-1;++j)dp[j][i]=sum[i-1];
            sum[i]=(head[i]-1)*sum[i-1]%mod;
            continue;
        }
        if(head[i]<head[i-1])
        {
            for(ll j=1;j<head[i];++j)dp[j][i]=dp[j][i-1],sum[i]=(sum[i]+dp[j][i])%mod;
            for(ll j=head[i]+1;j<head[i-1];++j)dp[j][i]=dp[head[i]][i-1],sum2[i]=(sum2[i]+dp[j][i])%mod;
            dp[head[i-1]][i]=sum[i-1];
            sum2[i]=(sum2[i]+dp[head[i-1]][i])%mod;
            for(ll j=head[i-1]+1;j<3000;++j)dp[j][i]=(dp[j][i-1]+dp[head[i]][i-1])%mod,sum2[i]=(sum2[i]+dp[j][i])%mod;;
            continue;
        }
        // head[i]>head[i-1]
        for(ll j=head[i]+1;j<3000;++j)dp[j][i]=dp[j][i-1],sum2[i]=(sum2[i]+dp[j][i])%mod;
        for(ll j=head[i-1]+1;j<head[i];++j)dp[j][i]=dp[head[i]][i-1],sum[i]=(sum[i]+dp[j][i])%mod;
        dp[head[i-1]][i]=sum2[i-1];
        sum[i]=(sum[i]+dp[head[i-1]][i])%mod;
        for(ll j=1;j<head[i-1];++j)dp[j][i]=(dp[head[i]][i-1]+dp[j][i-1])%mod,sum[i]=(sum[i]+dp[j][i])%mod;
    }
    // print
    cout<<(sum[n]+sum2[n])%mod<<endl;
    return 0;
}
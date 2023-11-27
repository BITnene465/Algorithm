#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3e4+10;
ll n,m,dp[maxn][30],t[30],v[30];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(ll i=1;i<=m;++i)
    {
        ll a,b;
        cin>>a>>b;
        t[i]=a;v[i]=a*b;
    }
    // Dp
    for(ll j=1;j<=m;++j)
        for(ll i=0;i<=n;++i)
        {   
            if(i<t[j]){dp[i][j]=dp[i][j-1];continue;}
            dp[i][j]=max(dp[i][j-1],dp[i-t[j]][j-1]+v[j]);
        }
    cout<<dp[n][m]<<endl;
    return 0;
}
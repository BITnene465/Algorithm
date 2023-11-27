// 枚举第一条路径 + DP第二条路径 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[10][10],b[10][10],dp[10][10];
ll n,ans;
ll solve()    //跑一遍DP 
{
    memset(dp,0,sizeof dp);
    for(ll i=1;i<=n;++i)
        for(ll j=1;j<=n;++j)
            dp[i][j]=max(dp[i-1][j],dp[i][j-1])+a[i][j];
    return dp[n][n];
}
void dfs(ll x,ll y,ll sum)
{
    sum+=a[x][y];
    a[x][y]=0;
    if(x==n&&y==n)
    {
        ll tmp=solve();
        ans=max(ans,tmp+sum);
        a[x][y]=b[x][y];   // 不要忘记 
        return;
    }
    if(x+1<=n)dfs(x+1,y,sum);
    if(y+1<=n)dfs(x,y+1,sum);
    a[x][y]=b[x][y];
}   
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    ll x,y,val;
    while(cin>>x>>y>>val)
    {
        if(x==0&&y==0)break;
        a[x][y]=b[x][y]=val;
    }
    ans=0;
    dfs(1,1,0);
    cout<<ans<<endl;
    return 0;
}
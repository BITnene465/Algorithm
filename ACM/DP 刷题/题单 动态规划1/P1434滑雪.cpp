// 记忆化搜索入门好题 //
// dp[i][j]表示从点（i，j）开始，最长的滑雪路径 //
// 当你不知道更新顺序的时候，可以使用记忆化搜索 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
const int dx[]={1,0,-1,0};
const int dy[]={0,-1,0,1};
int m,n,ans,a[maxn][maxn],dp[maxn][maxn];   // m行n列
int dfs(int x,int y)
{
    if(dp[x][y])return dp[x][y];
    int res=0;
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>0&&nx<=m&&ny>0&&ny<=n&&a[nx][ny]<a[x][y])res=max(res,dfs(nx,ny));
    }
    res+=1;
    return dp[x][y]=res;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m>>n;
    for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)cin>>a[i][j];
    for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)if(!dp[i][j])dfs(i,j);
    for(int i=1;i<=m;++i)for(int j=1;j<=n;++j)ans=max(ans,dp[i][j]);
    cout<<ans<<endl;
    return 0;
}
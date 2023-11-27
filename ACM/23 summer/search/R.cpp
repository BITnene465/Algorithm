// floyd 无向图,模板 //
#include<bits/stdc++.h>
using namespace std;
vector<int> g[101];
int dp[101][101];
int n,m;
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
                dp[x][y] = min(dp[x][y],dp[x][k]+dp[k][y]);
}
int main(void)
{
    cin>>n>>m;
    int u,v,w;
    memset(dp,0x3f,sizeof(dp));   // 为了两个相加不会越界
    for(int i=1;i<=n;i++)
        dp[i][i] = 0;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        g[u].push_back(v);
        g[v].push_back(u);
        dp[u][v] = w;    // 边权初始化
        dp[v][u] = w;
    }
    floyd();
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            printf("%d%c",dp[i][j],(j==n)?'\n':' ');
    }
    return 0;
}
// 无向图最小环（至少三元环） floyd //
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 105;
int m,n,f[maxn][maxn],ans;
int ww[maxn][maxn];
void floyd()
{
    for(int u=1;u<=n;u++)
        for(int x=1;x<=n;x++)
            for(int y=1;y<=n;y++)
            {
                if(ww[u][x]!=INF&&ww[u][y]!=INF&&x!=y&&f[x][y]!=INF)
                    ans = min(ans,f[x][y]+ww[u][x]+ww[y][u]);
                if(f[u][y]==INF||f[x][u]==INF)  continue;
                if(f[x][y]>f[x][u]+f[u][y])
                    f[x][y]=f[x][u]+f[u][y];
            }
}
int main(void)
{
    cin>>n>>m;
    int u,v,w;
    memset(f,0x3f,sizeof(f));
    memset(ww,0x3f,sizeof(ww));
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        f[v][u] = f[u][v] = min(f[u][v],w);   
        ww[u][v]=ww[v][u]=min(ww[u][v],w);    // 小心重边！！
    }
    for(int i=1;i<=n;i++)
        f[i][i] = 0;
    ans = INF;
    floyd();
    if(ans==INF)    printf("No solution.\n");
    else printf("%d\n",ans);
    return 0;
}
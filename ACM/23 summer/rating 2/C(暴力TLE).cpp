// 暴力方法，但是适用于任何图 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,m,id,ans;
int dis[4][maxn];
queue<int> q;
vector<int> tr[maxn];
int vis[maxn];
void bfs(int s,int i)
{
    for(int j=1;j<=n;j++)   vis[j]=0;
    vis[s]=1;
    q.push(s);
    dis[i][s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto v:tr[u])
        {
            if(!vis[v])
            {
                vis[v]=1;
                dis[i][v]=dis[i][u]+1;
                q.push(v);
            }
        }        
    }
}
void query(int x,int y,int z)
{
    bfs(x,1);
    bfs(y,2);
    bfs(z,3);
    id=0,ans=n;
    for(int i=1;i<=n;i++)
        if(dis[1][i]+dis[2][i]+dis[3][i]<ans){id=i;ans=dis[1][i]+dis[2][i]+dis[3][i];}
}
int main(void)
{
    scanf("%d %d",&n,&m);
    int u,v;
    for(int i=1;i<=n-1;i++)
    {
        scanf("%d %d",&u,&v);
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    while(m--)
    {
        int x,y,z;
        scanf("%d %d %d",&x,&y,&z);
        query(x,y,z);
        printf("%d %d\n",id,ans);
    }
    return 0;
}
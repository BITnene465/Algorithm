// corn maze S //
// 把二维地图转换为无向的图论图，而且为无权图，用BFS跑一遍即可 //
#include<bits/stdc++.h>
using namespace std;
vector<int> g[90005];    // 点(x,y) 对应点 x+(y-1)*m   (方格表放置于第一象限)
queue<int> q;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
int vis[90005];
int dis[90005]; 
char s[310][310];
int n,m;    // n行m列
int st,val;  // 分别表示起点和终点
void build_g()
{
    for(int y=1;y<=n;y++)
        for(int x=1;x<=n;x++)
        {
            if(s[y][x]=='#')    continue;
            if(s[y][x]=='.')
            {
                for(int i=0;i<=4;i++)
                {
                    int newx=x+dx[i];
                    int newy=y+dy[i];
                    if(newx<=m&&newy<=n&&newx>=1&&newy>=1&&s[newy][newx]!='#')
                    {
                        ;
                    }
                }
            }
        }
}
void bfs(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;
    vis[s] = 1;
    q.push(s);
    int u;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                dis[v] = dis[u] + 1;
                q.push(v);
            }
        }
    }
}
int main(void)
{
    cin>>n>>m;
    for(int y=n;y>=1;--y)
    {
        for(int x=1;x<=m;x++)
            scanf("%c",&s[y][x]);
        getchar();
    }
    build_g();
    bfs(st);
    cout<<dis[val]<<endl;
    return 0;
}
// 可以抽象为一个最短路问题,而且是无权图的最短路问题，可以直接使用Bfs，时间复杂度为O(knm)(好像确实会超时) //
// 最初版，13、18 TLE //
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
int n,m,k,sx,sy,tx,ty,ans,dis[1005][1005];
char s[1005][1005];
bool vis[1005][1005];
queue<pii> q;
void Bfs()
{
    ans=-1;
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    q.push(make_pair(sx,sy));
    while(!q.empty())
    {
        pii u=q.front();q.pop();
        int nx,ny;
        int d=dis[u.first][u.second];
        // 判断一下终点
        if(u.first==tx&&u.second==ty){ans=d;break;}
        //
        for(int i=1;i<=k;++i)
        {
            nx=u.first+i;ny=u.second;
            if(s[nx][ny]=='#'||nx>n)break;
            if(!vis[nx][ny])
            {
                q.push(make_pair(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.first-i;ny=u.second;
            if(s[nx][ny]=='#'||nx<=0)break;
            if(!vis[nx][ny])
            {
                q.push(make_pair(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.first;ny=u.second+i;
            if(s[nx][ny]=='#'||ny>m)break;
            if(!vis[nx][ny])
            {
                q.push(make_pair(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.first;ny=u.second-i;
            if(s[nx][ny]=='#'||ny<=0)break;
            if(!vis[nx][ny])
            {
                q.push(make_pair(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
            }
        }
    }

}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>k;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>s[i][j];
    cin>>sx>>sy>>tx>>ty;
    Bfs();
    cout<<ans<<endl;
    return 0;
}
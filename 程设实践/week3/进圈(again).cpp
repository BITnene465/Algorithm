// 改成c风格io以减小常数后仍然TLE //
// 把终点判断从出队判断改为入队判断后就过了，nt //
#include<bits/stdc++.h>
using namespace std;
struct point
{
    int x,y;
    point(int x,int y):x(x),y(y){};
};
int n,m,k,sx,sy,tx,ty,ans,dis[1005][1005];
char s[1005][1005];
bool vis[1005][1005];
queue<point> q;
void Bfs()
{
    ans=-1;
    vis[sx][sy]=1;
    dis[sx][sy]=0;
    q.push(point(sx,sy));
    while(!q.empty())
    {
        point u=q.front();q.pop();
        int nx,ny;
        int d=dis[u.x][u.y];
        // 判断一下终点
        if(u.x==tx&&u.y==ty){ans=d;break;}
        //
        for(int i=1;i<=k;++i)
        {
            nx=u.x+i;ny=u.y;
            if(s[nx][ny]=='#')break;
            if(nx<=n&&!vis[nx][ny])
            {
                q.push(point(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
                if(nx==tx&&ny==ty){ans=d+1;return;}
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.x-i;ny=u.y;
            if(s[nx][ny]=='#')break;
            if(nx>0&&!vis[nx][ny])
            {
                q.push(point(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
                if(nx==tx&&ny==ty){ans=d+1;return;}
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.x;ny=u.y+i;
            if(s[nx][ny]=='#')break;
            if(ny<=m&&!vis[nx][ny])
            {
                q.push(point(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
                if(nx==tx&&ny==ty){ans=d+1;return;}
            }
        }
        for(int i=1;i<=k;++i)
        {
            nx=u.x;ny=u.y-i;
            if(s[nx][ny]=='#')break;
            if(ny>0&&!vis[nx][ny])
            {
                q.push(point(nx,ny));
                vis[nx][ny]=1;
                dis[nx][ny]=d+1;
                if(nx==tx&&ny==ty){ans=d+1;return;}
            }
        }
    }
}
int main(void)
{
    scanf("%d %d %d",&n,&m,&k);
    getchar();
    for(int i=1;i<=n;++i){scanf("%s",s[i]+1);getchar();}
    scanf("%d %d %d %d",&sx,&sy,&tx,&ty);
    Bfs();
    printf("%d\n",ans);
    return 0;
}
// BFS 典型题 ； 含有逐步扩散的时间，很符合BFS的逻辑 //
#include<bits/stdc++.h>
using namespace std;
const int dx[4]={0,-1,0,1};
const int dy[4]={1,0,-1,0};
int m,mt;
struct lx
{
    int x,y;
    lx(int x,int y):x(x),y(y){};
};
struct pla
{
    int x,y;
    int t;
    pla(int x,int y,int t):x(x),y(y),t(t){};
};
vector<lx> star[1005];    // 每个时间砸下的流星 
bool Final[305][305],st[305][305];
bool vis[305][305];     // 走过就不要再走了，否则TLE 
void pre_final()
{
    for(int i=0;i<=mt;++i)
    {
        for(auto p:star[i])
        {
            if(!Final[p.x][p.y])Final[p.x][p.y]=1;
            if(p.x-1>=0&&!Final[p.x-1][p.y])Final[p.x-1][p.y]=1;
            if(p.y-1>=0&&!Final[p.x][p.y-1])Final[p.x][p.y-1]=1;
            if(!Final[p.x+1][p.y])Final[p.x+1][p.y]=1;
            if(!Final[p.x][p.y+1])Final[p.x][p.y+1]=1;
        }
    }
}
void fall(int t)
{
    for(auto p:star[t])
        {
            if(!st[p.x][p.y])st[p.x][p.y]=1;
            if(p.x-1>=0&&!st[p.x-1][p.y])st[p.x-1][p.y]=1;
            if(p.y-1>=0&&!st[p.x][p.y-1])st[p.x][p.y-1]=1;
            if(!st[p.x+1][p.y])st[p.x+1][p.y]=1;
            if(!st[p.x][p.y+1])st[p.x][p.y+1]=1;
        }
}
void bfs()
{
    queue<pla> q;
    fall(0);
    if(!st[0][0])q.push(pla(0,0,0)),vis[0][0]=1;
    int nowtime=0;
    while(!q.empty())
    {
        auto p=q.front();q.pop();
        if(!Final[p.x][p.y]){cout<<p.t<<endl;return;}     // 出队时判断是否到了安全的位置
        
        if(p.t+1>nowtime)fall(p.t+1);    // 入队时下落流星
        nowtime=p.t+1;
        for(int i=0;i<4;++i)
        {
            int nx=p.x+dx[i],ny=p.y+dy[i];
            if(nx>=0&&ny>=0&&!st[nx][ny]&&!vis[nx][ny])q.push(pla(nx,ny,p.t+1)),vis[nx][ny]=1;
        }
    }
    cout<<"-1"<<endl;
    return;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int x,y,t;
        cin>>x>>y>>t;
        if(t>mt)mt=t;
        star[t].push_back(lx(x,y));
    }
    pre_final();
    bfs();
    return 0;
}
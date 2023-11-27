// 乘法取对数，即加法 ； 负权最长路，去反即正权最短路 //
#include<bits/stdc++.h>
using namespace std;
typedef double D;
const int maxn=2005;
const D INF=-1.0;
// 快读
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
struct edge{
    int v;
    D w;
};
int n,m,s,t,flag[maxn];
D dis[maxn];
vector<edge> e[maxn];
priority_queue<pair<D,int>>  q;
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
        dis[i] = INF;
    dis[s]=1.;
    q.push(make_pair(dis[s],s));
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(flag[u])continue;
        flag[u]=1;
        for(auto ed:e[u])
        {
            int v=ed.v;
            D w=ed.w;
            if(dis[v]<dis[u]*w)   // 最长路更新
            {
                dis[v]=dis[u]*w;
                q.push(make_pair(dis[v],v));
            }
        }
    }
}
int main(void)
{
    n=read(),m=read();
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        D rate = 1.0-0.01*(D)w;
        e[u].push_back({v,rate});
        e[v].push_back({u,rate});
    }
    s=read(),t=read();
    dijkstra(s);
    printf("%.8lf\n",100.0/dis[t]);
    return 0;
}

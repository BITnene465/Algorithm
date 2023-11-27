// 只有点权就是只有边权 直接跑最短路即可 //
// 另外一个方法 ： 将点权转换为边权， 每条边的边权=两端的点权的算数平均 ， 则dis(i,j)=dis'(i,j)+(value[i]+value[j])/2
// 其中：dis(i,j)表示真正的最短路，dis'(i,j)是计算出来的最短路 //
// AC code //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
const ll INF=0x3f3f3f3f3f3f3f3f;
ll n,m,k,s,P,Q,c[maxn],value[maxn],cost[maxn];
ll dis[maxn];
int vis[maxn],flag[maxn];
priority_queue<pair<ll,ll>>q;
vector<ll> e[maxn];
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void bfs(ll x,ll s)   // x为起点，s为距离
{
    dis[x]=-1;    // 超级源点的距离定义为-1
    queue<ll> q;
    q.push(x);
    vis[x]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        if(dis[u]==s)   continue;
        for(auto v:e[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                dis[v]=dis[u]+1;
            }
        }
    }
}
void Dijkstra(ll s)
{
    memset(cost,0x3f,sizeof(cost));
    cost[s]=value[s];
    q.push(make_pair(-cost[s],s));
    while(!q.empty())
    {
        ll u=q.top().second;q.pop();
        if(flag[u])continue;
        flag[u]=1;
        for(auto v:e[u])
        {
            if(value[v]!=INF&&cost[v]>cost[u]+value[v])
            {
                cost[v]=cost[u]+value[v];
                q.push(make_pair(-cost[v],v));
            }
        }
    }
}
int main(void)
{
    n=read(),m=read(),k=read(),s=read();
    P=read(),Q=read();
    for(ll i=1;i<=k;i++)
        c[i]=read();
    ll u,v;
    for(ll i=1;i<=m;i++)
    {
        u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    // 建立超级源点n+1进行bfs
    for(ll i=1;i<=k;i++)
        e[n+1].push_back(c[i]);
    bfs(n+1,s);
    for(ll i=1;i<=n;i++)
    {
        if(vis[i])  value[i]=Q;   //危险
        else        value[i]=P;   //安全
    }
    for(ll i=1;i<=k;i++)
        value[c[i]]=INF;    // 极度危险
    value[1]=value[n]=0;   // 起点和终点
    //
    Dijkstra(1);
    cout<<cost[n]<<endl;
    return 0;
}
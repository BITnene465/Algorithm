// 物流运输 //
// f[i]为前i天最小代价，cost(i,j)表示第i天到第j天走同一道路，可走的最短路//
// f[i]=min(f[j]+cost(j+1,i)*(i-j)+k) 0<=j<=i-1 , 思考为什么？ //
// 用最短路算法预处理 cost(j+1,i) //
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll maxn=1005;
const ll maxm=250;
ll n,m,k,e,d;
struct edge{
    ll v;
    ll w;
};
vector<edge>ee[maxm];    // 邻接表存图
set<ll>forbid[maxn];   // 记录第i天被禁用的点
ll vis[maxm];    // dijk 时解决禁用的点的问题
ll flag[maxm];
ll dis[maxm];
ll min_dis[maxn];  // 记录每天的最短路长度
ll f[maxn],cost[maxn][maxn];
priority_queue<pair<ll,ll>>q;
ll read()
{
    ll f=1,x=0;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void init()
{
    for(ll i=1;i<=m;i++)
    {
        dis[i]=INF;
        flag[i]=0;
        vis[i]=0;
    }
    return;
}
void dijkstra()
{
    dis[1]=0;
    q.push({0,1});   // 不可能哪一天禁用 点1 和 点n 吧
    while(!q.empty())
    {
        int u=q.top().second;
        q.pop();
        if(flag[u]) continue;
        flag[u]=1;
        for(auto ed:ee[u])
        {
            ll v=ed.v,w=ed.w;
            if(vis[v])  continue;   // 禁用点，那么不更新
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({-dis[v],v});
            }
        }
    }
    return;
}
int main(void)
{
    n=read(),m=read(),k=read(),e=read();
    ll u,v,w;
    for(int i=1;i<=e;i++)
    {
        u=read();v=read();w=read();
        ee[u].push_back({v,w});
        ee[v].push_back({u,w});
    }
    d=read();
    ll l,r;
    for(ll i=1;i<=d;i++)
    {
        u=read();l=read();r=read();
        for(ll j=l;j<=r;j++)
            forbid[j].insert(u);   // 第j天禁用点u
    }
    // 开始预处理 cost数组 //
    for(ll i=1;i<=n;i++)
    {
        for(ll j=i;j<=n;j++)
        {
            init();
            for(ll kk=i;kk<=j;kk++)
            for(auto t:forbid[kk])  vis[t]=1;
            dijkstra();
            cost[i][j]=dis[m];   // 若为INF则是无法到达
        }
    }
    // 处理DP数组
    for(ll i=1;i<=n;i++)
    {
        if(cost[1][i]==INF) f[i]=INF;
        else f[i]=cost[1][i]*i;
        for(ll j=i-1;j>=1;--j)
            if(cost[j+1][i]!=INF&&f[j]!=INF)
                f[i]=min(f[i],f[j]+cost[j+1][i]*(i-j)+k);
    }
    cout<<f[n]<<endl;
    return 0;
}
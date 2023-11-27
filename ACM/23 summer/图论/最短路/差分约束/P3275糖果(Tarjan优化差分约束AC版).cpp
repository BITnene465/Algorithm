// 差分约束 + 求所有可行解中可行解最小值>=1,且可行解之和最小的可行解 //
// 边权特殊，可以使用Tarjan缩点 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
ll x,a,b,n,k;
struct edge{
    ll v;
    ll w;
    edge(ll v,ll w):v(v),w(w){}
};
vector<edge> G[MAXN];
queue<ll> Q;
inline void add(ll u,ll v,ll w){G[u].push_back(edge(v,w));}
void adde(ll type,ll u,ll v)    // 最后跑最长路
{
    switch(type)
    {
        case 1:
        add(u,v,0);
        add(v,u,0);
        break;
        case 2:
        add(u,v,1);
        break;
        case 3:
        add(v,u,0);
        break;
        case 4:
        add(v,u,1);
        break;
        case 5:
        add(u,v,0);
        break;
    }
}
ll stk[MAXN],top,cnt,low[MAXN],dfn[MAXN];
bool instk[MAXN];
ll id[MAXN],id_cnt,siz[MAXN],dis[MAXN],indeg[MAXN];
vector<edge> NG[MAXN];
void _Tarjan(int u)
{
    instk[u]=1,stk[++top]=u,dfn[u]=low[u]=++cnt;
    for(auto ed:G[u])
    {
        ll v=ed.v;
        if(!dfn[v]) _Tarjan(v),low[u]=min(low[u],low[v]);
        else if(instk[v]) low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++id_cnt;
        while(stk[top]!=u){id[stk[top]]=id_cnt;instk[stk[top--]]=0;siz[id_cnt]++;}
        id[u]=id_cnt,instk[u]=0,siz[id_cnt]++,--top;
    }
}
void Tarjan(int n)
{
    for(int i=1;i<=n;++i)
        if(!dfn[i]) _Tarjan(i);
}
void Topu(ll u)
{
    Q.push(u),dis[u]=1;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        for(auto ed:NG[u])
        {
            ll v=ed.v,w=ed.w;
            dis[v]=max(dis[v],dis[u]+w);
            indeg[v]--;
            if(!indeg[v])Q.push(v);
        }
    }
}
int main(void)
{
    scanf("%lld %lld",&n,&k);
    for(ll i=1;i<=k;++i)
    {
        scanf("%lld %lld %lld",&x,&a,&b);
        adde(x,a,b);
    }
    Tarjan(n);    // 缩点后得到的是逆拓扑序
    // 缩点之后如果同一个scc中有正权边，那么一定有正环，从而无最长路 , 从而无解 ,时间O(m) //
    for(ll u=1;u<=n;++u)
    {
        for(auto ed:G[u])
        {
            ll v=ed.v,w=ed.w;
            if(w&&id[v]==id[u]){printf("-1\n");return 0;}
            if(id[v]!=id[u]){NG[id[u]].push_back(edge(id[v],w));indeg[id[v]]++;}
        }
    }
    // 否则有解,且同一个scc中只有0权边 scc之间可以有0/1边 //
    for(int i=1;i<=id_cnt;++i)
        if(!indeg[i])Topu(i);
    ll ans=0;
    for(ll i=1;i<=id_cnt;++i)ans=ans+dis[i]*siz[i];
    printf("%lld\n",ans);
    return 0;
}
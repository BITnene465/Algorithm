#include<bits/stdc++.h>
using namespace std;
#define MAXN 300
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;

struct Edge{
    ll from,to,cap,flow;
    Edge(ll u,ll v,ll c,ll f):from(u),to(v),cap(c),flow(f){}
};   // 存边，单向边

struct EK{
    ll n,m;     // n：顶点数，m：边数
    vector<Edge> edges;   // 所有的边集合,id从0开始
    vector<ll> G[MAXN];  // G[x][i]表示节点x发出的第i条边的id，访问edges[id]即可
    ll a[MAXN],p[MAXN];
    // a：点 x -> BFS 过程中最接近点 x 的边给他带来的最大流
    // P：点 x -> BFS 过程中最接近点 x 的边
    void init(ll n)
    {
        for(ll i=1;i<=n;++i)G[i].clear();   //这个根据选点需要可以更改
        edges.clear();
    } 
    void adde(ll from,ll to,ll cap)
    {
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));
        m=edges.size();
        G[from].push_back(m-2);G[to].push_back(m-1); 
        // 正向边id为偶数，反向边id为奇数，并且相邻（id从0开始）
    }
    void Bfs(ll s,ll t)
    {
        memset(a,0,sizeof(a));
        queue<ll> Q;
        Q.push(s);a[s]=INF;
        while(!Q.empty())
        {
            ll x=Q.front();Q.pop();
            for(ll i=0;i<G[x].size();i++)
            {
                Edge& e=edges[G[x][i]];
                if(!a[e.to]&&e.cap>e.flow)
                {
                    p[e.to]=G[x][i];
                    a[e.to]=min(a[x],e.cap-e.flow);
                    Q.push(e.to);
                }
            }
            if(a[t])break;  // 如果汇点接收了流，就没必要再搜了，直接退出 BFS
        }
    }
    ll Maxflow(ll s,ll t)
    {
        ll flow=0;
        while(1)
        {
            Bfs(s,t);
            if(!a[t])break;   //如果汇点没有接收到流，说明源点和汇点不在同一个联通分量上
            for(ll u=t;u!=s;u=edges[p[u]].from)// 通过 u 追寻 BFS 过程中 s -> t的路径
            {
                edges[p[u]].flow +=a[t];  //增加路径上的flow值
                edges[p[u]^1].flow -=a[t]; //减少反向路径的flow值
            }
            flow += a[t];
        }
        return flow;
    }
};
EK mf;
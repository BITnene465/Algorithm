#include<bits/stdc++.h>
#define MAXN 500    // number of node
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
struct EK
{
    struct Edge{
        int from,to;
        ll cap,flow;
        Edge(int u,int v,ll c,ll f):from(u),to(v),cap(c),flow(f){};
    };
    vector<Edge> edges;
    vector<int> G[MAXN];    // 存边的编号
    ll a[MAXN],p[MAXN];
    int n,m;
    void init(int x)   // 输入顶点数
    {
        n = x;m = 0;
        for(int i=1;i<=n;++i)G[i].clear();
        edges.clear();
    }
    void AddEdge(int u,int v,ll c,ll f)
    {
        edges.push_back(Edge(u,v,c,f));
        edges.push_back(Edge(v,u,0,0));
        m = edges.size();
        G[u].push_back(m-2);
        G[v].push_back(m-1);
    }
    ll MaxFlow(int s,int t)    // 源点和汇点
    {
        ll flow=0;
        while(1)
        {
            memset(a,0,sizeof a);
            if(Bfs(s,t))flow+=a[t];
            else break;
        }
        return flow;
    } 
    bool Bfs(int s,int t)    // 寻找增广路
    {
        queue<int> Q;     // 容器会自动初始化
        a[s]=INF;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            for(auto id:G[u])
            {
                Edge& e=edges[id];
                if(e.cap>e.flow && !a[e.to])
                {
                    p[e.to]=id;
                    a[e.to]=min(a[u],e.cap-e.flow);
                    Q.push(e.to);
                }
            }
            if(a[t])break;
        }
        if(!a[t])return false;    // 不联通
        // upd edges' flow
        for(int u=t;u!=s;u=edges[p[u]].from)
        {
            edges[p[u]].flow += a[u];
            edges[p[u]^1].flow -= a[u];   // 反向边
        }
        return true;
    }
};
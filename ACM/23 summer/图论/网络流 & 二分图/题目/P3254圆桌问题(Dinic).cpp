// 最大流建模 //  // 使用 Dinic 防止超时 //
#include<bits/stdc++.h>
using namespace std;
#define maxn 500
#define INF 0x3f3f3f3f3f3f3f3f
typedef long long ll;

struct Edge {
  ll from, to, cap, flow;
  Edge(ll u, ll v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};

// Dinic算法的结构体，包含了初始化，添加边等等各类功能
struct Dinic {
  ll n, m, s, t;
  vector<Edge> edges;
  vector<ll> G[maxn];
  ll d[maxn], cur[maxn];
  bool vis[maxn];

  void init(ll n) {
    for (ll i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  void AddEdge(ll from, ll to, ll cap) {
    edges.push_back(Edge(from, to, cap, 0));
    edges.push_back(Edge(to, from, 0, 0));
    m = edges.size();
    G[from].push_back(m - 2);
    G[to].push_back(m - 1);
  }
 
  bool BFS() {
    memset(vis, 0, sizeof(vis));
    queue<ll> Q;
    Q.push(s);
    d[s] = 0;
    vis[s] = 1;
    while (!Q.empty()) {
      ll x = Q.front();
      Q.pop();
      for (ll i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (!vis[e.to] && e.cap > e.flow) {
          vis[e.to] = 1;
          d[e.to] = d[x] + 1;
          Q.push(e.to);
        }
      }
    }
    return vis[t];
  }
  ll DFS(ll x, ll a) {
    if (x == t || a == 0) return a;
    ll flow = 0;ll f;
    for (ll& i = cur[x]; i < G[x].size(); i++) {
      Edge& e = edges[G[x][i]];
      if (d[x] + 1 == d[e.to] && (f = DFS(e.to, min(a, e.cap - e.flow))) > 0) {
        e.flow += f;
        edges[G[x][i] ^ 1].flow -= f;
        flow += f;
        a -= f;
        if (a == 0) break;
      }
    }
    return flow;
  }
  ll Maxflow(ll s, ll t) {
    this->s = s;
    this->t = t;
    ll flow = 0;
    while (BFS()) {
      memset(cur, 0, sizeof(cur));
      flow += DFS(s, INF);
    }
    return flow;
  }
  // 找到一组可行解 //
    void search(ll m)
    {
        for(ll i=1;i<=m;++i)
        {
            for(ll j=0;j<G[i].size();++j)
            {
                Edge& e=edges[G[i][j]];
                if(e.flow==1)cout<<e.to-m<<" ";
            }
            cout<<endl;
        }
    }
};
Dinic mf;
ll n,m,sumr,r,c;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>m>>n;
    mf.init(n+m+2);sumr=0;
    for(ll i=1;i<=m;++i)
    {
        cin>>r;
        mf.AddEdge(n+m+1,i,r);
        sumr+=r;
    }
    for(ll i=1;i<=n;++i)
    {
        cin>>c;
        mf.AddEdge(m+i,m+n+2,c);
    }
    for(ll i=1;i<=m;++i)
        for(ll j=m+1;j<=m+n;++j)
            mf.AddEdge(i,j,1);
    if(sumr!=mf.Maxflow(n+m+1,n+m+2)){cout<<"0"<<endl;return 0;}
    cout<<"1"<<endl;
    mf.search(m);
    return 0;
}
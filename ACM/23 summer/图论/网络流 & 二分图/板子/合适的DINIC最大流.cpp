// 弧优化的Dinic大法 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define maxn 500 // count of Node
#define INF 0x3f3f3f3f3f3f3f3f
// 定义存储每条边的数据结构
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
};
Dinic mf;
// 以下为测试 //
ll n,m,s,t;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m>>s>>t;
    mf.init(n);
    for(ll i=1;i<=m;++i)
    {
        ll u,v,w;
        cin>>u>>v>>w;
        mf.AddEdge(u,v,w);
    }
    cout<<mf.Maxflow(s,t)<<endl;
    return 0;
}
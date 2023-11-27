// 最合适的版本 ISAP大法//
// 有错误 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF=0x3f3f3f3f3f3f3f3f;
const ll maxn=500;    // 数值记得改

struct Edge {
  ll from, to, cap, flow;
  Edge(ll u, ll v, ll c, ll f) : from(u), to(v), cap(c), flow(f) {}
};

bool operator<(const Edge& a, const Edge& b) {
  return a.from < b.from || (a.from == b.from && a.to < b.to);
}

struct ISAP {
  ll n, m, s, t;
  vector<Edge> edges;
  vector<ll> G[maxn];
  bool vis[maxn];
  ll d[maxn];
  ll cur[maxn];
  ll p[maxn];
  ll num[maxn];

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
    Q.push(t);
    vis[t] = 1;
    d[t] = 0;
    while (!Q.empty()) {
      ll x = Q.front();Q.pop();
      for (ll i = 0; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i] ^ 1];
        if (!vis[e.from] && e.cap > e.flow) {
          vis[e.from] = 1;
          d[e.from] = d[x] + 1;
          Q.push(e.from);
        }
      }
    }
    return vis[s];
  }

  void init(ll n) {
    this->n = n;
    for (ll i = 0; i < n; i++) G[i].clear();
    edges.clear();
  }

  ll Augment() {
    ll x = t, a = INF;
    while (x != s) {
      Edge& e = edges[p[x]];
      a = min(a, e.cap - e.flow);
      x = edges[p[x]].from;
    }
    x = t;
    while (x != s) {
      edges[p[x]].flow += a;
      edges[p[x] ^ 1].flow -= a;
      x = edges[p[x]].from;
    }
    return a;
  }

  ll Maxflow(ll s, ll t) {
    this->s = s;      // 方便Augment里面调用
    this->t = t;
    ll flow = 0;
    BFS();
    memset(num, 0, sizeof(num));
    for (ll i = 0; i < n; i++) num[d[i]]++;
    ll x = s;
    memset(cur, 0, sizeof(cur));
    while (d[s] < n) {
      if (x == t) {
        flow += Augment();
        x = s;
      }
      bool ok = 0;
      for (ll i = cur[x]; i < G[x].size(); i++) {
        Edge& e = edges[G[x][i]];
        if (e.cap > e.flow && d[x] == d[e.to] + 1) {
          ok = 1;
          p[e.to] = G[x][i];
          cur[x] = i;
          x = e.to;
          break;
        }
      }
      if (!ok) {
        ll m = n - 1;
        for (ll i = 0; i < G[x].size(); i++) {
          Edge& e = edges[G[x][i]];
          if (e.cap > e.flow) m = min(m, d[e.to]);
        }
        if (--num[d[x]] == 0) break;
        num[d[x] = m + 1]++;
        cur[x] = 0;
        if (x != s) x = edges[p[x]].from;
      }
    }
    return flow;
  }
};
ISAP mf;
// 以下为测试主函数 //
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
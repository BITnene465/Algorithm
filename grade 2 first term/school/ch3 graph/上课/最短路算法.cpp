// 手敲一下最短路算法 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,m;
struct edge{
        ll v;
        ll w;
        edge(ll v, ll w){
            this->v = v;
            this->w = w;
        }
    };
// 优先队列优化的 Dijkstra算法
// 使用前提： 正权图
namespace Dijkstra{
    ll dis[1005];
    vector<edge> g[1005];
    priority_queue<pair<ll, ll>> q;     // {-dis, node}
    bool flag[1005];
    void dijkstra(ll s, ll n)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(flag, 0, sizeof(flag));
        dis[s] = 0;
        q.push(make_pair(0, s));
        while(q.size()){
            ll u = q.top().second; q.pop();
            if(flag[u])continue;
            flag[u]=1;
            for(auto e: g[u]){
                ll v = e.v, w = e.w;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push(make_pair(-dis[v], v));
                }
            }
        }
    }
}


// SPFA 算法
// 作用：求最短路同时判负环 
namespace SPFA
{
    ll dis[1005], cnt[1005];
    vector<edge> g[1005];
    queue<ll> q;
    bool inque[1005];
    bool spfa(ll s, ll n)
    {
        memset(dis, 0x3f, sizeof(dis));
        memset(inque, 0, sizeof(inque));
        dis[s] = 0;
        q.push(s);
        inque[s] = 1;
        while(q.size()){
            ll u = q.front(); q.pop();
            for(auto e: g[u]){
                ll v = e.v, w = e.w;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    cnt[v] = cnt[u] + 1;
                    if(!inque[v]){q.push(v);inque[v]=1;}
                    if(cnt[v]>=n)return 1;    // 有负环
                }
            }
        }
        return 0;   // 没有负环
    }
} // namespace SPFA

namespace FLOYD
{
    ll dis[1005][1005];
    void init(ll n){
        memset(dis, 0x3f, sizeof(dis));
        for(int i=1;i<=n;++i)dis[i][i] = 0;
        return;
    }
    void floyd(ll n)
    {
        // 循环顺序不能乱 // 
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)   
                    dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
    }
    void printDistance(ll n){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(dis[i][j]!=INF)
                printf("dis[%c][%c]=%d, ", 'A'+i-1, 'A'+j-1, dis[i][j]);
                else
                printf("dis[%c][%c]=INF, ", 'A'+i-1, 'A'+j-1);
            }
            printf("\n");
        }
    }
} // namespace FLOYD




int main(void)
{
    // using namespace Dijkstra;
    // cin>>n>>m;
    // for(int i=1;i<=m;++i){
    //     ll u,v,w;
    //     cin>>u>>v>>w;
    //     g[u].push_back(edge(v,w));
    // }
    // dijkstra(1, n);
    // for(int i=1;i<=n;++i){
    //     if(dis[i]==INF)cout<<"dis["<<i<<"]=INF"<<endl;
    //     else cout<<"dis["<<i<<"]="<<dis[i]<<endl;
    // }
    // return 0;

    using namespace FLOYD;
    cin>>n>>m;
    init(n);
    for(int i=1;i<=m;++i){
        ll u,v,w;
        cin>>u>>v>>w;
        dis[u][v] = min(dis[u][v], w);    // 记得初始化边权
    }
    floyd(n);
    printDistance(n);
    return 0; 
}


/**
 * @file D.cpp
 * @author TJY
 * @brief 
 * 解法一： 采用拆点 + 分层图 跑最短路 一共需要 8*n 个顶点！！
 * @version 0.1
 * @date 2023-10-29
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll maxn = 1e6 + 5;
struct edge{
    int to;
    ll w;
    edge(int to, ll w):to(to),w(w){};
};
vector<edge> e[maxn];
ll dis[maxn];   // 单源最短路
int n,m,s;
struct node{
    ll dis;    // 存点u以及他的最短路长度
    int u;
    bool operator>(const node& a) const { return dis > a.dis; };  // 重载运算符
};
int  flag[maxn];   // 初始化为0，刚开始都放在集合T中
priority_queue<node,vector<node>,greater<node>> q;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;     // 初始化
    q.push({0,s});  
    while(!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if(flag[u]) continue;   // 点u已在集合S中了
        flag[u] = 1;   // 先放到集合S中
        // 再对相邻点进行松弛
        for(auto ed:e[u])
        {
            int v=ed.to;
            ll w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});   // 没变小千万不要放
            }
        }
    }
}
int main(void)
{
    scanf("%d %d",&n,&m);
    e[1].push_back(edge(n+1, 0));
    e[n].push_back(edge(2*n, 0));
    e[2*n+1].push_back(edge(3*n+1, 0));
    e[3*n].push_back(edge(4*n, 0));
    for(int i=2;i<=n-1;++i){
        ll val;
        scanf("%lld",&val);
        e[i].push_back(edge(n+i, val));
        e[2*n+i].push_back(edge(3*n+i, val));
        e[i].push_back(edge(3*n+i, 0));
    }
    for(int i=1;i<=m;++i){
        int u,v; ll w;
        scanf("%d %d %lld",&u,&v,&w);
        e[n+u].push_back(edge(v, w));
        e[n+v].push_back(edge(u, w));
        e[3*n+u].push_back(edge(2*n+v, w));
        e[3*n+v].push_back(edge(2*n+u, w));
    }
    dijkstra(1);
    printf("%lld\n", min(dis[4*n], dis[2*n]));    // 防止 hack
    return 0;
}

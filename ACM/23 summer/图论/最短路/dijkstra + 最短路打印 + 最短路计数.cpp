#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct edge{
    int to;
    ll w;
};
vector<edge> e[100005];
ll cnt[100005],pre[100005];   // 最短路计数 和 打印最短路
ll dis[100005];   // 单源最短路
int n,m,s;
struct node{
    ll dis;    // 存点u以及他的最短路长度
    int u;
    bool operator>(const node& a) const { return dis > a.dis; };  // 重载运算符
};
int  flag[100005];   // 初始化为0，刚开始都放在集合T中
priority_queue<node,vector<node>,greater<node>> q;
void dijkstra(int s)
{
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;     // 初始化
    cnt[s]=1;
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
            int v=ed.to,w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
                pre[v] = u;
                cnt[v] = cnt[u];
            }
            else if(dis[v]==dis[u]+w)
            {
                cnt[v] += cnt[u];
            }
        }
    }
}
void print_path(ll x)
{
    if(!x)
    {
        printf("0");
        return;
    }
    print_path(pre[x]);
    printf("->%lld",x);
    return;
}
int main(void)
{
    cin>>n>>m>>s;
    for(int i=1;i<=m;i++)
    {
        int u;
        edge temp;
        scanf("%d %d %lld",&u,&temp.to,&temp.w);
        e[u].push_back(temp);    // 重边无所谓，会在 **** 处取最小的边权值
    }
    dijkstra(s);
    for(ll i=1;i<=n;i++)
    {
        if(dis[i]<0x3f3f3f3f3f3f3f3f)    printf("dis[%lld]=%lld cnt[%lld]=%lld\n",i,dis[i],i,cnt[i]),print_path(i),printf("\n");   // dis[i]不是无穷，即可以到达该点
        else    printf("dis[%lld]=%d\n",i,INT_MAX);   // 无法到达该点
    }
    printf("\n");
    return 0;
}

/*
input:
5 15 5
2 5 181
1 5 98
4 2 49
3 2 262
4 3 26
2 4 192
5 1 221
2 2 254
4 4 233
1 5 44
5 4 67
4 2 214
1 1 47
1 1 118
5 4 3

input:
4 6 1
1 2 1
1 3 2
2 4 2
3 4 1
3 2 3
1 4 3
*/
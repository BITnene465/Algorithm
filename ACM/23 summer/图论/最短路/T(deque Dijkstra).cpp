// 模板 //
// Dijkstra 算法 优先队列优化，或二叉树优化 //
// 可以优化的理由是： 搜索dis最小的点时，可以二分 //
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct edge{
    int to;
    ll w;
};
vector<edge> e[100005];
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
                q.push({dis[v],v});   // 没变小千万不要放
            }
        }
    }
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
    for(int i=1;i<=n;i++)
    {
        if(dis[i]<0x3f3f3f3f3f3f3f3f)    printf("%lld ",dis[i]);   // dis[i]不是无穷，即可以到达该点
        else    printf("%d ",INT_MAX);   // 无法到达该点
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

output:
221 52 29 3 0 
*/
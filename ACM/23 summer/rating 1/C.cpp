// 最短路问题 虚拟顶点S,T S向A中所有点连一条0边 B中所有点向T中连一条0边 以S为源点跑最短路，dis_T即为答案 //
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int A[100005],B[100005],n,m,na,nb,dis[100005];
struct edge{
    int to;
    int w;
};
vector<edge> e[100005];
struct node{
    int dis;
    int u;
    bool operator>(const node& a)const {return dis > a.dis;};
};
priority_queue<node,vector<node>,greater<node>>q;
int flag[100005];
void dijkstra(int s)
{
    for(int i=1;i<=n+2;i++)    // 此处的n+2 ,一定要初始化
        dis[i] = INF;
    dis[s] = 0;
    q.push({0,s});
    while(!q.empty())
    {   
        int u=q.top().u;
        q.pop();
        if(flag[u]) continue;
        flag[u] = 1;
        for(auto ed:e[u])
        {
            int v=ed.to,w=ed.w;
            if(dis[v]>w+dis[u])
            {
                dis[v] = dis[u] + w;
                q.push({dis[v],v});
            }
        }
    }
    return;
}
int main(void)
{
    cin>>n>>m;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    cin>>na>>nb;
    for(int i=1;i<=na;i++)
    {
        scanf("%d",A+i);
    }
    for(int i=1;i<=nb;i++)
    {
        scanf("%d",B+i);
    }
    // 虚拟顶点s向所有A中的顶点连接一条0权边(有向无向均可)
    for(int i=1;i<=na;i++)
    {
        int u = A[i];
        e[n+1].push_back({u,0});
    }
    for(int i=1;i<=nb;i++)
    {
        int u = B[i];
        e[u].push_back({n+2,0});
    }
    dijkstra(n+1);
    // 输出最短路
    int ans = dis[n+2];
    printf("%d\n",ans);
    return 0;
}
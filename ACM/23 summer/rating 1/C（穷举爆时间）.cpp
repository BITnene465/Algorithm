#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m,na,nb;
int A[100005],B[100005];
int dis[100005];
struct edge{
    int to;
    int w;
};
struct node{
    int dis;    // 存点u以及他的最短路长度
    int u;
    bool operator>(const node& a) const { return dis > a.dis; };  // 重载运算符
};
vector<edge> e[100005];
priority_queue<node,vector<node>,greater<node>> q;
int flag[100005];    // 初始化为false，起初全在T集合中
void dijkstra(int s)
{
    for(int i=1;i<=n;i++)
        dis[i]=INF,flag[i]=0;
    dis[s] = 0;     // 初始化
    q.push({0,s});  
    while(!q.empty())
    {
        int u = q.top().u;
        q.pop();
        if(flag[u]) continue;   // 点u已在集合S中了
        flag[u] = true;   // 先放到集合S中
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    //读入 A B
    cin>>na>>nb;
    for(int i=1;i<=na;i++)
        scanf("%d",A+i);
    for(int i=1;i<=nb;i++)
        scanf("%d",B+i);
    //
    int ans = INF;
    for(int i=1;i<=na;i++)
    {
        int s=A[i];
        dijkstra(s);
        for(int j=1;j<=nb;j++)
        {
            int v = B[j];
            if(dis[v]<ans)  ans = dis[v];
        }
    }
    printf("%d\n",ans);
    return 0;
}
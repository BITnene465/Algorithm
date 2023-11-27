#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int INF=0x3f3f3f3f;
struct edge{
    int v,w;
};
vector<edge> e[maxn];
int n,m,k,s,t,dis[maxn];
priority_queue<pair<int,int>> q;   // pair的比较方式：先比第一个，相等再比第二个  ->  优先队列默认为  //
int flag[maxn];
void dijkstra(int s)
{
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    q.push(make_pair(0,s));
    while(!q.empty())
    {
        int u = q.top().second;
        q.pop();
        if(flag[u]) continue;
        flag[u] = 1;
        for(auto ed:e[u])
        {
            int v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
}
int main(void)
{
    cin>>n>>m>>k;
    cin>>s>>t;
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        for(int j=0;j<=k;j++)  // 有k+1层
        {
            e[u+j*n].push_back({v+j*n,w});
            e[v+j*n].push_back({u+j*n,w});    // 重边无所谓
            if(j<=k-1)
            {
                e[u+j*n].push_back({v+(j+1)*n,0});
                e[v+j*n].push_back({u+(j+1)*n,0});   // 指向下一层的有向边
            }
        }
    }
    // 预防那组hack数据 , 大概是s t相邻，边权为1，k为偶数
    for(int i=1;i<=k;i++)
        e[t+(i-1)*n].push_back({t+i*n,0});
    dijkstra(s);
    printf("%d\n",dis[t+n*k]);
    return 0;
}
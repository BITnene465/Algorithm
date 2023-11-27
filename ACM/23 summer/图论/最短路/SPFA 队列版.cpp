#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5+5;
struct edge{
    int v,w;
};
vector<edge> e[maxn];
int n,m,dis[maxn],vis[maxn],cnt[maxn];
queue<int> q;
bool spfa(int n,int s)    // n个点，s为源点
{// 在无负环的情况下，最短路最长为n-1
    memset(dis,0x3f,sizeof(dis));
    dis[s]=0,vis[s]=1,cnt[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        vis[u]=0;    // u不在队列里了
        for(auto ed:e[u])
        {
            int v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(!vis[v]) q.push(v),dis[v]=dis[u]+w;
                if(cnt[v]>=n)   return true;   // 说明有负环，没必要计算下去了，直接退出函数
            }
        }
    }
    return false;   // 没有负环
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
    if(spfa(n,1))    printf("计算时出现负环\n");
    for(int i=1;i<=n;i++)
        printf("dis[%d]=%d\n",i,dis[i]);
    return 0;
}


/*
input:
6 10
1 2 3
2 3 4
2 5 1
2 6 3
3 4 6
3 5 3
3 6 2
4 5 4
4 6 10
5 6 6

input:
3 3
1 2 3
1 3 -1
2 3 2

input:
3 3
1 2 3
1 3 1
2 3 1
*/
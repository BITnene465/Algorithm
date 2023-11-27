#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
const int INF = 0x3f3f3f3f;
struct edge{
    int v;
    int w;
};
vector<edge> e[maxn];
int n,m;
int dis[maxn];
bool bellmanford(int n,int s)    // n个顶点，s为源点
{
    memset(dis,63,sizeof(dis));
    dis[s]=0;
    bool flag;
    for(int i=1;i<=n;i++)    // 最多进行n-1次,如果第n次还可以松弛，那么就是有负环
    {
        flag = false;    // 记录是否有松弛
        for(int u=1;u<=n;u++)
        {
            if(dis[u]==INF) continue;    // 如果无穷大，那么无法去松弛别人
            for(auto ed:e[u])
            {
                int v=ed.v,w=ed.w;
                if(dis[v]>dis[u]+w)
                {
                    flag = true;
                    dis[v] = dis[u]+w;
                }
            }
        }
        if(!flag)   break;   // 没有松弛了，可以退出
    }
    return flag;
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
    if(bellmanford(n,1))    printf("计算时出现负环\n");
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
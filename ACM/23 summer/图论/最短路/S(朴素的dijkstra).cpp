#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct edge{
    int to;
    ll w;
};
vector<edge> e[10001];
ll dis[10001];   // 单源最短路
int n,m,s;
void dij(int s)
{
    bool flag[10001];   // 用于实现集合 S T 的划分，初始化为 false，即全在集合T中
    memset(dis,0x3f,sizeof(dis));
    dis[s] = 0;   // 初始化dis数组
    for(int k=1;k<=n;k++)    // 共有n轮，每次找到不在S集合中的点中dis最小的点(不与集合S相邻，那么就是未初始化，不可能dis最小），将其放入S中并松弛其他点
    {
        int t=0;
        ll mind = 0x3f3f3f3f3f3f3f3f;
        for(int i=1;i<=n;i++)
            if(!flag[i]&&dis[i]<mind)  t=i,mind=dis[i];    // 如果（不在S中 && （t还么赋值 || i的dis值比t更小） 那么 t = i
        flag[t] = true;   // 标记t在S集合中
        for(auto ne:e[t])
        {
            int v = ne.to;
            ll w=ne.w;
            dis[v] = min(dis[v],dis[t]+w);  // ****
        }
    }
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
    dij(s);
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
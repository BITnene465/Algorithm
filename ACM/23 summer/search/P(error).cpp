// 旅行计划 //
// 稀疏图，使用领接表存图 //
// 若x在y东面，则x->y，然后理解为从点i 出发 ， 求最长路径 //
// 由题目的定义可知这是一个 DAG //

// 理解错了，此程序可求最短路的最大值(利用BFS特性) ， 而非题目要求的最长路的最大值 //

#include<bits/stdc++.h>
using namespace std;
int n,m;   // n个点，m条边
int ans;
int vis[100005];
int step[100005];
vector<int> g[100005];
queue<int> q;
void bfs(int u)
{
    memset(vis,0,sizeof(int)*(n+1));  // 初始化vis数组
    q.push(u);
    step[u] = 1;    // 初始化
    vis[u] = 1;
    while(!q.empty())
    {
        u = q.front();
        q.pop();
        ans = step[u];  // 出队时更新ans
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                q.push(v);
                step[v] = step[u]+1;
                vis[v] = 1;
            }
        }
    }
}
int main(void)
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        g[v].push_back(u);    // v->u
    }
    for(int i=1;i<=n;i++)
    {
        bfs(i);
        printf("%d\n",ans);
    }
    return 0;
}
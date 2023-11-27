// 拓扑排序，模板题 //
#include<bits/stdc++.h>
using namespace std;
int in[101];  // 描述入度
int n;
int a[101];  // 用来存拓扑序
vector<int> g[101];
bool bfs()
{
    int tot = 0;
    queue<int> q;
    for(int u=1;u<=n;u++)
        if(!in[u])  q.push(u);   // 入度为0的点入队
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        a[++tot] = u;  // 一般以出队序为拓扑序
        for(auto v:g[u])
        {
            in[v]--;
            if(!in[v])  q.push(v);
        }
    }
    // 如果一定为DAG，则下面的代码不需要
    // 用于判定是否是 DAG
    if(tot==n)
        return true;   // 是DAG
    else    return false;   // 不是DAG
}
int main(void)
{
    cin>>n;
    for(int u=1;u<=n;u++)
    {
        int v;
        while(1)
        {
            scanf("%d",&v);
            if(v==0)   break;
            g[u].push_back(v);
            in[v]++;
        }
    }
    //
    bfs();
    for(int i=1;i<=n;i++)
        printf("%d%c",a[i],(i==n)?'\n':' ');
    return 0;
}
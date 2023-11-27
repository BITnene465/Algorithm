#include<bits/stdc++.h>
using namespace std;
int dis[31];
vector<int> node[31];
int vis[31];
int vis2[31][31];
queue<int> q;
int n;  //n个点
void bfs(int x)    // 时间复杂度O(n)
{
    q.push(x);
    vis[x] = 1;
    dis[x] = 0;
    while(!q.empty())
    {
        int now = q.front();
        for(auto to:node[now])
        {
            if(!vis[to])
            {
                q.push(to);
                vis[to] = 1;
                dis[to] = dis[now]+1;
            }
        }
        q.pop();
    }
    return;
}
void dfs(int x,int l)    // 时间复杂度很大，有很多重复搜索，要搜遍每一条路径
{
    if(l<dis[x])    dis[x]=l;  //更新距离
    for(auto to:node[x])
    {
        if(!vis2[x][to]&&!vis2[to][x])
        {
            vis2[x][to]=vis2[to][x]=1;   // 为了不走回头路
            dfs(to,l+1);    // 距离要更新
            vis2[x][to]=vis2[to][x]=0;   // 为了遍历所有路径，所以要复原
        }
    }
    return;
}
int main(void)
{
    int a,b;
    cin>>n;
    while(1)
    {
        scanf("%d %d",&a,&b);
        if(a==0&&b==0)  break;
        node[a].push_back(b);
        node[b].push_back(a);
    }
    memset(dis,0,sizeof(dis));
    memset(vis,0,sizeof(vis));
    bfs(1);
    cout<<"BFS"<<endl;
    for(int i=1;i<=n;i++)   
        cout<<"dis["<<i<<"]="<<dis[i]<<endl;
    memset(dis,127,sizeof(dis));    // 可以赋值很大的数，memset函数是对每一个字节操作
    memset(vis2,0,sizeof(vis2));
    dfs(1,0);
    cout<<"DFS"<<endl;
    for(int i=1;i<=n;i++)   
        cout<<"dis["<<i<<"]="<<dis[i]<<endl;
    return 0;
}

/*
sample:
11
1 2
1 8
1 9
2 3
2 5
3 4
4 5
5 6
6 7
8 9
9 10
10 11
0 0
*/
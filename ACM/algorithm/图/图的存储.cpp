// 图的存储及其DFS //
#include<iostream>
#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<vector>
#include<queue>
typedef long long ll;
typedef double db;
using namespace std;
int m,n;    // m边，n点
vector<int> a[10];   // 采用邻接表方式存储图 //
queue<int> q;    // 队列用于实现bfs算法 //
bool vis[10];    // visit数组，用于记录被访问状态 //

int dis[10];

void dfs(int num)   // dfs遍历全图：函数递归//
{
    vis[num] = 1;
    for(int i=0;i<a[num].size();i++)
    {
        if(!vis[a[num][i]])
        {
            dfs(a[num][i]);   // 递归，对下一个节点dfs
        }
    }
    return;
}
void bfs(int st)  // 采用bfs遍历全图：循环加队列 //
{
    q.push(st);    // 起点入队列 
    vis[st] = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(auto to:a[now])
        {
            if(!vis[to])
            {
                q.push(to);
                vis[to] = 1;
            }
        }
    }
    return;
}

void bfs2(int st)  // 采用bfs模板，bfs2测量所有点到st的最小距离 //
{
    q.push(st); 
    memset(dis,0x3f,sizeof(dis));     //  包含于string.h  对dis进行初始化，元素无穷大 //   
    vis[st] = 1;
    dis[st] = 0;
    int d = 1;
    while(!q.empty())
    {
        int now = q.front();
        q.pop();
        for(auto to:a[now])
        {
            if(!vis[to])
            {
                dis[to] = min(dis[to],dis[now]+1);
                q.push(to);
                vis[to] = 1;
            }
        }
        ++d;
    }
    return;
}

int main()
{
    cin>>n>>m;
    int u,v;
    for(int i =1;i<=m;i++)    // 每次接受一条边的信息
    {
        scanf("%d %d",&u,&v);
        a[u].push_back(v);
        a[v].push_back(u);
    }
    //  dfs(1); //
    //  bfs(1); //
    bfs2(1);
    for(int i=1;i<=n;i++)
        printf("%d %c",vis[i],(i==n)?'\n':' ');
    for(int i=1;i<=n;i++)
        printf("%d %c",dis[i],(i==n)?'\n':' ');
    return 0;
}

/*exmple:
input:
7 6
1 2
2 4
1 3
2 5
3 7
3 6

output:1  1  1  1  1  1  1
*/
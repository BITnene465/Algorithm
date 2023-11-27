#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n;
int fa[maxn],dep[maxn];
vector<int> tr[maxn];
void add_edge(int u,int v)
{
    tr[u].push_back(v);
    tr[v].push_back(u);
}
void dfs(int now)
{
    for(auto v:tr[now])
    {
        if(fa[now]!=v)
        {
            fa[v]=now;
            dfs(v);
        }
    }
    return;
}
void bfs(int rt)   // 预处理dep,根节点的深度为0, O(n)
{
    queue<int> q;
    q.push(rt);
    dep[rt]=0;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v:tr[u])
        {
            if(v!=fa[u])
            {
                q.push(v);
                dep[v]=dep[u]+1;
            }
        }
    }
    return;
}
// 朴素的lca
int lca(int a,int b)  
{
    if(dep[a]<dep[b])   swap(a,b);
    while(dep[a]>dep[b])    a=fa[a];  // 直到dep[a]=dep[b]
    while(a!=b){a=fa[a];b=fa[b];}
    return a;
}
// 倍增算法处理lca
int lca2(int a,int b)
{

}
// 
int main(void)
{
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;
        cin>>u>>v;
        add_edge(u,v);
    }
    // 转换为有根树 //
    fa[1]=0;
    dfs(1);
    // 预处理dep
    bfs(1);
    for(int i=1;i<=n;++i)
        printf("dep[%d]=%d\n",i,dep[i]);
    //
    int a,b;
    while(cin>>a>>b)
        printf("%d和%d的最近公共祖先是%d\n",a,b,lca(a,b));
    return 0;
}
/*
input:
10
2 5
2 4
3 6
6 10
6 9
5 7
5 8
1 2
1 3
*/
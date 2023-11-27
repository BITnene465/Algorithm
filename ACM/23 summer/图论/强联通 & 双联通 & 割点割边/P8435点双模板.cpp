// 模板点双 已知一个无向图， 求所有点双//
#include<bits/stdc++.h>
using namespace std;
#define MAXN 500005
#define MAXM 4000005
int n,m;
int vcc_cnt,cnt,top,dfn[MAXN],low[MAXN],stk[MAXN],e[MAXM<<1],deg[MAXN];
vector<int> G[MAXN],vcc[MAXN];
void _getvcc(int u,int fa)
{
    int son=0;
    low[u]=dfn[u]=++cnt;stk[++top]=u;
    for(auto v:G[u])
    {
        if(!dfn[v])   // 树边
        {
            ++son;
            _getvcc(v,u);
            low[u]=min(low[u],low[v]);
            if(low[v]>=dfn[u])
            {
                ++vcc_cnt;
                while(stk[top+1]!=v)vcc[vcc_cnt].push_back(stk[top--]);  //把子树出栈
                vcc[vcc_cnt].push_back(u);  // 把树根/割点丢进去
            }
        }
        else if(v!=fa)  low[u]=min(low[u],dfn[v]);
    }
    if(fa==0&&son==0)vcc[++vcc_cnt].push_back(u);   //特判孤立点
}
void getvcc(int n)
{
    for(int i=1;i<=n;++i)if(!dfn[i])top=0,_getvcc(i,0);  // 0作为根节点的父亲
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);G[v].push_back(u);
    }
    getvcc(n);    // 在DFS树上操作，本质还是Tarjan算法
    cout<<vcc_cnt<<endl;
    for(int i=1;i<=vcc_cnt;++i)
    {
        cout<<vcc[i].size()<<" ";
        for(auto it:vcc[i])cout<<it<<" ";
        cout<<endl;
    }
    return 0;
}
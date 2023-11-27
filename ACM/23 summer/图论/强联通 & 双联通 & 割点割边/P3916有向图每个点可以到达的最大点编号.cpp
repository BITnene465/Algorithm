// 板子题，求一个有向图中每个点能到达的最大点 //
// 方法可能复杂了 //
// 有十分简单的方法 -> 反向建图 + Dfs //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
int stk[MAXN],top,cnt,id[MAXN],id_cnt,low[MAXN],dfn[MAXN],ma[MAXN],n,m,dp[MAXN];
int indeg[MAXN];
queue<int> Q;
bool instk[MAXN];
vector<int> G[MAXN];
vector<int> G2[MAXN];  //缩点后建个反图，整个活
void _Tarjan(int u)
{
    dfn[u]=low[u]=++cnt,stk[++top]=u,instk[u]=1;
    for(auto v:G[u])
    {
        if(!dfn[v])_Tarjan(v),low[u]=min(low[u],low[v]);
        else if(instk[v])low[u]=min(low[u],dfn[v]);
    }
    if(dfn[u]==low[u])
    {
        id_cnt++;
        do{
            id[stk[top]]=id_cnt,instk[stk[top]]=0,ma[id_cnt]=max(ma[id_cnt],stk[top]);
        }while(stk[top--]!=u);
    }
}
void Tarjan(int n)
{
    for(int i=1;i<=n;++i)
        if(!dfn[i]) _Tarjan(i);
}
void Topu()
{
    for(int i=1;i<=id_cnt;++i)
    {
        dp[i]=ma[i];
        if(!indeg[i])Q.push(i);
    }
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(auto v:G2[u])
        {
            dp[v]=max(dp[v],dp[u]);
            if(!(--indeg[v]))Q.push(v);
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
    }
    Tarjan(n);  //缩点
    for(int u=1;u<=n;++u)
    {
        for(auto v:G[u])if(id[u]!=id[v])G2[id[v]].push_back(id[u]),indeg[id[u]]++;
    }
    Topu();
    for(int i=1;i<=n;++i)cout<<dp[id[i]]<<" ";
    cout<<endl;
    return 0;
}
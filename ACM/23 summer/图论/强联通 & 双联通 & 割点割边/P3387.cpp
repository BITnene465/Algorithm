// 缩点模板 //
#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
vector<int> g[MAXN];
int n,m,a[MAXN];
int stk[MAXN],top,cnt,low[MAXN],dfn[MAXN];
bool instk[MAXN];
int id[MAXN],id_cnt,val[MAXN];  // val为每个缩点的点全权
void Tarjan(int u)
{
    instk[u]=1,stk[++top]=u,dfn[u]=low[u]=++cnt;
    for(auto v:g[u])
    {
        if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
        else if(instk[v])   low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++id_cnt;
        while(stk[top]!=u){id[stk[top]]=id_cnt;val[id_cnt]+=a[stk[top]];instk[stk[top--]]=0;}
        id[u]=id_cnt;
        instk[u]=0;
        val[id_cnt]+=a[u];
        --top;
    }
}
inline void adde(int u,int v){g[u].push_back(v);}
set<int> gg[MAXN];   // 用set存缩点图
int f[MAXN];
int Dfs(int u)
{
    if(f[u])return f[u];
    int res=0;
    for(int v:gg[u])
        res=max(res,Dfs(v));
    return f[u]=res+val[u];
}  
int main(void)  
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adde(u,v);
    }
    // Tarjan
    for(int i=1;i<=n;++i)
        if(!dfn[i])Tarjan(i);
    // 建立缩点图
    for(int i=1;i<=n;++i)
        for(int j:g[i])
            if(id[i]!=id[j])gg[id[i]].insert(id[j]);
    // 建立超级源点
    for(int i=1;i<=id_cnt;++i)
        gg[id_cnt+1].insert(i);
    // 跑DAG上的DP
    cout<<Dfs(id_cnt+1)<<endl;
    return 0;
}
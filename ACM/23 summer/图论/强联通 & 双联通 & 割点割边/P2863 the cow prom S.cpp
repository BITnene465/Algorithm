// 板子题，求一个有向图的点数大于一的强联通分支的数量 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 10005
int stk[MAXN],top,cnt,id[MAXN],id_cnt,low[MAXN],dfn[MAXN],siz[MAXN],n,m,ans;
bool instk[MAXN];
vector<int> G[MAXN];
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
            id[stk[top]]=id_cnt,instk[stk[top]]=0,siz[id_cnt]++;
        }while(stk[top--]!=u);
    }
}
void Tarjan(int n)
{
    for(int i=1;i<=n;++i)
        if(!dfn[i]) _Tarjan(i);
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
    Tarjan(n);
    for(int i=1;i<=id_cnt;++i)if(siz[i]>1)ans++;
    cout<<ans<<endl;
    return 0;
}
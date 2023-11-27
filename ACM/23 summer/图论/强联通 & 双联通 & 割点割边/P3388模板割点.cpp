// 模板割点 已知一个无向图，求所有割点//
#include<bits/stdc++.h>
using namespace std;
#define MAXN 20005
vector<int> G[MAXN];
int n,m,ans,cnt,dfn[MAXN],low[MAXN];
bool tag[MAXN];
void _Tarjan(int u,int rt)
{
    int son=0;
    low[u]=dfn[u]=++cnt;
    for(auto v:G[u])
    {
        if(!dfn[v])
        {
            _Tarjan(v,rt);
            low[u]=min(low[u],low[v]);
            ++son;
            if(low[v]>=dfn[u]&&u!=rt)tag[u]=1;   // 可能会被多次赋值，计数时请注意
        }
        else    low[u]=min(low[u],dfn[v]);
    }
    if(u==rt&&son>1)tag[u]=1;   // 可能会被多次赋值，计数时请注意
}
void Tarjan(int n)
{
    for(int i=1;i<=n;++i)if(!dfn[i])_Tarjan(i,i);
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
    Tarjan(n);
    ans=0;
    for(int i=1;i<=n;++i)if(tag[i])ans++;
    cout<<ans<<endl;
    for(int i=1;i<=n;++i)if(tag[i])cout<<i<<" ";
    cout<<endl;
    return 0;
}


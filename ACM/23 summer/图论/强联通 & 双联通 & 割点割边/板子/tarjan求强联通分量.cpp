#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
vector<int> G[MAXN];
int stk[MAXN],top,cnt,scnt,low[MAXN],dfn[MAXN];
bool instk[MAXN];
vector<int> scc[MAXN];
void Tarjan(int u)
{
    instk[u]=1,stk[++top]=u,dfn[u]=low[u]=++cnt;
    for(auto v:G[u])
    {
        if(!dfn[v]) Tarjan(v),low[u]=min(low[u],low[v]);
        else if(instk[v])   low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++scnt;
        while(stk[top]!=u){scc[scnt].push_back(stk[top]);instk[stk[top--]]=0;}
        scc[scnt].push_back(u),instk[u]=0,--top;
    }
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    return 0;
}
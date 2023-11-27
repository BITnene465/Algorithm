// P2341 明星奶牛 //
// 缩点：ans=唯一的出度为0强联通分量包含点数的大小，如果有两个及以上，那么ans=0 //
#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
vector<int> g[MAXN];
int stk[MAXN],top,cnt,low[MAXN],dfn[MAXN];
bool instk[MAXN];
int id[MAXN],id_cnt,siz[MAXN];// id记录颜色id，siz记录该颜色的点数
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
        while(stk[top]!=u){id[stk[top]]=id_cnt;instk[stk[top--]]=0;siz[id_cnt]++;}
        id[u]=id_cnt,instk[u]=0,siz[id_cnt]++,--top;
    }
}
void adde(int u,int v)
{
    g[u].push_back(v);
}
int n,m,outdeg[MAXN]; // outdeg记录每个强联通分量的出度
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adde(u,v);
    }
    // 使用Tarjan
    for(int i=1;i<=n;++i)
        if(!dfn[i])Tarjan(i);
    //
    for(int u=1;u<=n;++u)
    {
        for(int v:g[u])
        {
            if(id[v]!=id[u])
            outdeg[id[u]]++;
        }
    }
    int flag=0,ans;
    for(int i=1;i<=id_cnt;++i)
    {
        if(!outdeg[i])ans=siz[i],flag++;
        if(flag==2){ans=0;break;}
    }
    cout<<ans<<endl;
    return 0;
}
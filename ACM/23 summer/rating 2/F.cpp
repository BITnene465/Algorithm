#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,m;
ll ans,ans2;
struct edge{
    int u;
    ll w;
};
int vis[maxn];
vector<edge> e[maxn];
void dfs(int s,ll sum,int num)
{
    if(num==n)
    {
        if(sum<ans)ans=sum;
        return;
    }
    for(auto ed:e[s])
    {
        int v=ed.u;
        if(vis[v])continue;
        ll w=ed.w;
        vis[v]=1;
        dfs(v,sum+w,num+1);
        vis[v]=0;
    }
    return;
}
void dfs2(int s,ll sum,int num)
{
    if(num==n)
    {
        if(sum!=ans&&sum<ans2)ans2=sum;
        return;
    }
    for(auto ed:e[s])
    {
        int v=ed.u;
        if(vis[v])continue;
        ll w=ed.w;
        vis[v]=1;
        dfs(v,sum+w,num+1);
        vis[v]=0;
    }
    return;
}
int main(void)
{
    scanf("%d %d",&n,&m);
    int u,v;ll w;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d %lld",&u,&v,&w);
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    ans=LONG_LONG_MAX;
    ans2=LONG_LONG_MAX;
    vis[1]=1;
    dfs(1,0,1);
    dfs2(1,0,1);
    vis[1]=0;
    cout<<ans<<endl;
    cout<<ans2<<endl;
    return 0;
}
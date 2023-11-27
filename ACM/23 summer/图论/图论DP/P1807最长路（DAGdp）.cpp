#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1505;
const ll INF=-0x3f3f3f3f3f3f3f3f;
struct edge{
    ll v;
    ll w;
};
vector<edge> e[maxn];
ll n,m,dp[maxn];
inline void adde(ll u,ll v,ll w){e[u].push_back({v,w});}
ll dfs(ll s)
{
    if(dp[s]!=INF)return dp[s];
    if(s==n)    return dp[s]=0;
    ll ans=INF;
    for(auto ed:e[s])
    {
        ll v=ed.v,w=ed.w;
        if(dfs(v)==INF)continue;
        ans=max(ans,w+dfs(v));
    }
    return dp[s]=ans;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    ll u,v,w;
    for(ll i=1;i<=m;++i)
    {
        cin>>u>>v>>w;
        adde(u,v,w);
    }
    for(ll i=1;i<=n;++i)dp[i]=INF;
    if(dfs(1)==INF)cout<<-1<<endl;
    else    cout<<dfs(1)<<endl;
    return 0;
}
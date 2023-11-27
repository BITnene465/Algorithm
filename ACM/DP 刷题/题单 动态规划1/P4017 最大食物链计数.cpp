// 一道DAG dp //
// 也可以反向建图，然后用拓扑序进行更新 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=80112002;
const int maxn=5005;
vector<int> G[maxn];
ll dp[maxn],n,m,outdeg[maxn],indeg[maxn];
void adde(int u,int v)
{
    G[u].push_back(v);     // 被吃者指向吃者
}
ll dfs(int s)
{
    if(dp[s])return dp[s];
    ll res=0;
    for(auto v:G[s])res=(res+dfs(v))%mod;
    return dp[s]=res;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adde(u,v);
        outdeg[u]++;indeg[v]++;
    }
    for(int i=1;i<=n;++i)if(!outdeg[i])dp[i]=1;   // 初始化
    ll ans=0;
    for(int i=1;i<=n;++i)if(!indeg[i])ans=(ans+dfs(i))%mod;
    cout<<ans<<endl;
    return 0;
}
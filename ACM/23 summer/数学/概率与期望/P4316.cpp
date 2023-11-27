// P4316 ÂÌ¶¹ÍÜµÄ¹éËÞ //
// DAG DP //
#include<bits/stdc++.h>
using namespace std;
typedef double D;
typedef long long ll;
const ll maxn=1e5+5;
ll n,m;
D ex[maxn];
struct edge{
    ll v;
    ll w;
};
vector<edge> e[maxn];
D dfs(ll s)
{
    if(ex[s]>0) return ex[s];
    if(s==n)    return 0.;
    D p=1.0/e[s].size();
    D ans=0.;
    for(auto ed:e[s])
    {
        ll v=ed.v,w=ed.w;
        ans+=p*((D)w+dfs(v));
    }
    return ex[s]=ans;
}
int main(void)
{
    scanf("%lld %lld",&n,&m);
    ll u,v,w;
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld %lld %lld",&u,&v,&w);
        e[u].push_back({v,w});
    }
    printf("%.2lf\n",dfs(1));
    return 0;
}
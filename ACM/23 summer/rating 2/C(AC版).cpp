// 树上集合点  ->  LCA //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5e5+5;
ll n,q,rt;
vector<ll> tr[maxn];
ll fa[maxn],dep[maxn];
void adde(int u,int v)
{
    tr[u].push_back(v);
    tr[v].push_back(u);
}
void dfs(ll now)
{
    for(auto v:tr[now])
    {
        if(v!=fa[now])
        {
            fa[v]=now;
            dfs(v);
        }
    }
    return;
}
void bfs(int rt)
{
    queue<ll> q;
    q.push(rt);
    dep[rt]=0;
    while(!q.empty())
    {
        ll u=q.front();q.pop();
        for(auto v:tr[u])
        {
            if(v!=fa[u])
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return;
}
ll lca(ll a,ll b)
{
    if(dep[a]<dep[b])   swap(a,b);
    while(dep[a]>dep[b])    a=fa[a];
    while(a!=b){a=fa[a];b=fa[b];}
    return a;
}
int main(void)
{
    scanf("%lld %lld",&n,&q);
    for(ll i=1;i<=n-1;i++)
    {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        adde(u,v);
    }
    // 转换为有根树
    rt=1;
    fa[rt]=0;
    dfs(rt);
    // 预处理dep
    bfs(rt);
    // 询问+LCA
    while(q--)
    {
        ll a,b,c;
        scanf("%lld %lld %lld",&a,&b,&c);
        // 三个点，两两LCA，必有至少两个重合,若重合，选第三点;若三点重合，选该点 //
        // 也可以直接选深度最深的那个LCA //
        ll ab=lca(a,b),bc=lca(b,c),ca=lca(c,a);
        ll p=ab;
        if(dep[bc]>dep[p])  p=bc;
        if(dep[ca]>dep[p])  p=ca;
        ll ans=3*dep[p]+dep[a]+dep[b]+dep[c]-2*dep[lca(p,a)]-2*dep[lca(p,b)]-2*dep[lca(p,c)];
        // print
        printf("%lld %lld\n",p,ans);
    }
    return 0;
}
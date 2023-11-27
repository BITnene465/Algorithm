// spfa已经死了 TLE 90pt//
// 差分约束 + 求所有可行解中可行解最小值>=1,且可行解之和最小的可行解 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
typedef long long ll;
ll x,a,b,n,k;
struct edge{
    ll v;
    ll w;
    edge(ll v,ll w):v(v),w(w){}
};
vector<edge> G[MAXN];
queue<ll> Q;
ll cnt[MAXN];ll dis[MAXN];bool inque[MAXN];
inline void add(ll u,ll v,ll w){G[u].push_back(edge(v,w));}
void adde(ll type,ll u,ll v)
{
    switch(type)
    {
        case 1:
        add(u,v,0);
        add(v,u,0);
        break;
        case 2:
        add(u,v,1);
        break;
        case 3:
        add(v,u,0);
        break;
        case 4:
        add(v,u,1);
        break;
        case 5:
        add(u,v,0);
        break;
    }
}
bool spfa(ll s)   // 跑最长路
{
    Q.push(s),inque[s]=1;
    dis[s]=1;
    while(!Q.empty())
    {
        ll u=Q.front();Q.pop();
        inque[u]=0;
        for(auto ed:G[u])
        {
            ll v=ed.v;ll w=ed.w;
            if(dis[v]<dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(!inque[v]){Q.push(v);inque[v]=1;}
                if(cnt[v]>=n+2)return true;    // 有负环
            }
        }
    }
    return false;
}
int main(void)
{
    scanf("%lld %lld",&n,&k);
    for(ll i=1;i<=k;++i)
    {
        scanf("%lld %lld %lld",&x,&a,&b);
        adde(x,a,b);
    }
    for(ll i=1;i<=n;++i)add(n+1,i,0);   //建立超级源点
    if(spfa(n+1))printf("-1\n");
    else
    {
        ll ans=0;
        for(ll i=1;i<=n;++i)ans+=dis[i];
        printf("%lld\n",ans);
    }
    return 0;
}
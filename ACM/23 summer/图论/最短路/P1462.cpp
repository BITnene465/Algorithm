// md 第一次看错题了 //
// 二分答案 + 修改版单源最短路 //  // 这种最大值的最小值的题一般都要二分 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e4+5;
const ll INF=0x3f3f3f3f;
struct edge{
    ll v;
    ll w;
};
vector<edge> e[maxn];
priority_queue<pair<int,int>> q;
ll n,m,b,dis[maxn],value[maxn];
int flag[maxn];
ll read()
{
    ll f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void init()
{
    for(ll i=1;i<=n;i++)
        dis[i]=INF,flag[i]=0;
}
bool Dijkstra(ll s,ll c)
{
    init();
    if(value[s]<=c)
    {
        dis[s]=0;
        q.push({0,s});
    }
    while(!q.empty())
    {
        ll u=q.top().second;
        q.pop();
        if(flag[u]) continue;
        flag[u]=1;
        for(auto ed:e[u])
        {
            ll v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w&&value[v]<=c)   // 禁用点权大于c的点
            {
                dis[v]=dis[u]+w;
                q.push(make_pair(-dis[v],v));
            }
        }
    }
    if(dis[n]>b)    return true;
    return false;
}
int main(void)
{
    ll r,l,mid;
    r=0;
    n=read(),m=read(),b=read();
    for(ll i=1;i<=n;i++)   value[i]=read(),r=max(r,value[i]);
    ll u,v,w;
    for(ll i=1;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        e[u].push_back({v,w});
        e[v].push_back({u,w});
    }
    // 二分模板
    l= max(value[1],value[n]);
    mid=r+l>>1;
    if(Dijkstra(1,r))
    {
        cout<<"AFK"<<endl;
        return 0;
    }
    while(l<=r)
    {
        if(Dijkstra(1,mid)) l=mid+1;
        else r=mid-1;
        mid=r+l>>1;
    }
    cout<<l<<endl;
    return 0;
}
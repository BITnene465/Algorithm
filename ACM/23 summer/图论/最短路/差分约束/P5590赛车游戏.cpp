// 关键在于想到差分约束建立模型 //
// n个点, 对于连边(i,j),1<=dis(j)-dis(i)<=9,如果有解,那么每条边w(i,j)=dis(j)-dis(i)即可 //
// 注意点1： 由于题目给的是有向边，所以要判断是否能够从1到n //
// 注意点2： 由于只对1->n路径中经过的边进行差分约束，如果对无用的边进行约束，那么会出错 //
// 为何可以这样建模？对于"有用"的点，每个点的dis值是唯一的 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
typedef pair<int,int> pii;
vector<pii> query;
struct edge
{
    int v,w;
    edge(int v,int w):v(v),w(w){};
};
vector<int> g1[MAXN];   // 原图,找1->n路径上的点
vector<int> gn[MAXN];   // 反向图
vector<edge> g[MAXN];   // 存差分约束的图
bool flag[MAXN],vis1[MAXN],visn[MAXN];   // 记录有用的点
int n,m,dis[MAXN],inque[MAXN],cnt[MAXN];   // spfa所需的数组
queue<int> Q;
void adde(int u,int v)
{
    g[u].push_back(edge(v,9));
    g[v].push_back(edge(u,-1));
}
inline void adde1(int u,int v)
{
    g1[u].push_back(v);
}
inline void adden(int u,int v)
{
    gn[v].push_back(u);
}
void Bfs1(int s)    // 1->n所有路径中经过的点
{
    Q.push(s);vis1[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(auto v:g1[u])
        {
            if(!vis1[v])Q.push(v),vis1[v]=1;
        }
    }
}
void Bfsn(int s)
{
    Q.push(s);visn[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();
        for(auto v:gn[u])
        {
            if(!visn[v])Q.push(v),visn[v]=1;
        }
    }
}
bool spfa(int s)
{
    memset(dis,63,sizeof(dis));
    dis[s]=0;Q.push(s);inque[s]=1;
    while(!Q.empty())
    {
        int u=Q.front();Q.pop();inque[u]=0;
        for(auto ed:g[u])
        {
            int v=ed.v,w=ed.w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=2*n)return 0;
                if(!inque[v])Q.push(v),inque[v]=1;
            }
        }
    }
    return 1;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        adde1(u,v);
        adden(u,v);
        query.push_back(make_pair(u,v));
    }
    Bfs1(1);
    if(!vis1[n])    // 判断能否到达n
    {
        cout<<-1<<endl;
        return 0;
    }
    Bfsn(n);
    for(int i=1;i<=n;++i)
        flag[i]=vis1[i]&visn[i];    // 找出所有有用的点
    // 有1->n的路径
    for(int i=0;i<=m-1;++i)
    {
        int u=query[i].first,v=query[i].second;
        if(flag[u]&&flag[v])adde(u,v);
    }
    if(!spfa(1))
    {
        cout<<-1<<endl;
        return 0;
    }
    cout<<n<<" "<<m<<endl;
    for(auto it:query)
    {
        int u=it.first,v=it.second;
        if(flag[u]&&flag[v])
        cout<<u<<" "<<v<<" "<<dis[v]-dis[u]<<endl;
        else   
        cout<<u<<" "<<v<<" "<<1<<endl;   // 1~9整数均可
    }
    return 0;
}
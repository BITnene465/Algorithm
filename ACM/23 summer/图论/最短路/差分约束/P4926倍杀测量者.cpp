// 二分答案 + 差分约束模型 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1005
const double eps=1e-6;
int n,s,t,o[MAXN],A[MAXN],B[MAXN],k[MAXN],C[MAXN],x[MAXN];
struct edge{
    int v;
    double w;
    edge(int v,double w):v(v),w(w){}
};
vector<edge> G[MAXN];
queue<int> Q;bool inque[MAXN];int cnt[MAXN];double dis[MAXN];
void reset()
{
    for(int i=1;i<=n+2;++i)G[i].clear();
    memset(inque,0,sizeof(inque));
    memset(cnt,0,sizeof(cnt));
    memset(dis,0x3f,sizeof(dis));
}
inline void adde(int u,int v,double w)
{
    G[u].push_back(edge(v,w));
}
void Build(double c)
{
    for(int i=1;i<=s;++i)
    {
        if(o[i]==1)adde(A[i],B[i],-log(k[i]-c));
        else adde(A[i],B[i],log(k[i]+c));
    }
    for(int i=1;i<=t;++i)
    {
        adde(n+1,C[i],log((double)x[i]));     // 虚拟顶点维护已知值
        adde(C[i],n+1,-log((double)x[i]));     
    }
    for(int i=1;i<=n+1;++i)   adde(n+2,i,0); // 超级源点求最短路
}
bool spfa(int s)
{
    Q.push(s);inque[s]=1;dis[s]=0;
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();inque[u]=0;
        for(auto ed:G[u])
        {
            int v=ed.v;double w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                cnt[v]=cnt[u]+1;
                if(!inque[v])Q.push(v),inque[v]=1;
                if(cnt[v]>=n+2)return true;   // 有负环,无解
            }
        }
    }
    return false;  // 无负环
}
bool check(double c)
{
    reset();
    Build(c);
    return spfa(n+2);
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>s>>t;
    for(int i=1;i<=s;++i)
        cin>>o[i]>>A[i]>>B[i]>>k[i];
    for(int i=1;i<=t;++i)
        cin>>C[i]>>x[i];
    double l=0.0,r=10.0;
    double mid;
    for(int i=1;i<=30;++i)
    {
        mid=(r+l)/2;
        if(check(mid))l=mid;
        else r=mid;
    }
    cout.precision(11);
    if(mid<eps)cout<<"-1"<<endl;
    else cout<<mid<<endl;
    return 0;
}
// 用Dfs爆搜足以算一百万年 //
// 采用Bfs 并构建图模型然后搜最短路即可 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int m,s,t,ans,dis[maxn];
bool vis[maxn];
vector<int> G[maxn];   // 存图
queue<int> q;
void Bfs()
{
    q.push(s);
    vis[s]=1;
    dis[s]=1;
    ans=-1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(auto v:G[u])
        {
            if(v==t){ans=dis[u]+2;return;}
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
                dis[v]=dis[u]+1;
            }
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>m;
    for(int i=1;i<=m;++i)
    {
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        G[a].push_back(d);
    }
    // 保证开始和结束都存在
    int a1,b1,c1,d1,a2,b2,c2,d2;
    cin>>a1>>b1>>c1>>d1;
    cin>>a2>>b2>>c2>>d2;
    if(a1==a2&&b1==b2&&c1==c2&&d1==d2){cout<<'1'<<endl;return 0;} // 特判1
    s=d1,t=a2;   // 设置起点和终点
    if(s==t){cout<<'2'<<endl;return 0;} // 特判2
    Bfs();
    cout<<ans<<endl;
    return 0;
}


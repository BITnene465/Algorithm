// 无向无权图 单源最短路 使用BFS //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
const int mod=100003;
int cnt[maxn],n,m,dis[maxn],vis[maxn];   // 顺便把最短路长度也算了,本题可以不算
vector<int> g[maxn];
queue<int> q;
set<int> st;   // 用来记录下一次要入队的点
// 不同于往常的bfs，这次按距离分层入队出队
void bfs(int s)
{
    dis[s]=0,cnt[s]=1,vis[s]=1;
    q.push(s);
    while(1)
    {
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v:g[u])
            {
                if(!vis[v])
                {
                    dis[v]=dis[u]+1;
                    cnt[v]=(cnt[v]+cnt[u])%mod;
                    st.insert(v);
                }
            }
        }
        if(st.empty())  break;
        for(auto v:st)
            vis[v]=1,q.push(v);
        st.clear();
    }
}
int main(void)
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    bfs(1);
    for(int i=1;i<=n;i++)
        printf("%d\n",cnt[i]);
    return 0;
}
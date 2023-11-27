// 字典树 + 贪心 //
// 最长异或路径 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct edge{
    int v,w;
    edge(){}
    edge(int v, int w):v(v),w(w){}
};
vector<edge> e[maxn];
bool vis[maxn];
int arr[maxn],n,ans;
queue<int> q;
// 预处理每个节点到根节点的路径异或和 //
void bfs(int rt)
{
    q.push(rt);
    arr[rt]=0;
    vis[rt]=true;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(auto ed:e[u])
        {
            int v=ed.v,w=ed.w;
            if(!vis[v])
            {
                arr[v]=arr[u]^w;
                q.push(v);
                vis[v]=true;
            }
        }
    }
    return;
}
void add_edge(int u,int v,int w)
{
    e[u].push_back(edge(v,w));
    e[v].push_back(edge(u,w));
}
// 0-1字典树 
int nex[3200005][2],cnt;
int find(int val)
{ 
    // 搜索可以和val异或得到的最大值 //
    int ans=0;
    int p=0;
    for(int i=(1<<30);i;i>>=1)
    {
        bool c=val&i;
        if(nex[p][!c])
        {//如果这一位可以进行异或就沿着这一条往下走
            ans+=i;
            p=nex[p][!c];
        }
        else p=nex[p][c];//否则就沿着另一条路往下走
    }
    return ans;
}
void insert(int val)
{
    // 插入
    int p=0;
    for(int i=(1<<30);i;i>>=1)
    {
        bool c=val&i;
        if(!nex[p][c])nex[p][c]=++cnt;
        p=nex[p][c];
    }
    return;
}
// 主函数
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);   // 不能混用scanf和cin!
    cin>>n;
    for(int i=1;i<=n-1;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        add_edge(u,v,w);
    }
    bfs(1);   // 预处理路径异或和
    // 字典树操作
    ans=0;
    for(int i=1;i<=n;++i)   // 建立字典树
        insert(arr[i]);
    for(int i=1;i<=n;++i)
        ans=max(ans,find(arr[i]));
    cout<<ans<<endl;
    return 0;
}
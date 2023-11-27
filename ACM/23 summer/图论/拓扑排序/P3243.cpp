// P3243 菜肴制作 //
// 反向建图 //
// 尽量保证编号小的菜肴在前面 ->  反图跑字典序最大拓扑排序 再倒过来 //
#include<bits/stdc++.h>
using namespace std;
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
const int maxn=1e5+5;
int n,m,t,in[maxn],ans[maxn];
vector<int> g[maxn];
priority_queue<int> q;
bool bfs()
{
    int cur=0;
    for(int i=1;i<=n;i++)
        if(!in[i])  q.push(i);
    while(!q.empty())
    {
        int u=q.top();
        q.pop();
        ans[++cur]=u;
        for(auto v:g[u])
        {
            in[v]--;
            if(!in[v])  q.push(v);
        }
    }
    if(cur==n)  return true;
    else return false;
}
int main(void)
{
    t=read();
    while(t--)
    {
        n=read(),m=read();
        // init
        for(int i=1;i<=n;i++)
            in[i]=0,g[i].clear();
        // init_end
        int u,v;
        for(int i=1;i<=m;i++)
        {
            u=read(),v=read();
            g[v].push_back(u);   // 直接构建  反图
            in[u]++;
        }
        if(bfs())   
        {
            for(int i=n;i>=1;--i)
                printf("%d%c",ans[i],(i==1)?'\n':' ');
        }
        else printf("Impossible!\n");
    }
    return 0;
}

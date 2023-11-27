// Ä£°åÌâ£¬ÍØÆËÅÅĞò //
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
vector<int> g[maxn];
int n,m,in[maxn];
int ans[maxn];
bool bfs()
{
    queue<int> q;
    int cur=0;
    for(int i=1;i<=n;i++)
        if(!in[i])  q.push(i);
    while(!q.empty())
    {
        int u=q.front();
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
    n=read(),m=read();
    int u,v;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read();
        g[u].push_back(v);
        in[v]++;
    }
    if(bfs())   
    {
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[i],(i==n)?'\n':' ');
    }
    else printf("No solution\n");
    return 0;
}
// 食物链条数 单独的一种生物不算一条食物链//
// 由食物链的定义知 DAG //
// DAG DP & 记忆化搜索 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,m,out[maxn],in[maxn],f[maxn]; // f[i] 表示以i为起点的食物链个数
vector<int> g[maxn];
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int dfs(int s)
{
    if(f[s])    return f[s];
    int ans=0;
    for(auto v:g[s])
        ans+=dfs(v);
    return f[s]=ans;
}
int main(void)
{
    n=read(),m=read();
    int u,v;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read();
        g[u].push_back(v);
        out[u]++;
        in[v]++;
    }
    // init
    for(int i=1;i<=n;i++)
    {
        if(out[i]==0&&in[i]!=0)   f[i]=1;
        else if(out[i]!=0&&in[i]==0)   g[n+1].push_back(i); 
    }
    cout<<dfs(n+1)<<endl;
    return 0;
}

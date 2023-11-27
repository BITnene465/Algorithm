// P1038 神经网络//
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
int n,m,C[maxn],U[maxn],in[maxn],out[maxn],vis[maxn];
queue<int> q;
set<int> s;
struct edge{
    int v;
    int w;
};
vector<edge> e[maxn];

int main(void)
{
    n=read(),m=read();
    for(int i=1;i<=n;i++)
    {
        C[i]=read();
        U[i]=read();
    }
    int u,v,w;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        e[u].push_back({v,w});    // 有向边
        out[u]++;
        in[v]++;
    }
    for(int i=1;i<=n;i++)
        if(in[i]==0)
            q.push(i);
    while(1)
    {   
        if(q.empty())   break;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(C[u]<=0) continue; 
            for(auto ed:e[u])
            {
                int v=ed.v,w=ed.w;
                C[v]+=C[u]*w;
                s.insert(v);
            }
        }
        for(auto u:s)
        {
            C[u]=C[u]-U[u];
            if(C[u]>0)  q.push(u);
        }
        s.clear();
    }
    bool flag=false;
    for(int i=1;i<=n;i++)
        if(out[i]==0&&C[i]>0)
            printf("%d %d\n",i,C[i]),flag=true;
    if(!flag)   printf("NULL\n");
    return 0;
}
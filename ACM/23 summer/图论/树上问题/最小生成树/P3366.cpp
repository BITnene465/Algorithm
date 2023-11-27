#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int maxm=2e5+5;
struct edge
{
    int u,v;
    int w;
}e[maxm];
int n,m,ans,s[maxn];
bool cmp(edge a,edge b)
{
    return a.w<b.w;
}
int find_s(int x)
{
    int r=x;while(r!=s[r])r=s[r];
    int t;while(x!=r){t=s[x];s[x]=r;x=t;}
    return r;
}
void union_s(int x,int y)
{
    x=find_s(x);y=find_s(y);
    s[x]=s[y];
    return;
}
bool kruskal()
{
    int cnt=0;
    for(int id=1;id<=m&&cnt<n-1;id++)
    {
        int x=find_s(e[id].u),y=find_s(e[id].v);
        if(x==y)    continue;
        union_s(x,y);
        cnt++;
        ans+=e[id].w;
    }
    if(cnt==n-1)    return true;
    else            return false;
}
int main(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;
        scanf("%d %d %d",&u,&v,&w);
        e[i].u=u;e[i].v=v;e[i].w=w;
    }
    ans=0;
    sort(e+1,e+m+1,cmp);
    for(int i=1;i<=n;i++)
        s[i]=i;
    if(kruskal())   printf("%d\n",ans);
    else    printf("orz\n");
    return 0;
}   
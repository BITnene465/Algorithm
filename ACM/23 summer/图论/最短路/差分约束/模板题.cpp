#include<bits/stdc++.h>
using namespace std;
const int maxn=5005;
const int INF=0x3f3f3f3f;
struct edge{
    int v;
    int w;
};
vector<edge> e[maxn];
queue<int> q;
int n,m,dis[maxn],flag[maxn],cnt[maxn];
int read()
{
    int f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
bool spfa(int s)
{
    memset(dis,63,sizeof(dis));
    q.push(s);
    flag[s]=1,dis[s]=0;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        flag[u]=0;
        for(auto ed:e[u])
        {
            int v=ed.v,w=ed.w;
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(!flag[v])    q.push(v),flag[v]=1;
                cnt[v]=cnt[u]+1;
                if(cnt[v]>=2*n)   return true;  // 长度为n也有可能是有0环，不一定就是有负环，可以把n适当改大一点
            }
        }
    }
    return false;
}
int main(void)
{
    n=read(),m=read();
    int u,w,v;
    for(int i=1;i<=m;i++)
    {
        u=read(),v=read(),w=read();
        e[v].push_back({u,w});  // 重边无所谓
    }
    for(int i=1;i<=n;i++)
        e[n+1].push_back({i,0});    // 以n+1为超级原点，向每一个点加一条0权边
    if(spfa(n+1))   // 有负圈，则无解
    {
        printf("NO\n");
        return 0;
    }
    for(int i=1;i<=n;i++)
        printf("%d%c",dis[i],(i==n)?'\n':' ');
    return 0;
}
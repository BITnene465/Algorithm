// 思路一：确定点1 和 点n两个联通分支中编号差最小的两个点， // update: 思路错了nnd
// 如果相等，代价为0，如果差1，代价为1，如果相差大于1，取中点为中转点，算代价 
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int n,m,T,vis[maxn];
vector<int>g[maxn];
vector<int> s1,sn;   // 存联通分支的编号们
queue<int> q;
void init_vis()
{
    for(int i=1;i<=n;i++)
        vis[i]=0;
    return;
}
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void bfs1()
{
    s1.clear();
    init_vis();
    q.push(1);
    vis[1]=1;
    while(!q.empty())
    {
        int u=q.front();
        s1.push_back(u);    // 出队时加入s1
        q.pop();
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
}
void bfsn()
{
    sn.clear();
    init_vis();
    q.push(n);
    vis[n]=1;
    while(!q.empty())
    {
        int u=q.front();
        sn.push_back(u);    // 出队时加入sn
        q.pop();
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                q.push(v);
                vis[v]=1;
            }
        }
    }
} 
ll solve()    // 双指针求两个数组的最小差值
{
    int i=0,j=0;
    ll minL=10000000;
    while(i<s1.size()&&j<sn.size())
    {
        if(abs(s1[i]-sn[j])<minL) minL=abs(s1[i]-sn[j]);   // 更新最小值
        if(s1[i]-sn[j]>0)   j++;
        else    i++;
    }
    // 计算最小代价
    ll ans=(minL-minL/2)*(minL-minL/2)+(minL/2)*(minL/2);
    return ans;
}
int main(void)
{
    T=read();
    while(T--)
    {
        n=read(),m=read();
        int u,v;
        for(int i=1;i<=m;i++)
        {
            u=read(),v=read();
            g[u].push_back(v);
            g[v].push_back(u);
        }
        bfs1();
        bfsn();
        sort(s1.begin(),s1.end());
        sort(sn.begin(),sn.end());
        printf("%lld\n",solve());
    }
    return 0;
}

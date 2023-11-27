// 2-SAT 模板题 //
#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
vector<int> G[MAXN<<1];   // i代表i种材料做汉菜，i+n代表i种材料做满菜
int T,n,m;
bool instk[MAXN<<1];
int stk[MAXN<<1],top,cnt,low[MAXN<<1],dfn[MAXN<<1];
int id[MAXN<<1],id_cnt;
int read()
{
    int cur=0;char ch;int res,x;
    ch=getchar();
    while(ch!='m'&&ch!='h'){ch=getchar();}
    if(ch=='m')res=n;
    else res=0;
    x=0;ch=getchar();
    while(ch<='9'&&ch>='0'){x=10*x+ch-'0';ch=getchar();}
    return res+x;
}
void reset()
{
    cnt=top=id_cnt=0;
    for(int i=1;i<=2*n;++i)
        G[i].clear();
    memset(dfn,0,sizeof(dfn));
    memset(low,0,sizeof(low));
    memset(instk,0,sizeof(instk));
    memset(id,0,sizeof(id));
}
void adde()
{
    int a,b,na,nb;
    a=read(),b=read();
    na=a>n?a-n:a+n;
    nb=b>n?b-n:b+n;
    G[na].push_back(b);
    G[nb].push_back(a);
}
void Tarjan(int u)
{
    instk[u]=1,stk[++top]=u,dfn[u]=low[u]=++cnt;
    for(auto v:G[u])
    {
        if(!dfn[v]) {Tarjan(v);low[u]=min(low[v],low[u]);}
        else if(instk[v])   low[u]=min(low[u],dfn[v]);
    }
    if(low[u]==dfn[u])
    {
        ++id_cnt;
        while(stk[top]!=u){id[stk[top]]=id_cnt;instk[stk[top--]]=0;}
        id[u]=id_cnt;instk[u]=0;--top;
    }
} 
int main(void)
{
    cin>>T;
    while(T--)
    {
        reset();     // 重置
        cin>>n>>m;
        for(int i=1;i<=m;++i)   // 建图
            adde();
        for(int i=1;i<=2*n;++i)   // 缩点
            if(!dfn[i])Tarjan(i);
        bool f=1;
        for(int i=1;i<=n;++i)   // 判断是否有解
            if(id[i]==id[n+i]){cout<<"BAD"<<endl;f=0;break;}
        if(f)cout<<"GOOD"<<endl;
    }
    return 0;
}
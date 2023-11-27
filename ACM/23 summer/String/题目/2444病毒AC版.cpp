// P2444 病毒 //
// 字典图去掉一些边后;Dfs判环 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int n,nex[maxn][2],fail[maxn],cnt,indeg[maxn];string s;
bool End[maxn];
queue<int> q;
void Insert(string s)
{
    int p=0;
    int l=(int)s.length();
    for(int i=0;i<l;++i)
    {
        int c=s[i]-'0';
        if(!nex[p][c])nex[p][c]=++cnt;
        p=nex[p][c];
    }
    End[p]=true;
}
void pre_fail()   // 顺便建图
{
    if(nex[0][0])q.push(nex[0][0]);
    if(nex[0][1])q.push(nex[0][1]);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<=1;++i)
        {
            if(nex[u][i])
            {
                fail[nex[u][i]]=nex[fail[u]][i];
                if(End[fail[nex[u][i]]])End[nex[u][i]]=true;    // 这样才可以保证所有的危险节点都被找出来
                q.push(nex[u][i]);
            }
            else
                nex[u][i]=nex[fail[u]][i];
        }
    }
}
// Dfs判环
int ins[maxn],vis[maxn];
bool Dfs(int u)
{
    ins[u]=1;     // ins[u]=1表示u正在被访问
    for(int i=0;i<=1;++i)
    {
        int v=nex[u][i];
        if(ins[v])return 1;     // 如果到了一个正在被访问的点，那么找到了一个圈
        if(vis[v]||End[v])continue;    // 如果v被访问过,就不走这条路了（板子里不需要End）
        vis[v]=1;      // 标记v被访问过了
        if(Dfs(v))return 1;
    }
    ins[u]=0;   // 访问结束
    return 0;
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        Insert(s);
    }
    pre_fail();
    if(Dfs(0))cout<<"TAK"<<endl;   // 源点开搜
    else    cout<<"NIE"<<endl;
    return 0;
}
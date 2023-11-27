// P2444 病毒 //
// 字典图去掉一些边后判环 //
// 错了，不会建图; 拓扑排序判环莫名WA 76pt//
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4+5;
int n,nex[maxn][2],fail[maxn],cnt,indeg[maxn];string s;
bool End[maxn];
queue<int> q;
vector<int> g[maxn];
void adde(int u,int v)
{
    g[u].push_back(v);
}
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
                if(End[fail[nex[u][i]]])End[nex[u][i]]=true;
                q.push(nex[u][i]);
            }
            else
                nex[u][i]=nex[fail[u]][i];
        }
    }
}
void build_graph()
{
    for(int i=0;i<=cnt;++i)
    {
        if(End[i]){indeg[i]=-1;continue;}
        if(!End[nex[i][0]]){adde(i,nex[i][0]);indeg[nex[i][0]]++;}
        if(!End[nex[i][1]]){adde(i,nex[i][1]);indeg[nex[i][1]]++;}
    }
}
bool topu_circle()
{
    int tot=0;
    for(int i=0;i<=cnt;++i)
    {
        if(!indeg[i])q.push(i);
    }
        
    while(!q.empty())
    {
        int u=q.front();q.pop();
        tot++;
        for(auto v:g[u])
        {
            indeg[v]--;
            if(!indeg[v])q.push(v);
        }
    }
    if(tot==cnt+1-n)    return false;
    else    return true;   // 有环
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
    build_graph();
    if(topu_circle())cout<<"TAK"<<endl;
    else    cout<<"NIE"<<endl;
    return 0;
}
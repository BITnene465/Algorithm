#include<bits/stdc++.h>
using namespace std;
#define MAXN 60
int G[MAXN][MAXN];int stk[MAXN*MAXN],top;
int n,deg[MAXN];
string s;
inline int getnum(char ch)
{
    if(ch>='A'&&ch<='Z')return ch-'A';
    else    return ch-'a'+26;
}
inline char tochar(int num)
{
    char ch;
    if(num<26)  ch='A'+num;
    else        ch='a'+num-26;
    return ch;
}
void Dfs(int s)
{
    for(int i=0;i<=51;++i)    // 天然字典序
    {
        if(G[s][i]>0)
        {
            G[s][i]--;
            G[i][s]--;
            Dfs(i);
        }
    }
    stk[++top]=s;
}
void print_path()
{
    while(top)cout<<tochar(stk[top--]);
    cout<<endl;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    int S=60;int cnt=0;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        int u=getnum(s[0]),v=getnum(s[1]);
        G[u][v]++;G[v][u]++;
        deg[u]++;deg[v]++;
        S=min(S,u);S=min(S,v);
    }
    for(int i=51;i>=0;i--)   if(deg[i]&1){cnt++;S=i;}   // 统计奇度点个数
    if(cnt!=0&&cnt!=2){cout<<"No Solution"<<endl;return 0;}
    Dfs(S);
    if(top<n+1){cout<<"No Solution"<<endl;return 0;}    // 对应不联通的情况
    print_path();
    return 0;
}
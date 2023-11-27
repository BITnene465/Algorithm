// TLE 版本 95pt//
// L语言   AC自动机 + DP //
#include<bits/stdc++.h>
using namespace std;
const int maxS=21;
const int maxT=2e6+5;
string s,t;
int nex[500][26],fail[500],len[500],f[maxT],cnt,n,m;
bool End[500];
queue<int> q;
void Insert(string s)
{
    int p=0,l=(int)s.length();
    for(int i=0;i<l;++i)
    {
        int c=s[i]-'a';
        if(!nex[p][c])nex[p][c]=++cnt;
        p=nex[p][c];
    }
    End[p]=true;
    len[p]=l;
}
void Query(string t)
{
    int l=(int)t.length();
    int p=0;
    for(int i=0;i<l;++i)
    {
        int c=t[i]-'a';
        p=nex[p][c];
        f[i+1]=0;
        for(int k=p;k;k=fail[k])
        {
            if(!End[k])continue;
            if(f[i-len[k]+1]&1){f[i+1]=1;break;}
        }
    }
}
void Pre_fail()
{
    for(int i=0;i<26;++i)
        if(nex[0][i])q.push(nex[0][i]);
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<26;++i)
        {
            if(nex[u][i])
            {
                fail[nex[u][i]]=nex[fail[u]][i];
                q.push(nex[u][i]);
            }
            else    nex[u][i]=nex[fail[u]][i];
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        Insert(s);
    }
    Pre_fail();
    f[0]=1;  // 这个必须有
    for(int i=1;i<=m;++i)
    {
        cin>>t;
        Query(t);
        int ans=0;
        int l=(int)t.length();
        for(int i=l;i>=1;--i)if(f[i]&1){ans=i;break;}
        cout<<ans<<endl;
    }
    return 0;
}
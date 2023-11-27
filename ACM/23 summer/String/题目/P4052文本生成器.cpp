// 文本生成器 //
// ACam + 图上DP //
#include<bits/stdc++.h>
using namespace std;
const int mod=1e4+7;
const int maxn=6005;   // 最大节点数(模式串长度之和)
string s;
int n,m;
int f[101][maxn];   // f[i][j]表示当前j节点，串长为i，不可读的数量
namespace ACam
{
    queue<int> q;
    int cnt;
    struct state
    {
        int nex[26];
        int fail;
        bool End;
    };
    state st[maxn];
    inline int getnum(char ch){return ch-'A';}
    void Insert(string s)
    {
        int p=0,l=(int)s.length();
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!st[p].nex[c])st[p].nex[c]=++cnt;
            p=st[p].nex[c];
        }
        st[p].End=1;
    }
    void Pre_fail()
    {
        for(int i=0;i<26;++i)
            if(st[0].nex[i])st[st[0].nex[i]].fail=0,q.push(st[0].nex[i]);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            for(int i=0;i<26;++i)
            {
                int v=st[u].nex[i];
                if(v)
                {
                    st[v].fail=st[st[u].fail].nex[i];
                    if(st[st[v].fail].End)st[v].End=1;    // 这样可以找出所有的危险串
                    q.push(v); 
                }
                else
                    st[u].nex[i]=st[st[u].fail].nex[i];
            }
        }
    }
    void Query()   // 也是DP的过程
    {
        f[0][0]=1;  // 必不可少
        for(int i=0;i<=m-1;++i)
        {
            for(int j=0;j<=cnt;++j)
            {
                if(st[j].End)continue;
                for(int k=0;k<26;++k)
                {
                    if(!st[st[j].nex[k]].End)   f[i+1][st[j].nex[k]]=(f[i+1][st[j].nex[k]]+f[i][j])%mod;
                }
            }
        }
    }
};
using namespace ACam;
int qpow(int x,int power,int mod)
{
    x=x%mod;
    int res=1;
    for(;power;power>>=1,x=x*x%mod)
        if(power&1)res=res*x%mod;
    return res;
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
    Query();
    int ans=qpow(26,m,mod);
    for(int i=0;i<=cnt;++i)     // 一定要从0开始！！
        ans=(ans-f[m][i]+mod)%mod;
    cout<<ans<<endl;
    return 0;
}
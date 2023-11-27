// 两个字符串的最长公共子串 //
#include<bits/stdc++.h>
using namespace std;
const int MAXN=3e5+1;   // 字符串的最大长度 
namespace Sam
{
    int cnt=0,last;
    struct state
    {
        int len,link;
        int nex[26];
    };
    state st[2*MAXN];   
    inline int getnum(char ch)
    {
        return ch-'a';
    }
    void _init_()
    {
        last=1,cnt=1;
        st[1].len=0;
        st[1].link=0;   
    }
    void extend(char ch)
    {
        int c=getnum(ch);
        int cur=++cnt;
        int p=last;last=cur;
        st[cur].len=st[p].len+1;    // 不要忘了初始化长度
        for(;p&&!st[p].nex[c];p=st[p].link){st[p].nex[c]=cur;}
        if(!p){st[cur].link=1;return;}
        int q=st[p].nex[c];
        if(st[q].len==st[p].len+1){st[cur].link=q;return;}
        int nq=++cnt;
        st[nq].len=st[p].len+1;
        memcpy(st[nq].nex,st[q].nex,sizeof(state::nex));
        st[nq].link=st[q].link;st[q].link=st[cur].link=nq;
        for(;st[p].nex[c]==q;p=st[p].link)st[p].nex[c]=nq;
    }  
};
using namespace Sam;
string s,t;
// 示例：返回一个匹配的最长公共子串 //
// 核心为：找一个字符串和自动机匹配的最长后缀 + 动态维护T的前缀 //
int LCS(const string& s,const string& t)
{
    _init_();
    int l1=(int)s.length(),l2=(int)t.length();
    for(int i=0;i<l1;++i)extend(s[i]);

    int l=0,best=0,p=1;
    for(int i=0;i<l2;++i)   // 每次加入T的一个字符
    {
        int c=getnum(t[i]);
        while(st[p].link&&!st[p].nex[c])   // 无法匹配，跳link（后缀）
        {
            p=st[p].link;
            l=st[p].len;
        }
        if(st[p].nex[c])
        {
            p=st[p].nex[c];
            l++;   // 注意为什么是 l++, 而不是l=st[p].len
        }
        if(l>best)best=l;
    }
    return best;
}
// 主函数
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;cin>>t;
    cout<<LCS(s,t)<<endl;
    return 0;
}
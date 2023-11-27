// 自制版本 //
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1;   // 字符串的最大长度 
// 后缀自动机 //
// 如果想要维护多个Sam,可以在此模板的基础上更改 //
namespace Sam
{
    // cnt记录点状态数，last为上次更新的状态 //
    int cnt,last;
    struct state
    {
        int len,link;
        int nex[26];    // 这里默认26个小写字母集
        // 如果字符集太大了，可以使用map
        // std::map<char,int> nex 
    };
    state st[2*MAXN];   // 节点数<=2n
    // 字符和整数的映射 
    inline int getnum(char ch)
    {
        return ch-'a';
    }
    // 初始化：根节点为1，空节点为0
    void _init_()
    {
        last=1,cnt=1;
        st[1].len=0;
        st[1].link=0;   // 后缀连接为空节点
    }
    // 扩展，在线维护Sam，每次加入一个字符 
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
        for(;st[p].nex[c]==q;p=st[p].link)st[p].nex[c]=nq;   // st[0].nex[c]=0,无需担心
    }
};
using namespace Sam;
string s;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>s;
    int l=(int)s.length();
    _init_();
    for(int i=0;i<l;++i)
    {
        extend(s[i]);
    }
    int ans=0;
    for(int i=2;i<=cnt;++i)    // 根节点的贡献是0，从2号节点开始
    {
        ans+=st[i].len-st[st[i].link].len;
    }
    cout<<"本质不同的子串有"<<ans<<endl;  // 不包含空字符串
    return 0;
}
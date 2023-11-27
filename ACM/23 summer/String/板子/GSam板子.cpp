// GSam //
#include<bits/stdc++.h>
#define MAXN 100005
#define CHAR_NUM 26
using namespace std;
namespace GSam
{
    queue<pair<int,int>> q;    // <now,last>
    int cnt;  // 节点总数:[1,cnt],1为根节点
    struct state{
        int nex[CHAR_NUM];  // 转移
        int len;            // 节点长度
        int link;           // 后缀连接，link
    };
    state st[MAXN];      // 最大节点数2*\sum|s_i|
    void _init_()
    {
        cnt=1;
        st[1].link=st[1].len=0;
    }
    // 依旧是核心函数 //
    int expendGSam(int last,int c)     // last为父节点，cur为c儿子
    {
        int cur=st[last].nex[c];
        if(st[cur].len) return cur;   // *
        st[cur].len=st[last].len+1;
        int p=st[last].link;     // 因为已知last有c儿子了，所以p从这里开始（和之前的Sam稍有不同）
        for(;p&&!st[p].nex[c];p=st[p].link) st[p].nex[c]=cur;
        if(!p){st[cur].link=1;return cur;}   // 没找到，直接连到根节点
        int q=st[p].nex[c];
        if(st[q].len==st[p].len+1){st[cur].link=q;return cur;}
        int nq=++cnt;  // 准备分裂
        for(int i=0;i<CHAR_NUM;++i)
            st[nq].nex[i]=(st[st[q].nex[i]].len)?st[q].nex[i]:0;    // 又一处不同 **
        st[nq].len=st[q].len+1;
        for(;p&&st[p].nex[c]==q;p=st[p].link)   st[p].nex[c]=nq;
        st[nq].link=st[q].link;
        st[q].link=st[cur].link=nq;
        return cur;
    }
    // 在字典树基础上，用BFS建立后缀自动机，新增函数 //
    void build()
    {
        for(int i=0;i<CHAR_NUM;++i)
            if(st[1].nex[i])q.push({i,1}),st[st[1].nex[i]].link=1;    // 入队并设置好link，同ACam
        while(!q.empty())
        {
            auto it=q.front();q.pop();
            auto last=expendGSam(it.second,it.first);       // 只有在此处用到expendGSam函数
            for(int i=0;i<CHAR_NUM;++i)
                if(st[last].nex[i])q.push({i,last});
        }
    }
    // 下面为Trie的插入操作，轻车熟路
    inline int getnum(char ch)          // 这里以小写字母举例,字符集和整数的映射函数
    {
        return ch-'a';   
    }
    inline int insertTrie(int cur,int c)    // 该函数主要是为了封装更好看
    {
        if(st[cur].nex[c])return st[cur].nex[c];  // 节点已经存在，直接返回即可
        return st[cur].nex[c]=++cnt;              // 节点不存在，新建一个
    }
    void insert(const string& s)     // 一个处理string类型的insert版本
    {
        int p=1;    // 刚开始是根节点
        for(auto ch:s)  p=insertTrie(p,getnum(ch));
    }
    void insert(const char* s,int l)   // c字符串版本
    {
        int p=1;
        for(int i=0;i<l;++i)
            p=insertTrie(p,getnum(s[i]));
    }
};
using namespace GSam;
// 主函数，使用案例 //
string s;
int n;    // n个模式串
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    _init_();
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        insert(s);
    }
    build();      // 在Trie上构建广义后缀自动机
    // 构建完毕，下面开始操作

    // 操作结束
    return 0;
}
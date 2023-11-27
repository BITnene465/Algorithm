// ACam二次加强版 //
// fail图拓扑排序很快 //
// 大致题意：给出n个可能重复的模式串，和文本串S，查找每个模式串在文本串里的出现次数 //
#include<bits/stdc++.h>
using namespace std;
const int maxt=2e6+5;
const int maxn=2e5+5;
int vis[maxn],n;
int rev[maxn];   // 表示第i个字符串对应的计数编号，用于处理重复模式串
char s[maxt];
struct ACam
{
    int nex[maxn][26],cnt;  // 只考虑小写的26个字母
    int fail[maxn];  // fail指针,自动机的精髓
    int indeg[maxn];   // 记录fail图入度，是此优化的核心
    int ans[maxn];    // ans标记，可以最后拓扑排序得到答案，此优化的核心
    int idx[maxn];
    queue<int> q;
    int getnum(char ch)   // 字符集和整数的对应
    {
        return ch-'a';
    }
    void Insert(char s[],int l,int id)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
        if(!idx[p]) idx[p]=id;   // 最小的那个id即为idx[p]
        rev[id]=idx[p];
    }       
    // 多模式匹配
    void Query(char t[],int l)    
    {
        int p=0;
        for(int i=0;i<l;++i){p=nex[p][getnum(t[i])];ans[p]++;}   // 返回值不需要，打上ans标记即可
    }
    void Pre_fail()   // 插入完毕后再预处理fail指针,处理类似于BFS
    {
        fail[0]=0;   // 约定一下，不初始化也可以
        for(int i=0;i<26;++i)
            if(nex[0][i])q.push(nex[0][i]),fail[nex[0][i]]=0;   // 初始化第一层
        while(q.size())
        {
            int u=q.front();
            q.pop();
            for(int i=0;i<26;++i)    
            {
                int v=nex[u][i];
                if(!v)
                {
                    nex[u][i]=nex[fail[u]][i];
                    continue;
                }
                fail[v]=nex[fail[u]][i];
                indeg[nex[fail[u]][i]]++;    // 入度加一,与上一个唯一的不同之处
                q.push(v);
            }
        }
    }
    // 拓扑排序算答案       只是找存在性可以用拓扑遍历
    void topu()
    {
        for(int i=1;i<=cnt;++i)
            if(!indeg[i])q.push(i);
        while(q.size())
        {
            int fr=q.front();q.pop();
            vis[idx[fr]]=ans[fr];
            int v=fail[fr];
            ans[v]+=ans[fr];
            if(!(--indeg[v]))q.push(v);
        }
    }
};
ACam AC;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        AC.Insert(s,strlen(s),i);
    }
    AC.Pre_fail();
    cin>>s;
    AC.Query(s,strlen(s));
    AC.topu();
    for(int i=1;i<=n;++i)
        cout<<vis[rev[i]]<<endl;
    return 0;
}
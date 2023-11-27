// 这个代码写的很丑 啊啊啊啊啊啊//
// ACam (加强版) //
#include<bits/stdc++.h>
using namespace std;
const int maxn=11000;
const int maxt=1e6+4;
typedef vector<int> vei;
struct ACam
{
    // 字典树中，0为根节点，0也为空节点，记得判断
    int nex[maxn][26],cnt;  // 只考虑小写的26个字母
    int fail[maxn];  // fail指针,自动机的精髓
    int exist[maxn];  // 记录id值
    int ccnt[151];   // 记录每个模式串的出现次数
    queue<int> q;
    //
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
        exist[p]=id;
    }       
    // 多模式匹配
    vei Query(char t[],int l,int n)    // 返回值看需要，此处查询模式串在文本t中出现的不同的模式串的个数总和
    {
        vei res;
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(t[i]);
            p=nex[p][c];
            for(int j=p;j;j=fail[j])
            {
                if(exist[j])ccnt[exist[j]]++;
            }
        }
        // 找出现最多的字符串的id
        int ma=0;
        for(int i=1;i<=n;++i)
            if(ccnt[i]>ma)ma=ccnt[i];
        cout<<ma<<endl;
        for(int i=1;i<=n;++i)
            if(ccnt[i]==ma)res.push_back(i);
        return res;
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
            for(int i=0;i<26;++i)    // 这是路径压缩的版本
            {
                if(nex[u][i])    // 存在这个节点
                    fail[nex[u][i]]=nex[fail[u]][i],q.push(nex[u][i]);
                else   // 不存在这个节点
                    nex[u][i]=nex[fail[u]][i];
            }
        }
    }
    void reset()
    {
        for(int i=1;i<=150;++i)
            ccnt[i]=0;
        for(int i=0;i<=cnt;++i)
        {
            fail[i]=0;
            exist[i]=0;
            for(int j=0;j<26;++j)nex[i][j]=0;
        }
        cnt=0;   // 最后更新
    }
};
ACam T;
int n;char s[151][75],t[maxt];
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while(1){
    cin>>n;
    if(n==0)break;
    T.reset();   // 重置
    for(int i=1;i<=n;++i)
    {
        cin>>s[i];
        T.Insert(s[i],strlen(s[i]),i);
    }
    cin>>t;
    T.Pre_fail();
    vei tmp=T.Query(t,strlen(t),n);
    for(int i=0;i<tmp.size();++i)
        cout<<s[tmp[i]]<<endl;
    }
    return 0;
}
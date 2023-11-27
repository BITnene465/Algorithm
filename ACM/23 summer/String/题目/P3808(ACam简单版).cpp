// ACam (简单版) //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
struct ACam
{
    // 字典树中，0为根节点，0也为空节点，记得判断
    int nex[10*maxn+5][26],cnt;  // 只考虑小写的26个字母
    int fail[10*maxn+5];  // fail指针,自动机的精髓
    int ccnt[10*maxn+5];
    //
    int getnum(char ch)   // 字符集和整数的对应
    {
        return ch-'a';
    }
    void Insert(char s[],int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
        ccnt[p]++;
    }       
    // 多模式匹配
    int Query(char t[],int l)    // 返回值看需要，此处查询模式串在文本t中出现的不同的模式串的个数总和
    {
        int p=0,res=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(t[i]);
            p=nex[p][c];
            for(int j=p;j;j=fail[j])
            {
                if(ccnt[j]!=-1)
                {
                res+=ccnt[j];
                ccnt[j]=-1;   // 遍历过了
                }
            }
        }
        return res;
    }
    void Pre_fail()   // 插入完毕后再预处理fail指针,处理类似于BFS
    {
        queue<int> q;
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
};
ACam T;
int n;char s[maxn];
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        T.Insert(s,strlen(s));
    }
    cin>>s;
    T.Pre_fail();
    cout<<T.Query(s,strlen(s))<<endl;
    return 0;
}
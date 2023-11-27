// P3808 //
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
            while(!nex[p][c]&&p)p=fail[p];
            p=nex[p][c];
            res+=ccnt[p];
            ccnt[p]=0;   // 防止下次来重复计算
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
            for(int i=0;i<26;++i)
            {
                if(!nex[u][i])continue;
                int k=u;
                while(!nex[fail[k]][i]&&k)k=fail[k];
                if(k==0)fail[nex[u][i]]=0;
                else    fail[nex[u][i]]=nex[fail[k]][i];
                // 其实也可以直接:  fail[nex[u][i]]=nex[fail[k]][i];
                q.push(nex[u][i]);
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
// P3879 阅读理解 //
// 下面是本题的一种数据结构的实现方式，同时也可以用一个数组来维护多棵字典树，只需要动态开点即可 //
// MLE  90pt //
// 此题必须要用一个数组来维护多棵字典树 //
#include<bits/stdc++.h>
using namespace std;
const int maxt=5e3;   // 每篇文章最大字符数
const int maxs=21;      // 单词最大长度
const int maxn=1e3;   // 最多多少篇文章
struct trie
{
    int cnt,nex[maxt][26];
    bool exist[maxt];
    void Insert(char s[],int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=s[i]-'a';
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
        }
        exist[p]=true;
    }
    bool find(char s[],int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=s[i]-'a';
            if(!nex[p][c])return false;
            p=nex[p][c];
        }
        return exist[p];
    }
};
trie T[maxn];   // 维护多棵字典树
int N,M,L;char s[maxs];
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>N;
    for(int i=0;i<N;++i)
    {
        cin>>L;
        for(int j=0;j<L;++j)
        {
            cin>>s;
            T[i].Insert(s,strlen(s));
        }
    }
    cin>>M;
    for(int i=1;i<=M;++i)
    {
        cin>>s;
        for(int j=1;j<=N;++j)
            if(T[j-1].find(s,strlen(s)))cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
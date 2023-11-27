#include<bits/stdc++.h>
using namespace std;
struct trie{
    int nex[2000005][30],cnt;
    bool exist[2000005];  // 该节点结尾的字符串是否存在
    bool flag[2000005];  // 标记以p节点结尾的字符串是否被点到过了

    void insert(char* s,int l)
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
    int find(char* s,int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=s[i]-'a';
            if(!nex[p][c])  return -1;   // 不存在
            p=nex[p][c];
        }
        if(!exist[p])return -1;  //不存在，容易遗漏
        if(flag[p]) return 0;  //重复点名
        flag[p]=true;
        return 1;    // 点名成功
    }
};
int n,m;char s[105];
trie T;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cin>>s;
        T.insert(s,strlen(s));
    }
    cin>>m;
    for(int i=0,flag;i<m;++i)
    {
        cin>>s;
        flag=T.find(s,strlen(s));
        if(flag==-1)printf("WRONG\n");
        else if(flag==0)printf("REPEAT\n");
        else    printf("OK\n");
    }
    return 0;
}
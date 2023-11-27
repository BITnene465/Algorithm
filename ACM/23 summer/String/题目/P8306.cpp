// 统计前缀个数 //
#include<bits/stdc++.h>
using namespace std;
const int sigma=62;    // 字符集的大小
struct trie{
    int nex[2000005][sigma],cnt;   // 数组别开小了
    int ccnt[2000005];
    void insert(char* s,int l)
    {
        int p=0;
        ccnt[0]++;     // ccnt[0]统计的是输入的字符串个数
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!nex[p][c])nex[p][c]=++cnt;
            p=nex[p][c];
            ccnt[p]++;  // 以该字符串为前缀的字符串个数加一
        }   
    }
    // s为要匹配前缀的字符串
    int query(char* s,int l)
    {
        int p=0;
        for(int i=0;i<l;++i)
        {
            int c=getnum(s[i]);
            if(!nex[p][c])  return 0;   // 不存在,即0
            p=nex[p][c];
        }
        return ccnt[p];
    }
    void reset()
    {
        for(int i=0;i<=cnt;++i)
        {
            for(int j=0;j<sigma;++j)
                nex[i][j]=0;
            ccnt[i]=0;
        }
        cnt=0;
        return;
    }
    int getnum(char x)
    {
        if(x>='A'&&x<='Z')
            return x-'A';
        else if(x>='a'&&x<='z')
            return x-'a'+26;
        else if(x>='0'&&x<='9')
            return x-'0'+52;
    } 
};
trie tr;
int T,n,q;
char s[(int)3e6+5];
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>T;
    while(T--)
    {
        tr.reset();
        cin>>n>>q;
        for(int i=0;i<n;++i)
        {
            cin>>s;
            tr.insert(s,strlen(s));
        }
        for(int i=0;i<q;++i)
        {
            cin>>s;
            printf("%d\n",tr.query(s,strlen(s)));
        }
    }
    return 0;
}
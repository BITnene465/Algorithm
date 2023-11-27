// 最胃痛的一集 //
// 每一个人优先刺杀在自己后面最靠前的异族 ， 不能刺杀别人就去ban最前面的异族 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,top,stk[maxn],flag[maxn]; // flag: 0 存活 1 死亡
char s[maxn];
int main(void)
{
    scanf("%d",&n);
    getchar();
    scanf("%s",s+1);
    // 为了迎合出题者，乐,但是逻辑是错的
    int D=0,X=0;
    for(int i=1;i<=n;++i)
    {
        if(s[i]=='D')D++;
        else X++;
    }
    if(D==X)
    {
        printf("%c\n",s[1]);
        return 0;
    }
    // 特判结束
    int deta;
    do{
        top=deta=0;
        for(int i=1;i<=n;++i)
        {
            if(flag[i])continue;
            if(top&&s[i]!=s[stk[top]])flag[i]=1,--top,++deta;
            else stk[++top]=i;
        }
        for(int i=1;top&&i<=n;++i)
        {
            if(flag[i])continue;   // 已经死了，没必要判断了
            if(s[i]!=s[stk[top]])flag[i]=1,--top,++deta;
        }
       // for(int i=1;i<=n;++i)if(!flag[i]){printf("%c",s[i]);}
       // printf("\n");
    }while(deta);
    for(int i=1;i<=n;++i)if(!flag[i]){printf("%c\n",s[i]);break;}
    return 0;
}



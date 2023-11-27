#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,top,stk[maxn],flag[maxn]; // flag: 0 ¥ÊªÓ 1 À¿Õˆ
char s[maxn],win;
int main(void)
{
    scanf("%d",&n);
    getchar();
    scanf("%s",s+1);
    while(1)
    {
        int Dk=0,Xk=0;
        top=0;
        for(int i=1;i<=n;++i)
        {
            if(!top||s[stk[top]]!=s[i])--top;
            else
            {
                stk[++top]=i;
                if(s[i]=='D')   Dk++;
                else            Xk++;
            }
        }
        int l=0;
        int cntD=0,cntX=0;
        for(int i=1;i<=n;++i)
        {
            if(s[i]=='D')
            {
                cntD++;
                if(cntD>Xk)s[++l]='D';
            }
            else
            {
                cntX++;
                if(cntX>Dk)s[++l]='X';
            }
        }
        for(int i=1;i<=l;++i)putchar(s[i]);
        printf("\nDk=%d,Xk=%d\n",Dk,Xk);

        if(n==l){win=s[1];break;}
        
        n=l;
    }
    printf("%c\n",win);
    return 0;
}
// 相当潦草的解法，完全可以被hack //
#include<bits/stdc++.h>
using namespace std;
const char pat[]=" fattyhappy";
char s[1010];
int T,p[11];
int cmp(int idx)
{
    int f=0;
    for(int i=1;i<=10;++i)
        if(s[idx-1+i]!=pat[i])p[++f]=i;
    return f;
}
void solve()
{
    int f;
    int l=strlen(s+1);
    for(int i=1;i<=l-9;++i)
    {
        f = cmp(i);
        if(f==0){printf("%d %d\n",i+2,i+3);return;}
        else if(f==1)
        {
            char find=pat[p[1]];
            for(int j=1;j<=l;++j)
                if(s[j]==find&&(j>i+9||j<i)){printf("%d %d\n",i-1+p[1],j);return;}
        }
        else if(f==2){if(s[i-1+p[1]]==pat[p[2]]&&s[i-1+p[2]]==pat[p[1]]){printf("%d %d\n",i-1+p[1],i-1+p[2]);return;}}
    }
    printf("-1\n");
    return;
}
int main(void)
{   
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        scanf("%s",s+1);
        solve();
    }
    return 0;
}
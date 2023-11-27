#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,d1[maxn],d2[maxn];
char s[maxn];
// 字符串s,长度n,两个数组d1[],d2[]
void manacher(char s[],int n,int d1[],int d2[])
{
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])    ++k;
        d1[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k+1;}
    }
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-1-k>=0&&i+k<n&&s[i+k]==s[i-1-k])    ++k;
        d2[i]=k;
        if(i+k-1>=r){r=i+k-1;l=i-k;}
    }
    return;
}
int main(void)
{   
    scanf("%s",s);
    n=strlen(s);
    manacher(s,n,d1,d2);
    for(int i=0;i<n;++i)
        printf("%d %d\n",d1[i],d2[i]);
    return 0;
}

// Manacher °å×Ó //
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7+3;
char s[maxn];
int d1[maxn],d2[maxn],n,ans;
void manacher(char s[],int n,int d1[],int d2[])
{
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])++k;
        d1[i]=k;if(ans<2*k-1)ans=2*k-1;
        if(i+k-1>r){r=i+k-1;l=i-k+1;}
    }
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-k-1>=0&&i+k<n&&s[i-k-1]==s[i+k])++k;
        d2[i]=k;if(ans<2*k)ans=2*k;
        if(i+k-1>r){r=i+k-1;l=i-k;}
    }
    return;
}
int main(void)
{
    scanf("%s",s);
    n=strlen(s);
    ans=0;
    manacher(s,n,d1,d2);
    cout<<ans<<endl;
    return 0;
}
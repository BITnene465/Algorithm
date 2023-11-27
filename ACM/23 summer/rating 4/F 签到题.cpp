#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int T,n,m,k,d1[maxn],d2[maxn],buc[maxn];
char s[maxn];
// 字符串s,长度n,两个数组d1[],d2[]
void manacher(char s[],int n,int d1[],int d2[],int maxk)
{
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])    ++k;
        d1[i]=k;
        int tmp=min(2*k-1,maxk);
        for(int j=1;j<=tmp;j+=2)
            buc[j]++;

        if(i+k-1>r){r=i+k-1;l=i-k+1;}
    }
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-1-k>=0&&i+k<n&&s[i+k]==s[i-1-k])    ++k;
        d2[i]=k;
        int tmp=min(2*k,maxk);
        for(int j=2;j<=tmp;j+=2)
            buc[j]++;

        if(i+k-1>r){r=i+k-1;l=i-k;}
    }
    return;
}
bool search(int sum,int num)
{
    if(sum<num)return 0;
    if(sum==num)
    {
        if(buc[1]>=sum)return 1;
        return 0;
    }
    for(int i=1;i<=num-1;++i)
    {
        if(buc[1]>=i&&sum>i&&buc[sum-i]>=1)return 1;
        if(buc[2]>=i&&sum>2*i&&buc[sum-2*i]>=1)return 1;
    }
    return 0;
}
int main(void)
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        memset(buc,0,sizeof(buc));
        for(int i=1;i<=n;++i)
        {
            scanf("%s",s);
            int l=strlen(s);
            manacher(s,l,d1,d2,k);
        }
        if(search(k,m))printf("YES\n");
            else    printf("NO\n");
    }
    return 0;
}
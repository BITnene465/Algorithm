#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int T;
char a[maxn],b[maxn],c[maxn];
void add(char a[],int l1,char b[],int l2,char c[])
{
    if(l1<l2){swap(a,b);swap(l1,l2);}
    int tmp=0;
    for(int i=1;i<=l2;++i)
    {
        int x=tmp+a[l1+1-i]-'0'+b[l2+1-i]-'0';
        tmp=x>>1;
        c[i]=(x&1)+'0';
    }
    for(int i=l2+1;i<=l1;++i)
    {
        int x=tmp+a[l1+1-i]-'0';
        tmp=x>>1;
        c[i]=(x&1)+'0';
    }
    int l3;
    if(tmp==1){l3=l1+1;c[l3]='1';c[l3+1]='\0';}
    else {l3=l1;c[l3+1]='\0';}
    // reverse
    for(int i=1;i<=(1+l3)/2;++i)swap(c[i],c[l3+1-i]);
    return;
}
int main(void)
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",a+1);
        scanf("%s",b+1);
        int l1,l2,l3;
        l1=strlen(a+1),l2=strlen(b+1);
        add(a,l1,b,l2,c);
        l3=strlen(c+1);
        for(int i=1;i<=l3+2-l1;++i)putchar(' ');
        puts(a+1);
        putchar('+');
        for(int i=1;i<=l3+1-l2;++i)putchar(' ');
        puts(b+1);
        for(int i=1;i<=l3+2;++i)putchar('-');
        printf("\n  ");
        puts(c+1);
    }
    return 0;
}
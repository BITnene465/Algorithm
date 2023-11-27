// TLE 版本 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
void fr(char &x)
{
    x=0;while(x!='M'&&x!='A') x=getchar();
}
int n,q,w,c,l,r;
int a[maxn],b[maxn],belong[maxn],st[maxn],ed[maxn],tag[maxn],s,num;  // s为每个分块的最大长度,num为分块的个数
void init()
{   
    st[1]=1,ed[1]=s;
    for(int i=2;i<=num-1;i++)
        st[i]=st[i-1]+s,ed[i]=ed[i-1]+s;
    num=s;
    if(ed[s]<n)
    {
        st[s+1]=ed[s]+1;
        if(ed[s]+s<n)
        {
            ed[s+1]=ed[s];
            st[s+2]=ed[s+1]+1;
            ed[s+2]=n;
            num=s+2;
        }
        else
        {
            ed[s+1]=n;
            num=s+1;
        }
    }
    // belong & sort
    for(int i=1;i<=num;i++)
    {
        for(int j=st[i];j<=ed[i];j++)
            belong[j]=i;
        tag[i]=0;    // 第i块的tag初始化为0
        sort(a+st[i],a+ed[i]+1);   // 每个块内排序
    }
    return;
}
void update(int l,int r,int w)
{
    int x=belong[l],y=belong[r];
    if(x==y)    // 起点和终点在同一块内，直接更新
    {
        for(int i=l;i<=r;i++)
            b[i]+=w;
        for(int i=st[x];i<=ed[x];i++)
            a[i]=b[i];
        sort(a+st[x],a+ed[x]+1);
    }
    else
    {
        for(int i=l;i<=ed[x];i++) 
            b[i]+=w;
        for(int i=st[y];i<=r;i++)
            b[i]+=w;
        // 下放tag
        for(int i=st[x];i<=ed[x];i++)
            a[i]=b[i]=b[i]+tag[x];
        tag[x]=0;
        for(int i=st[y];i<=ed[y];i++)
            a[i]=b[i]=b[i]+tag[y];
        tag[y]=0;
        // 对a重新排序
        sort(a+st[x],a+ed[x]+1);
        sort(a+st[y],a+ed[y]+1);  
        // 中间部分直接加tag
        for(int i=x+1;i<=y-1;i++)
            tag[i]+=w;
    }
    return;
}
int query(int l,int r,int c)
{
    int x=belong[l],y=belong[r];
    int sum=0;
    if(x==y)
    {   
        for(int i=l;i<=r;i++)   if(b[i]>=c)sum++;
        return sum;
    }
    else
    {
        for(int i=l;i<=ed[x];i++)   if(b[i]>=c)sum++;
        for(int i=st[y];i<=r;i++)   if(b[i]>=c)sum++;
        for(int i=x+1;i<=y-1;i++)
            sum+=a+ed[i]+1-lower_bound(a+st[i],a+ed[i]+1,c-tag[i]);
        return sum;
    }
}
int main(void)
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i),b[i]=a[i];
    s=sqrt(n);
    init();
    // query
    char flag;
    while(q--)
    {
        fr(flag);
        if(flag=='M')
        {
            scanf("%d %d %d",&l,&r,&w);
            update(l,r,w);
        }
        else if(flag=='A')
        {   
            scanf("%d %d %d",&l,&r,&c);
            printf("%d\n",query(l,r,c));
        }
    }
    return 0;
}

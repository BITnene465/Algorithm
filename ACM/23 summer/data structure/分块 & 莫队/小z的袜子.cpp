// 离线普通莫队算法板子 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const int maxm=5e4+10;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
struct query{
    int r,l;
    int id;
}q[maxm];
int n,m,a[maxn],ans1[maxm],ans2[maxm];int buc[maxn],l,r,cnt,cnt2;int s,num,belong[maxn],st[maxn],ed[maxn];
bool cmp(query a,query b)
{
    if(belong[a.l]<belong[b.l]) return true;
    else if(belong[a.l]==belong[b.l])    return belong[a.r]<=belong[b.r];
    else return false;
}
int gcd(int x,int y)
{
    int temp;
    if(x<y)swap(x,y);
    while(y)
    {
        temp=x%y;
        x=y;
        y=temp;
    }
    return x;
}
void init()
{
    s=sqrt(n);
    st[1]=1,ed[1]=s;
    for(int i=2;i<=s;i++)
        st[i]=st[i-1]+s,ed[i]=ed[i-1]+s;
    num=s;
    if(ed[s]<n)
    {
        num++;
        st[s+1]=ed[s]+1;
        ed[s+1]=n;
    }
    //
    for(int i=1;i<=num;i++)
    {
        for(int j=st[i];j<=ed[i];j++)
            belong[j]=i;
    }
    return;
}
void move(int x,int flag)
{
    if(flag==1)
    {
        cnt2+=r-l;
        buc[a[x]]++;
        cnt+=buc[a[x]]-1;
        printf("l=%d,r=%d,cnt2=%d,cnt=%d\n",l,r,cnt2,cnt);
    }
    else
    {
        cnt2-=r-l+1;
        buc[a[x]]--;
        cnt-=buc[a[x]];
        printf("l=%d,r=%d,cnt2=%d,cnt=%d\n",l,r,cnt2,cnt);
    }
}
void solve(int vl,int vr)
{
    while(l>vl) move(--l,1);   //扩大区间时flag=1
    while(r<vr) move(++r,1);
    while(l<vl) move(l++,-1);  //缩小区间时flag=-1
    while(r>vr) move(r--,-1);
}
int main(void)
{
    // input
    n=read(),m=read();
    for(int i=1;i<=n;i++)
        a[i]=read();
    for(int i=1;i<=m;i++)
        q[i].l=read(),q[i].r=read(),q[i].id=i;
    // 分块 init & sort query
    init();
    sort(q+1,q+m+1,cmp);

    // 莫队算法核心，区间移动
    l=r=1;
    buc[a[1]]=1;
    for(int i=1;i<=m;i++)
    {
        solve(q[i].l,q[i].r);
        if(cnt==0)
        {
            ans1[q[i].id]=0;
            ans2[q[i].id]=1;
            continue;
        }
        int g=gcd(cnt,cnt2);
        ans1[q[i].id]=cnt/g;
        ans2[q[i].id]=cnt2/g;
    }
    // print
    for(int i=1;i<=m;i++)
        printf("%d/%d\n",ans1[i],ans2[i]);
    return 0;
}
// 七星瓢虫 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+10;
const int maxm=5e4+10;
struct query{
    int r,l,g;
    int id;
}q[maxm];
int n,m,a[maxn],ans[maxm];
int buc[maxn],l,r,cnt,gg;
int s,num,belong[maxn],st[maxn],ed[maxn];
bool cmp(query a,query b)
{
    if(belong[a.l]<belong[b.l]) return true;
    else if(belong[a.l]==belong[b.l])    return belong[a.r]<=belong[b.r];
    else return false;
}
bool gcd(int x,int y)
{
    int temp;
    if(x<y)swap(x,y);
    while(y)
    {
        temp=x%y;
        x=y;
        y=temp;
    }
    if(x==1)return true;
    else return false;
}
void init()
{
    s=(int)sqrt(n);
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
        if(buc[a[x]]==0)
        {
            cnt++;
            buc[a[x]]++;
            return;
        }
        bool u = gcd(buc[a[x]],gg);
        bool v = gcd(buc[a[x]]+1,gg);
        if(u&&!v)cnt--;
        else if(!u&&v)cnt++;
        buc[a[x]]++;
        // printf("l=%d r=%d gg=%d cnt=%d\n",l,r,gg,cnt);
    }
    else
    {
        if(buc[a[x]]==1)
        {
            cnt--;
            buc[a[x]]--;
            return;
        }
        bool u = gcd(buc[a[x]],gg);
        bool v = gcd(buc[a[x]]-1,gg);
        if(u&&!v)cnt--;
        else if(!u&&v)cnt++;
        buc[a[x]]--;
        // printf("l=%d r=%d gg=%d cnt=%d\n",l,r,gg,cnt);
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
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){scanf("%d",a+i);}
    for(int i=1;i<=m;i++){q[i].id=i,scanf("%d %d %d",&q[i].l,&q[i].r,&q[i].g);}
    // 分块 init & sort query
    init();
    sort(q+1,q+m+1,cmp);
    // 莫队算法核心，区间移动
    q[0].g=-1;
    r=l=1,buc[a[1]]=1;
    for(int i=1;i<=m;i++)
    {
        if(q[i].g!=q[i-1].g)   // g不同了，重新初始化
        {
            gg = q[i].g;
            cnt = 0;
            for(int j=1;j<=n;j++)
            {
                if(buc[j]&&gcd(buc[j],gg))  cnt++;
            }
        }
        solve(q[i].l,q[i].r);
        ans[q[i].id]=cnt;
    }
    // print
    for(int i=1;i<=m;i++)
        printf("%d\n",ans[i]);
    return 0;
}
// 有前缀和的性质，但是由于k在变，没法直接预处理前缀和 //
// 数论分块 + Mobius //
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e4+5;
int n,a,b,c,d,k;
int mu[maxn],sum_mu[maxn],pri[maxn],cnt;bool isnp[maxn];
void linear(int n)
{
    cnt=0;mu[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!isnp[i])pri[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else    mu[i*pri[j]]=-mu[i];
        }
    }
}
void pre()
{
    linear(5e4+1);
    // 预处理莫比乌斯函数的前缀和 //
    sum_mu[0]=0;
    for(int i=1;i<=5e4+1;i++)
        sum_mu[i]=sum_mu[i-1]+mu[i];
    return;
}
int ccnt(int n,int m,int k)
{
    n=n/k,m=m/k;
    int top=min(n,m);
    int r,l=1,res=0;
    while(l<=top)
    {
        r=min(n/(n/l),m/(m/l));
        res+=(sum_mu[r]-sum_mu[l-1])*(n/l)*(m/l);
        l=r+1;
    }
    return res;
}
int main(void)
{
    cin>>n;
    pre();
    while(n--)
    {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&k);
        int ans;
        ans=ccnt(b,d,k)-ccnt(a-1,d,k)-ccnt(b,c-1,k)+ccnt(a-1,c-1,k);
        printf("%d\n",ans);
    }
    return 0;
}
// 约数个数和 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e4+5;
int pri[maxn],cnt,mu[maxn],sum[maxn];
bool isnp[maxn];
void linear_mu(int n)
{
    cnt=0;mu[1]=1;
    sum[0]=0,sum[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!isnp[i])pri[++cnt]=i,mu[i]=-1;
        for(int j=1;j<=n&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else    mu[i*pri[j]]=-mu[i];
        }
        sum[i]=sum[i-1]+mu[i];
    }
    return;
}
ll g[maxn],n,m,T;
void pre(int n)    //O(n*sqrt(n))
{
    for(ll i=1;i<=n;++i)
    {
        ll res=0;
        for(ll l=1,r;l<=i;l=r+1){r=i/(i/l);res+=(r-l+1)*(i/l);}
        g[i]=res;
    }
    return;
}
ll solve(ll n,ll m)  // O(T*sqrt(n))
{
    ll ans=0;
    ll top=min(m,n);
    for(ll l=1,r;l<=top;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=(sum[r]-sum[l-1])*g[n/l]*g[m/l];
    }
    return ans;
}
int main(void)
{
    int num=5e4+2;
    linear_mu(num);
    pre(num);
    // 预处理
    cin>>T;
    while(T--)
    {
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",solve(n,m));
    }
    return 0;
}
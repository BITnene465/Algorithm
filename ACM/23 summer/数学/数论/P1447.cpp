// 能量采集 //
// 计算 \sum(i=1~n)\sum(j=1~m)(2*gcd(i,j)-1) n,m<=1e5//
// 莫反习题 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
ll n,m;
ll pri[maxn],mu[maxn],sum[maxn],cnt;bool isnp[maxn];
void linear(int n)
{
    sum[0]=0,sum[1]=1,mu[1]=1;
    cnt=0;
    for(ll i=2;i<=n;++i)
    {
        if(!isnp[i])pri[++cnt]=i,mu[i]=-1;
        for(ll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            mu[i*pri[j]]=-mu[i];
        }
        sum[i]=sum[i-1]+mu[i];
    }
}
ll ssum(ll n,ll m)
{
    ll res=0;
    for(ll l=1,r;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        res+=(sum[r]-sum[l-1])*(m/l)*(n/l);
    }
    return res;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    if(n>m)swap(n,m);
    linear(n);
    //
    ll ans=0;
    for(ll r,l=1;l<=n;l=r+1)
    {
        r=min(n/(n/l),m/(m/l));
        ans+=(r+l)*(r-l+1)/2*ssum(n/l,m/l);
    }
    ans=2*ans-m*n;
    cout<<ans<<endl;
    return 0;
}


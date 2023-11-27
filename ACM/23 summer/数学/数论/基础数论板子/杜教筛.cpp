// 板子：杜教筛 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e6+10;
ll mu[maxn],phi[maxn],sum_mu[maxn],sum_phi[maxn];
ll T,n;
ll pri[maxn],cnt;bool isnp[maxn];
void linear()
{
    int n=maxn-1;
    cnt=0;mu[1]=1;phi[1]=1;
    sum_mu[0]=sum_phi[0]=0;
    sum_mu[1]=sum_phi[1]=1;
    for(int i=2;i<=n;++i)
    {
        if(!isnp[i]){pri[++cnt]=i;mu[i]=-1;phi[i]=i-1;}
        for(int j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;phi[i*pri[j]]=phi[i]*pri[j];break;}
            else
            {
                mu[i*pri[j]]=-mu[i];
                phi[i*pri[j]]=phi[i]*phi[pri[j]];
            }
        }
        sum_mu[i]=sum_mu[i-1]+mu[i];
        sum_phi[i]=sum_phi[i-1]+phi[i];
    }
    return;
}
// 杜教筛 + 记忆化搜索 //
map<ll,ll> mp1;
ll du_sieve_mu(ll n)
{
    if(n<maxn)  return sum_mu[n];
    if(mp1.count(n))    return mp1[n];
    // 数论分块
    ll res=1;
    for(ll l=2,r;l<=n;l=r+1){r=n/(n/l);res-=(r-l+1)*du_sieve_mu(n/l);}
    return mp1[n]=res;
}
map<ll,ll> mp2;
ll du_sieve_phi(ll n)
{
    if(n<maxn)  return sum_phi[n];
    if(mp2.count(n))    return mp2[n];
    // 数论分块
    ll res=n*(n+1)/2;
    for(ll l=2,r;l<=n;l=r+1){r=n/(n/l);res-=(r-l+1)*du_sieve_phi(n/l);}
    return mp2[n]=res;
}
int main(void)
{
    cin>>T;
    linear();
    while(T--)
    {
        cin>>n;
        printf("%lld %lld\n",du_sieve_phi(n),du_sieve_mu(n));
    }
    return 0;
}
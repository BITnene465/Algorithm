#include<bits/stdc++.h>
using namespace std;
typedef __int128_t ll;
const ll mod=(ll)1<<64;
const ll maxn=2e6+5;
ll n,cnt,pri[maxn],phi[maxn];
ll sum[maxn];
bool vis[maxn];
ll calc(ll l,ll r)
{
    return r*(r+1)*(2*r+1)/6-l*(l-1)*(2*l-1)/6;
}
void linear_euler_phi(ll n)
{
    phi[1]=1;cnt=0;
    sum[0]=0;sum[1]=1;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i])pri[++cnt]=i,phi[i]=i-1;
        for(ll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j])phi[i*pri[j]]=phi[i]*phi[pri[j]];
            else
            {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
        }
        sum[i]=sum[i-1]+phi[i];
    }
}
map<ll,ll> mp;
ll du(ll n)
{
    if(n<maxn)return sum[n];
    if(mp.count(n))return mp[n];
    // 数论分块
    ll res=n*(n+1)/2;
    for(ll l=2,r;l<=n;l=r+1){r=n/(n/l);res-=(r-l+1)*du(n/l);}
    return mp[n]=res; // 记忆化搜索 
}
int main(void)
{
    scanf("%lld",&n);
    linear_euler_phi(maxn-1);
    ll ans=0;
    for(ll l=1,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        ans+=calc(l,r)*(2*du(n/l)-1);
    }
    ans=ans%mod;
    cout<<(unsigned long long)ans<<endl;
    return 0;
}
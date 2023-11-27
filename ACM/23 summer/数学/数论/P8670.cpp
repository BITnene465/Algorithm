// P8670 蓝桥杯国赛B 矩阵求和 //
// 莫反 or euler function //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const ll maxn=1e7+5;
ll n,cnt,pri[maxn],phi[maxn];
bool vis[maxn];
void linear_euler_phi(ll n)
{
    phi[0]=0;phi[1]=1;cnt=0;
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
    }
}
int main(void)
{
    scanf("%lld",&n);
    linear_euler_phi(n);
    ll ans=0;
    for(ll d=1;d<=n;++d)
    {
        ll tmp=0;
        for(ll k=1;k<=n/d;++k)
        {
            tmp+=2*phi[k]%mod;
        }
        ans+=d*d*(tmp-1)%mod;
    }
    cout<<ans%mod<<endl;
    return 0;
}
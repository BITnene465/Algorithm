// 一道简单（困难）的数学题 //
#include<bits/stdc++.h>
using namespace std;
typedef __int128_t ll;    // 大杀器
const ll maxn=5e6+5;
ll p,n;
ll S[maxn],pri[maxn],cnt,phi[maxn];bool isnp[maxn];
ll read()
{
    ll x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
ll calc(ll l, ll r)
{return (r*(r+1)*(2*r+1)/6-(l-1)*l*(2*l-1)/6)%p;}
void linear()
{
    S[0]=0,S[1]=1,phi[1]=1,cnt=0;
    for(ll i=2;i<maxn;++i)
    {
        if(!isnp[i])pri[++cnt]=i,phi[i]=i-1;
        for(ll j=1;j<=cnt&&i*pri[j]<maxn;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0){phi[i*pri[j]]=phi[i]*pri[j];break;}
            else    phi[i*pri[j]]=phi[i]*phi[pri[j]];
        }
        S[i]=(S[i-1]+i*i%p*phi[i]%p)%p;
    }
}
map<ll,ll> mp;
ll du(ll n)
{
    if(n<maxn)return S[n];
    if(mp.count(n))return mp[n];
    ll res=(n*(n+1)/2%p)*(n*(n+1)/2%p)%p;
    for(ll l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res=((res-calc(l,r)*du(n/l))%p+p)%p;
    }
    return mp[n]=res;
}
int main(void)
{
    p=read();n=read();
    linear();
    ll ans=0;
    for(ll r,l=1;l<=n;l=r+1)
    {
        ll x=n/l;
        r=n/(n/l);
        ans=(ans+(du(r)-du(l-1)+p)%p*(x*(x+1)/2%p)*(x*(x+1)/2%p)%p)%p;
    }
    cout<<(long long)ans<<endl;
    return 0;
}
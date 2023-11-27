#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
// 需要 (a,mod)=1 //
// 能够计算出 0~deta(a,mod)-1中的一个解 //
ll bsgs(ll a,ll b,ll mod)
{
    a=a%mod+mod;
    b=b%mod+mod;   // 让a,b变成非负数
    map<ll,ll> mp;
    ll t=ceil(sqrt(mod)),cur=1;
    for(int d=1;d<=t;d++)
    {
        cur=cur*a%mod;
        mp[cur*b%mod]=(ll)d;
    }
    ll now=cur;
    for(int c=1;c<=t;c++)
    {
        if(mp[now])return (ll)c*t-mp[now];
        now=now*cur%mod;
    }
    return -1;   // 无解 
}
int main(void)
{
    ll a,b,p;
    cin>>p>>a>>b;
    ll x=bsgs(a,b,p);
    if(x==-1)cout<<"no solution"<<endl;
    else cout<<x<<endl;
    return 0;
}
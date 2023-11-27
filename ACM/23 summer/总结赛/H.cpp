#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e7+5;
ll ans=0;
bool is_yy(ll x)
{
    for(ll i=2;i<=sqrt(x)+1;i++)
    {
        if(x%i==0&&x/i%i==0)return 1;
    }
    return 0;
}
int main(void)
{
    ll n=1;
    double tmp=0;
    while(cin>>n)
    {
        ans=0;
    for(ll i=1;i<=n;++i)
    {
        if(is_yy(i))ans++;
        tmp=max(tmp,(double)ans/n);
    }
    cout<<"temp="<<tmp<<endl;
    }
    return 0;
}

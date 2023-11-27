#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e7+2;
ll n,m;
bool check(ll t)
{
    for(ll i=sqrt(t);i>=1&&t/i<=n;--i)
    {
        if(t%i==0)return true;
    }
    return false;
}   
int main(void)
{
    cin>>n>>m;
    ll x=sqrt(m);
    if(n<x)printf("-1\n");
    else if(n==x&&x*x<m)printf("-1\n");
    // 否则，一定有解 在m~x*x+2*x+1
    ll tmp=(x+1)*(x+1);
    for(ll t=m;t<=tmp;++t)
        if(check(t)){printf("%lld\n",t);break;}
    return 0;
}
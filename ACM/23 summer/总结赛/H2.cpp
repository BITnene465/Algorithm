#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long double x1=0.390;
const long double x2=0.393;
bool isyy(ll x)
{
    ll s=sqrt(x);
    for(ll i=2;i<=s;++i)
    {
        if(x%i==0&&x/i%i==0)return 1;
    }
    return 0;
}
ll k;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>k;
    ll mi,ma;
    if(k>=5000)
    {
        mi=k/x2,ma=k/x1;
        for(ll x=mi;x<=ma;++x)
        if(isyy(x)){cout<<x<<endl;return 0;}
    }
    ll cnt=0;
    for(ll x=1;x<=2*k;++x)
        if(isyy(x)){cnt++;if(cnt==k){cout<<x<<endl;return 0;}}
}
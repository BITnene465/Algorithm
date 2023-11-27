#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ans,n;
ll euler_phi(ll x)
{
    if(x==0)return 0;
    ll ans=x;
    for(ll i=2;i<=sqrt(x);i++)
    {
        if(x%i==0)
        {
            while(x%i==0)   x/=i;
            ans=ans/i*(i-1);
        }
    }
    if(x!=1)    ans=ans/x*(x-1);
    return ans;
}
int main(void)
{
    cin>>n;
    if(n==1)  // 特解
    {
        cout<<0<<endl;
        return 0;
    }
    // n>1的情况
    ans=1;
    for(ll i=0;i<=n-1;i++)
        ans+=2*euler_phi(i);
    cout<<ans<<endl;
    return 0;
}
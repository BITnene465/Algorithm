#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n;
set<ll> ans;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    if(n==1)
    {
        cout<<"None\n";
        return 0;
    }
    // solve
    ans.insert(1);    // 1还是得单独加，否则下面的j就得从-1开始了
    for(ll i=1;i*i<=n;++i)
    {
        if(n%i==0)
        {
            ll a=i,b=n/i;
            for(ll j=b-1;j<=n;j+=b)if((j-1)%a==0)ans.insert(j);
            for(ll j=b+1;j<=n;j+=b)if((j+1)%a==0)ans.insert(j);
        }
    }
    // 去重
    for(auto num:ans)cout<<num<<'\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 998244353;
ll n;
ll fib(ll n)
{
    if(n==0||n==1)return (ll)1;
    ll a = 1,b = 1;
    for(int i=1;i<=n;++i){
        ll tmp = b;
        b = (a + b)%mod;
        a = tmp;
    }
    return a;
}
int main(void)
{
    cin>>n;
    cout<<fib(n)<<endl;
    return 0;
}
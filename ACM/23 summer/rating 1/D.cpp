#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,b,a[1000005];
int main(void)
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    scanf("%lld",&b);
    //
    ll cnt = 0;
    for(ll i=1;i<=n-1;i++)
    {
        ll pos1,pos2;
        pos1 = upper_bound(a+1,a+n+1,a[i]+b) - (a+1);
        pos2 = lower_bound(a+1,a+n+1,a[i]+b) - (a+1);
        if(pos1>pos2)
            cnt+=pos1-pos2;
    }
    printf("%lld\n",cnt);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll P,Q,a[100005],n;
long long abs64(ll x)
{
    return x>0? x:-x;
}
int main(void)
{
    cin>>n>>P>>Q;
    if(P<Q) swap(P,Q);  // P>=Q
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    sort(a+1,a+n+1);
    ll ans = LONG_LONG_MAX;
    for(ll i=1;i<=n-1;i++)
    {
        ll pos1,pos2;
        ll temp = P*a[i]/Q;
        pos1 = lower_bound(a+1,a+n+1,temp) - (a+1);
        pos2 = upper_bound(a+1,a+n+1,temp) - (a+1);
        for(ll j=pos1-1;j<=pos2+1;j++)
            ans = min(ans,abs64(P*a[i]-Q*a[j]));
    }
    cout<<ans<<endl;
}
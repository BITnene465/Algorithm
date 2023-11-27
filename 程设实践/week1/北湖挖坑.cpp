#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
ll n,h,a[maxn],ans;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>h;
    a[0]=a[n+1]=h;
    for(ll i=1;i<=n;++i)
    {
        cin>>a[i];
        if(a[i]<a[i-1])ans+=a[i-1]-a[i];
    }
    cout<<ans<<endl;
    return 0;
}
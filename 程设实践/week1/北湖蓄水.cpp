//  O(n)预处理出两侧的最高列，然后O(n)求和 //
//  时间复杂度O(n)  //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e5+5;
ll Lma[maxn],Rma[maxn];
ll T,n,a[maxn],ans;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n;
        ans=0;
        a[0]=a[n+1]=0;Lma[0]=Rma[n+1]=0;
        for(ll i=1;i<=n;++i)cin>>a[i];
        for(ll i=1;i<=n;++i){Lma[i]=max(Lma[i-1],a[i]);}
        for(ll i=n;i>=1;--i){Rma[i]=max(Rma[i+1],a[i]);}
        for(ll i=1;i<=n;++i){ans+=min(Lma[i],Rma[i])-a[i];}
        cout<<ans<<endl;
    }
    return 0;
}
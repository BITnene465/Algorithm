// 裸DP可写,注意到每次都要讨论每一行是从左端点下去还是从右端点下去//
// 所以使用 f[i][0]表示走完前i行并且最终停在第i行左端点的最小步数， f[i][1]同理 //
// 一阶线性DP，时间复杂度 O(n) //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=2e4+5;
ll n,f[maxn][2],R[maxn],L[maxn];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>L[i]>>R[i];
    // init //
    f[1][0] = 2*R[1]-L[1]-1;
    f[1][1] = R[1]-1;
    // DP //
    for(ll i=2;i<=n;++i)
    {
        f[i][0]=min(f[i-1][0]+fabs(R[i]-L[i-1])+R[i]-L[i],f[i-1][1]+fabs(R[i]-R[i-1])+R[i]-L[i])+1;
        f[i][1]=min(f[i-1][0]+fabs(L[i]-L[i-1])+R[i]-L[i],f[i-1][1]+fabs(L[i]-R[i-1])+R[i]-L[i])+1;
    }
    // for(ll i=1;i<=n;++i)cout<<f[i][0]<<' '<<f[i][1]<<endl;
    cout<<min(f[n][0]+n-L[n],f[n][1]+n-R[n])<<endl;
    return 0;
}
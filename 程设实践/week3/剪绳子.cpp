// 二分一下 时间复杂度O(nlogn) //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll l,r,mid,L[10005],K,N;
bool check(ll c)
{
    ll sum=0;
    for(ll i =1;i<=N;++i)sum+=L[i]/c;
    return sum>=K;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>N;
    ll sum=0;
    for(ll i=1;i<=N;++i)cin>>L[i],sum+=L[i];
    cin>>K;
    if(sum<K){cout<<0<<endl;return 0;}
    l=0,r=sum;
    while(l<=r)
    {
        mid=l+r>>1;
        if(check(mid))l=mid+1;
        else r=mid-1;
    }  // 退出时，一定是 l=r+1 //
    cout<<r<<endl;
    return 0;
}
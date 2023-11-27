/*
这是一道最大化最小值的问题。这道题可以描述为：
给定一个n长度的数组，将数组分割成K+1个连续的子数组，求一种分割方法可以使得分割后的所有子数组的和的最小值，比其他分割方法得到的子数组的和最小值都大。要求输出这个最大的最小值。
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,a[1000721];
bool check(ll val)
{
    ll sum = 0;
    ll cnt = 0;
    for(ll i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum>=val)
        {
            sum = 0;
            cnt++;
        }
        if(cnt>=k+1)    return true; 
    }
    return false;
}
int main(void)
{
    cin>>n>>k;
    for(ll i=1;i<=n;i++)
        scanf("%d",a+i);
    ll l,r;
    l = 1, r=LONG_LONG_MAX-1;
    ll mid;
    while(l<=r)
    {
        mid = (r+l)/2;
        if(check(mid))  l=mid+1;
        else    r=mid-1;
    }
    printf("%lld\n",r);
    return 0;
}
// 本质是求逆序对 //
// 归并排序并在过程中求逆序对 时间复杂度 O(nlogn)//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=3e5+5;
ll n,cnt,a[maxn],b[maxn];
void merge_cross(ll l,ll mid,ll r)
{
    ll i=l,j=mid+1,k=1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])b[k++]=a[i++];
        else b[k++]=a[j++],cnt+=mid-i+1;   // 在此处计数逆序对
    }
    if(i==mid+1)while(j<=r)b[k++]=a[j++];
    else        while(i<=mid)b[k++]=a[i++];
    // copy
    for(i=l,k=1;i<=r;++i,++k)a[i]=b[k];
}
void merge_sort(ll l,ll r)
{
    if(l==r)return;
    ll mid=l+r>>1;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    merge_cross(l,mid,r);
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    cnt=0;
    merge_sort(1,n);
    cout<<cnt<<endl;
    return 0;
}
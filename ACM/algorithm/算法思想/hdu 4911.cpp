// hdu 4911 "inversion" //
// 归并求逆序对,求完顺便也排序了 //
#include<bits/stdc++.h>
using namespace std;
#define N 100000
typedef long long ll;
ll a[N],b[N];
ll cnt;
void merge(ll left,ll mid,ll right)
{
    ll i,j,k;
    i=left,j=mid+1,k=0;
    while(i<=mid&&j<=right)
    {
        if(a[i]>a[j])
        {
            b[k++]=a[j++];
            cnt += mid-i+1;
        }
        else    b[k++]=a[i++];
    }
    // 此处有遗漏 //
    // 把排好序的b拷贝到a //
    for(i=0;i<k;++i)    a[left+i]=b[i];
}
void mergesort(ll left,ll right)
{
    if(left<right)
    {
        ll mid = (left+right)/2;
        mergesort(left,mid);
        mergesort(mid+1,right);
        merge(left,mid,right);
    }
}
int main(void)
{
    ll n,k;
    cin>>n>>k;   
    for(ll i=0;i<n;++i)     scanf("%lld",a+i);
    cnt = 0;
    mergesort(0,n-1);
    if(cnt<=k)  printf("0\n");
    else    printf("%lld\n",cnt-k);
    return 0;
}
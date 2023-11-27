// 本质是求逆序对，可以归并O(nlogn)解决 //
// 但是本题要先将每个名字标序号并且整理出打乱后的序列，使用STL map 可以O(nlogn)解决 //
// 总时间复杂度O(nlogn) //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int n,arr[maxn];ll cnt;string s;map<string,int> mp;
int b[maxn];  // 作为临时数组
void merge_cross(int a[],int l,int mid,int r)
{
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]>a[j])
        {
            cnt=cnt+mid-i+1;
            b[k++]=a[j++];
        }
        else
            b[k++]=a[i++];
    }
    if(i==mid+1)
        while(j<=r)b[k++]=a[j++];
    else
        while(i<=mid)b[k++]=a[i++];
    // 拷贝回a
    for(int t=0;t<=r-l;++t)   a[l+t]=b[t];
    return;
}
void merge_sort(int a[],int l,int r)
{   
    if(l==r)return;
    int mid=l+r>>1;
    merge_sort(a,l,mid);
    merge_sort(a,mid+1,r);
    merge_cross(a,l,mid,r);
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        mp[s]=i;
    }
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        arr[i]=mp[s];
    }
    // 数逆序对
    cnt=0;
    merge_sort(arr,1,n);
    cout<<cnt<<endl;
    return 0;
}
// 写好二分代码也是技术活  O(nlogn)//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[200005],b[200005];
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",b+i);
        a[i] = a[i] - b[i];
    }
    sort(a+1,a+n+1);   // 升序
    ll cnt = 0;
    // 只要找 (i,j) i<j 使得a[i] + a[j] > 0即可
    for(int i=1;i<n;i++)
    {
        int l = i+1;
        int r = n;     // 一定保证 l<=r 否则会死循环
        int mid;
        while(l<=r)
        {
            mid = (r+l)/2;
            if(a[mid]+a[i]>0)   r=mid-1;
            else    l=mid+1;
        }
        // 退出时 ,一定是 l=r+1, 并且l代表a[i]+a[j]>0 的最小下标j ，r是a[i]+a[j]<=0 的最大下标j
        if(l!=n+1)  cnt+=n-l+1;
    }
    cout<<cnt<<endl;
}
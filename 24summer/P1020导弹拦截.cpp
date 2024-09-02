// 导弹拦截，由于数据原因， 只能使用 O(nlogn) 的算法，故需要二分
#include<bits/stdc++.h>
using namespace std;
int n, ans1, ans2;
int arr[500005], f[500005], dp[500005];  
// dp[i] 表示以i结尾的最长单调不增子序列的长度，f[x] 表示长度为x的单调不增子序列的结尾的最大值（最宽松的一个序列）(由于都是正数，所以初始化为 0)
int g[500005];   // g[i]单增
int bs(int l, int r, int value)
{
    int mid;
    while(l <= r){
        mid = l + r >> 1;
        if(value <= f[mid]) l = mid+1;
        else r = mid-1;
    }
    return r;
}
int bs2(int l, int r, int value)
{
    int mid;
    while(l <= r)
    {
        mid = l + r >> 1;
        if(value <= g[mid]) r = mid-1;
        else l = mid+1;
    }
    return l;
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int x;
    n = 0;
    while(cin >> x)
        arr[++n] = x;
    // pro1   dp + bs
    dp[0] = 0;
    dp[1] = 1; f[1] = arr[1];
    for(int i=2;i<=n;++i)
    {
        dp[i] = 1 + bs(1, i-1, arr[i]);
        f[dp[i]] = max(f[dp[i]], arr[i]);
    }
    ans1 = 0;
    for(int i=1;i<=n;++i)
        ans1 = max(ans1, dp[i]); 

    // pro2   greedy + bs
    int ans2 = 1;
    g[1] = arr[1];
    for(int i=1;i<=n;++i){
        int idx = bs2(1, ans2, arr[i]);
        if(idx>ans2) g[++ans2]=arr[i];   // 没找可行的
        else g[idx] = arr[i];
    }
    cout << ans1 << endl;
    cout << ans2 << endl;
    return 0;
}
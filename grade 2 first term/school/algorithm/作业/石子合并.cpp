// 区间DP经典入门，由于数据太小，可以直接暴力DP（无需决策单调优化） 
// 但是环形
#include<bits/stdc++.h>
using namespace std;
int n, arr[205], sum[205], f1[205][205], f2[205][205], ans1, ans2;  
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    sum[0] = 0;
    for(int i=1;i<=n;++i){cin>>arr[i]; arr[i+n]=arr[i];}
    for(int i=1;i<=2*n;++i) sum[i] = sum[i-1] + arr[i];
    // DP
    for(int i=1;i<=2*n;++i)f1[i][i]=f2[i][i]=0;
    for(int l=2;l<=2*n;++l)
    {
        for(int i=1;i<=2*n-l+1;++i)
        {
            int j = i+l-1;
            f1[i][j] = 0;
            f2[i][j] = INT_MAX;
            for(int k=i;k<=j-1;++k)
            {
                f1[i][j] = max(f1[i][j], f1[i][k] + f1[k + 1][j] + sum[j] - sum[i - 1]);
                f2[i][j] = min(f2[i][j], f2[i][k] + f2[k + 1][j] + sum[j] - sum[i - 1]);
            }
        }
    }
    // get answer
    ans1 = 0;
    for (int i = 1; i <= n; ++i)
        ans1 = max(ans1, f1[i][i + n - 1]);
    ans2 = INT_MAX;
    for (int i = 1; i <= n; ++i)
        ans2 = min(ans2, f2[i][i + n - 1]);

    cout<<ans2<<endl;
    cout<<ans1<<endl;
    return 0;
}
// 区间DP
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, A[105], dp[105][105], s[105][105];   // s用于记录最佳分隔点
void Print_correct_path(ll l, ll r)   // 利用最佳决策点来构造答案
{
    if(l==r){
        cout<<"A"<<l;
        return;
    }
    ll pos = s[l][r];
    cout<<"(";
    Print_correct_path(l, pos);
    Print_correct_path(pos+1, r);
    cout<<")";
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n;
    for(ll i=0;i<=n;++i)cin>>A[i];  // A[0] ~ A[n]
    // DP
    for(ll i=1;i<=n;++i)dp[i][i] = 0;
    for(ll l=2;l<=n;++l)
    {
        for(ll i=1;i<=n-l+1;++i)
        {
            ll j = i+l-1;
            dp[i][j] = LONG_LONG_MAX;
            for(ll k=i;k<=j-1;++k)
            {
                if(dp[i][j] > dp[i][k]+dp[k+1][j]+A[i-1]*A[k]*A[j]){
                    dp[i][j] = dp[i][k] + dp[k + 1][j] + A[i - 1] * A[k] * A[j];
                    s[i][j] = k;
                }
            }
        }
    }
    // print
    cout<<dp[1][n]<<endl;
    if(n==1)cout<<"(A"<<1<<")"<<endl;
    else {Print_correct_path(1, n);cout << endl;}
    
    return 0;
}
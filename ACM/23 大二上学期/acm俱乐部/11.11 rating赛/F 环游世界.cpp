// 首先这是一个DAG 采用DP
// TLE 最后一个
#include<bits/stdc++.h>
using namespace std;
// typedef long long ll;
const int maxn = 100005;
int n, l[maxn], r[maxn], hot[maxn], dp[maxn];
int dfs(int x)
{
    if(x==1)return 0;
    if(dp[x])   return dp[x];   // 负无穷也会返回
    dp[x] = INT_MIN;
    for(int v=l[x];v<=r[x];++v)
        if(dfs(v)+hot[x]+v-x>dp[x])dp[x]=dp[v]+hot[x]+v-x;
    return dp[x];
}
int main(void)
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i) scanf("%d", hot+i);
    for(int i=2;i<=n;++i) scanf("%d %d", l+i, r+i);
    printf("%d\n", dfs(n)+hot[1]);
    return 0;
}
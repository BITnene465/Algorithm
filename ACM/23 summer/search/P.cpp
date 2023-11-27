// 旅行问题 ， DAG，求以一个顶点为起点的最长路径 //
//  DAG DP //
#include<bits/stdc++.h>
using namespace std;
int n,m;   // n个点，m条边
int dp[100005];  // 即题目所求
int in[100005];
int out[100005];  // 记录出度和入度
vector<int> g[100005];
// 记忆化搜索
int dfs(int u)
{
    if(dp[u]!=0)  return dp[u];
    if(out[u]==0)   return dp[u]=1;   // 朴素情况
    int ans = 0;
    for(auto v:g[u])
        ans = max(ans,1+dfs(v));     // 不要把dfs(v)错写成dp[v]
    return dp[u]=ans;
}
int main(void)
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        g[v].push_back(u);    // v->u
        in[u]++;
        out[v]++;
    }
    for(int i=1;i<=n;i++)
        if(!in[i])  dfs(i);    // 对入度为0的点进行dfs
    for(int i=1;i<=n;i++)
        printf("%d\n",dp[i]);
    return 0;
}
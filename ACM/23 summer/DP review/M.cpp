#include<bits/stdc++.h>
using namespace std;
const int N = 3e3+1;
int stone[N];
vector<int> tree[N];
int n;
int dp[N];   // dp[i]表示放置于点i是否有必胜策略,不必赢就必输
int dfs(int u)
{
    if(dp[u]!=-1)  return dp[u];
    else
    {
        int ans = 0;
        for(int i=0;i<tree[u].size();i++)
        {
            int v = tree[u][i];
            ans = ans|(1-dfs(v));
        }
        return dp[u]=ans;
    }
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",stone+i);
    for(int i=1;i<=n-1;i++)   // 建立有向图（且由定义一定是DAG）
    {
        int u,v;
        scanf("%d %d",&u,&v);
        if(stone[u]>stone[v])   tree[u].push_back(v);    // 大数指向小数
        else if(stone[u]<stone[v])  tree[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
        dp[i] = -1;            // 初始化
    for(int i=1;i<=n;i++)
        dfs(i);
    for(int i=1;i<=n;i++)
        if(dp[i]==1)    printf("%d ",i);
    printf("\n");
    return 0;
}
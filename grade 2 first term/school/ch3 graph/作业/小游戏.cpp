// 树形DP,无需记忆化，不会重复
#include<bits/stdc++.h>
using namespace std;
vector<int> tr[1505];
int dp[1505][2], n, root;
void init(int n)
{
    for(int i=0;i<n;++i)tr[i].clear();
}
void dfs(int rt)
{
    dp[rt][1] = 1;
    dp[rt][0] = 0;
    for(auto child: tr[rt]){
        dfs(child);
        dp[rt][0] += dp[child][1];
        dp[rt][1] += min(dp[child][1], dp[child][0]);
    }
}
int main(void)
{
    while(~scanf("%d",&n))
    {
        init(n);
        for(int i=1;i<=n;++i)
        {
            int u,v,num;
            scanf("%d:(%d)", &u, &num);
            if(i==1)root=u;   // 题目特性
            for(int j=1;j<=num;++j)
            {
                scanf("%d", &v);
                tr[u].push_back(v);
            }
        }
        dfs(root);
        printf("%d\n", min(dp[root][1], dp[root][0]));
    }
    return 0;
}
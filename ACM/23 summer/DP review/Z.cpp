#include<bits/stdc++.h>
using namespace std;
const int N = 6e3+5;
int n;
int r[N];
int up[N];    // i的上司是up[i]
vector<int> a[N]; 
int dp[N][2];
void dfs(int u)
{
    dp[u][1] = r[u];
    dp[u][0] = 0;
    for(auto child:a[u])
    {
        dfs(child);
        dp[u][1] = dp[u][1] + dp[child][0];
        dp[u][0] = dp[u][0] + max(dp[child][0],dp[child][1]);
    }
    return;
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)   
        scanf("%d",r+i);
    for(int i=1;i<=n-1;i++)
    {   
        int u,fa;
        scanf("%d %d",&u,&fa);
        up[u] = fa;
        a[fa].push_back(u);
    }
    int root=1;
    while(up[root]!=0)  root=up[root];
    dfs(root);
    cout<<max(dp[root][0],dp[root][1])<<endl;
    return 0;
}
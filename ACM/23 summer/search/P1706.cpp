#include<bits/stdc++.h>
using namespace std;
int n;
int vis[10];
int ans[10];
void dfs(int d)
{
    if(d==n+1)
    {
        for(int i=1;i<=n;i++)
            printf("%5d",ans[i]);
        printf("\n");
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            vis[i] = 1;
            ans[d] = i;   // ¼ÇÂ¼´ð°¸
            dfs(d+1);
            vis[i] = 0;
        }
    }
}
int main(void)
{
    cin>>n;
    dfs(1);
    return 0;
}
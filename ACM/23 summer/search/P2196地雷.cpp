#include<bits/stdc++.h>
using namespace std;
int a[22],G[22][22],n;bool vis[22];
int ans,path[22],ans_path[22],ans_stp;
void dfs(int s,int sum,int stp)
{
    sum+=a[s];path[stp]=s;
    bool flag=0;
    vis[s]=1;
    for(int i=1;i<=n;++i)
        if(G[s][i]&&!vis[i])dfs(i,sum,stp+1),flag=1;
    if(!flag&&ans<sum){ans=sum;memcpy(ans_path,path,sizeof path);ans_stp=stp;}
    vis[s]=0;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int i=1;i<=n-1;++i)for(int j=i+1;j<=n;++j)cin>>G[i][j];
    a[n+1]=0;
    for(int i=1;i<=n;++i)G[n+1][i]=1;   // n+1作为超级起点
    dfs(n+1,0,0);
    for(int i=1;i<=ans_stp;++i)cout<<ans_path[i]<<' ';
    cout<<'\n';
    cout<<ans<<'\n';
    return 0;
}
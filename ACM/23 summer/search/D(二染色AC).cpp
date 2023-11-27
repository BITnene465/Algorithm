#include<bits/stdc++.h>
using namespace std;
vector<int> g[10005];
int ans;
int n,m;
int vis[10005];
int flag[10005]; // 0表示染白色，1表示染黑色
queue<int> q;
void bfs(int s)
{
    int cnt[2];  // 记录白色点和黑色点个数
    cnt[0] = cnt[1] = 0;
    vis[s] = 1;
    flag[s] = 0;   // 染白色
    cnt[0]++;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v:g[u])
        {
            if(!vis[v])
            {
                vis[v] = 1;
                flag[v] = 1-flag[u]; 
                cnt[flag[v]]++;
                q.push(v);
            }
            else    // 判断是否出现错误
            {
                if(flag[v]!=1-flag[u])
                {
                    ans = 1e5;
                    return;
                }
            }
        }
    }
    // 找二染色中颜色较小的数
    ans += min(cnt[1],cnt[0]);
    return;
}
int main(void)
{
    cin>>n>>m;
    int u,v;
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans = 0;
    // 由于图不一定联通，所以要全部bfs一遍
    for(int s=1;s<=n;s++)
        if(!vis[s])
        {
            bfs(s);
            if(ans==1e5)    
            {cout<<"Impossible"<<endl;
            return 0;}
        }
    cout<<ans<<endl;
    return 0;
}
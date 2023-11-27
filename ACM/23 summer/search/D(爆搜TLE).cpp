// 封锁阳光大学 //
// 爆搜 TLE //
#include<bits/stdc++.h>
using namespace std;
vector<int> g[10005];
int ans;
int n,m;
bool flag[10005];  // 初始化为false
void dfs(int cur,int num,int m)   // cur为当前搜索的点，num为已放置的河蟹数量，m为当前剩余边数
{
    if(m==0){
        if(ans>num) ans = num;
        return;
    }
    if(cur>n)   return;  //越界
    if(flag[cur])   dfs(cur+1,num,m);
    dfs(cur+1,num,m);    // 不取cur点
    for(auto v:g[cur])    flag[v] = true;
    dfs(cur+1,num+1,m-g[cur].size());
    for(auto v:g[cur])    flag[v] = false; // 复原
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
    ans = 1e5;
    dfs(1,0,m);
    if(ans<1e5) cout<<ans<<endl;
    else    cout<<"Impossible"<<endl;
    return 0;
}
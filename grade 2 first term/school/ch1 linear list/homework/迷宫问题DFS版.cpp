#include<bits/stdc++.h>
using namespace std;
#define NOS "There is no solution!"
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,table[105][105],vis[105][105],cnt,ans[10005][2];
bool flag;
void Dfs(int x,int y)
{
    if(flag)return;  // 如果已经找到一个答案了，直接返回
    // 没找到答案，继续搜索 //
    vis[x][y]=1;
    ++cnt;
    vis[x][y]=1;
    ans[cnt][0] = x;
    ans[cnt][1] = y;
    if(x==n&&y==m)  // 到达终点
    {
        flag = 1;
        return;
    }
    for(int i=0;i<4;++i)
    {
        int nx=x+dx[i],ny=y+dy[i];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&!table[nx][ny])Dfs(nx,ny);
    }
    if(flag)return;   // 为什么此处要加这个？ 防止找到答案后还复原（当然也可以在找到答案之后，将cnt复制一份来解决）
    --cnt;
    vis[x][y]=0;   // 复原
    return;
}
void printPath()
{
    for(int i=1;i<=cnt;++i)cout<<'<'<<ans[i][0]<<','<<ans[i][1]<<'>'<<' ';
    cout<<'\n';
    return;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cin>>table[i][j];
    Dfs(1,1);
    if(!flag){cout<<NOS<<endl;return 0;}
    printPath();
    return 0;
}
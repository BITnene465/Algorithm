// 马的遍历 //
#include<bits/stdc++.h>
using namespace std;
int x,y;
int m,n;  // n行m列
int dis[401][401];
struct node{
    int x,y;
};
const int dx[8] = {1,1,-1,-1,2,2,-2,-2};
const int dy[8] = {2,-2,2,-2,1,-1,1,-1};
void bfs(int x,int y)
{
    queue<node> q;
    node now;
    node next;
    // Init
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            dis[i][j] = -1;
    //
    next.x = x;
    next.y = y;
    q.push(next);
    dis[x][y] = 0;
    while(!q.empty())
    {
        now = q.front();
        q.pop();
        for(int i=0;i<8;i++)
        {
            next.x = now.x+dx[i];
            next.y = now.y+dy[i];
            if(next.x>n||next.x<1||next.y>m||next.y<1)  continue;   // 越界
            if(dis[next.x][next.y]==-1)   // 距离还没有更新过
            {
                q.push(next);
                dis[next.x][next.y] = dis[now.x][now.y]+1;
            }
        }
    }
    return;
}
int main(void)
{
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    bfs(x,y);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
            printf("%-5d",dis[i][j]);
        printf("\n");
    }
    return 0;
}
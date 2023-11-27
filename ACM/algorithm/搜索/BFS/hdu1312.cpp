// hdu1312 "red and black" //
// 类似于迷宫问题，BFS暴搜即可 //
#include<bits/stdc++.h>
using namespace std;
int dir[4][2] ={{1,0},{0,-1},{-1,0},{0,1}};   
char room[21][21];     // 棋盘
int vis[21][21];      // 访问数组
int ans = 0;
int x_max,y_max;
bool check(pair<int,int> dot)
{
    if(dot.first>=1&&dot.first<=x_max&&dot.second>=1&&
    dot.second<=y_max&&room[dot.first][dot.second]=='.'&&
    !vis[dot.first][dot.second])
        return true;
    else
        return false;
}
void bfs(int dx,int dy)
{
    queue<pair<int,int>> q;    // 队列用于存储点

    pair<int,int> start;
    start.first = dx;
    start.second = dy;
    // 起点入队列
    q.push(start);
    vis[dx][dy] = 1;
    ++ans;
    while(!q.empty())
    {
        pair<int,int> next;
        start = q.front();
        for(int i=0;i<4;i++)
        {
            next.first = start.first + dir[i][0];
            next.second = start.second + dir[i][1];
            if(check(next))
            {
                q.push(next);
                vis[next.first][next.second] = 1;
                ++ans;
            }
        }
        q.pop();
    }
    return;
}
int main(void)
{
    scanf("%d %d",&x_max,&y_max);
    getchar();
    int i,j;
    int dx,dy;
    for(i=1;i<=x_max;i++)
    {
        for(j=1;j<=y_max;j++)
        {
           cin>>room[i][j];
           if(room[i][j]=='@')
           {
                dx = i;     // 读入起点
                dy = j;
           } 
        }
        getchar();
    }
    bfs(dx,dy);
    cout<<ans<<endl;
    return 0;
}
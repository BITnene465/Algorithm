//  01迷宫  //
#include<bits/stdc++.h>
using namespace std;
char s[1005][1005];
int n,m;
string str;
int fri[10005][1005];
int vis[10005][10005];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
struct node{
    int x,y;
};
queue<node> q;  
vector<node> ttt;    // 存储经过的点，之后用于赋值
void bfs(int x,int y)
{
    // init
    int cnt = 0;
    ttt.clear();
    //
    struct node no;
    struct node ne;
    ne.x = x;
    ne.y = y;
    q.push(ne);
    vis[x][y] = 1;
    ++cnt;
    ttt.push_back(ne);
    while(!q.empty())
    {
        no = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            ne.x = no.x+dx[i];
            ne.y = no.y+dy[i];
            if(ne.x>n||ne.x<1||ne.y>n||ne.y<1)  continue;
            if(!vis[ne.x][ne.y]&&s[ne.x][ne.y]!=s[no.x][no.y])
            {
                q.push(ne);
                vis[ne.x][ne.y] = 1;
                ++cnt;
                ttt.push_back(ne);
            }
        }
    }
    // 赋值
    for(auto it:ttt)
        fri[it.x][it.y] = cnt;
    return;
}
int main(void)
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>str;
        for(int j=1;j<=n;j++)
            s[i][j] = str[j-1];
    }
    while(m--)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(!vis[x][y])  
            bfs(x,y);
        printf("%d\n",fri[x][y]);
    }
    return 0;
}
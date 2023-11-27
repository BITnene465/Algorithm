#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;  // n行m列，a个感染源，b个领主
int dis[501][501];
const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};
int vis[501][501];
vector<pair<int,int>> pos;
vector<pair<int,int>> lord;
queue<pair<int,int>> q;
void bfs(pair<int,int> p)
{
    memset(vis,0,sizeof(vis));
    pair<int,int> no,ne;
    ne = p;
    q.push(ne);
    dis[ne.first][ne.second] = 0;
    vis[ne.first][ne.second] = 1;
    while(!q.empty())
    {
        no = q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            ne.first = no.first + dx[i];
            ne.second = no.second + dy[i];
            if(ne.first>n||ne.first<1||ne.second>m||ne.second<1)    continue;
            if(!vis[ne.first][ne.second])
            {
                q.push(ne);
                vis[ne.first][ne.second] = 1;
                dis[ne.first][ne.second] = min(dis[ne.first][ne.second],dis[no.first][no.second]+1);  // 更新
            }
        }
    }
}
int main(void)
{
    cin>>n>>m>>a>>b;
    int t1,t2;
    for(int i=1;i<=a;i++)
    {
        scanf("%d %d",&t1,&t2);
        pos.push_back(make_pair(t1,t2));
    }
    for(int i=1;i<=b;i++)
    {
        scanf("%d %d",&t1,&t2);
        lord.push_back(make_pair(t1,t2));
    }
    //
    memset(dis,126,sizeof(dis));    // 初始化
    for(auto it:pos)
    {
        bfs(it);
    }
    for(auto it:lord)
    {
        printf("%d\n",dis[it.first][it.second]);
    }
    return 0;
}
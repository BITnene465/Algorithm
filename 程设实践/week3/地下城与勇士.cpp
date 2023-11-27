// 还是最短路，采用Bfs，无权，但是有限制，多增一维时间维度 //

#include<bits/stdc++.h>
using namespace std;
struct State
{
    int x,y;
    int t;
    State(int x,int y,int t):x(x),y(y),t(t){};
};
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};
bool vis[105][105][1005];    // 断定最短步数不会超过305,并以此来剪枝
int T,n,m,k,sx,sy,ex,ey,ans;
char s[105][105];
void Bfs()
{
    queue<State> q;
    ans=-1;
    q.push(State(sx,sy,0));
    vis[sx][sy][0]=1;
    while(!q.empty())
    {
        auto st=q.front();q.pop();
        for(int i=0;i<4;++i)
        {
            auto tmp=State(st.x+dx[i],st.y+dy[i],st.t+1);
            // cout<<tmp.x<<' '<<tmp.y<<' '<<tmp.t<<endl;
            // 把下面的 tmp.t>1000删掉反倒过了，我不理解 //
            if(tmp.x<=0||tmp.y<=0||tmp.x>n||tmp.y>m||s[tmp.x][tmp.y]=='#'||(s[tmp.x][tmp.y]=='*'&&tmp.t%k!=0)||vis[tmp.x][tmp.y][tmp.t])continue;  // 跳过
            if(tmp.x==ex&&tmp.y==ey){ans=tmp.t;return;}
            q.push(tmp);
            vis[tmp.x][tmp.y][tmp.t]=1;
        }
    }
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        memset(vis,0,sizeof(vis));
        cin>>n>>m>>k;
        for(int i=1;i<=n;++i)for(int j=1;j<=m;++j){cin>>s[i][j];if(s[i][j]=='S')sx=i,sy=j;else if(s[i][j]=='E')ex=i,ey=j;}
        // for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)cout<<s[i][j];
        Bfs();
        cout<<ans<<endl;
    }
    return 0;
}
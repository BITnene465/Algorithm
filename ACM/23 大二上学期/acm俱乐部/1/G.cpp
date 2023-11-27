// 还有错，还得改

#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
char line[10];
int table[10][10];
int flex[10][10];
vector<int> able[10][10];  // 可行域
pair<int,int> nxt[10][10];
const int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
bool isnprime(int x)
{
    if(x==2||x==3||x==5||x==7||x==11||x==13||x==17)return false;
    return true;
}
bool isok(int x, int y)
{
    for(int i=0;i<4;++i)
    {
        int newx = x+dir[i][0], newy= y+dir[i][1];
        if(newx>n||newx<1||newy>m||newy<1||table[newx][newy]==-1)continue;
        if (isnprime(table[x][y] + table[newx][newy]))return false;
    }   
    return true;
}
bool isok2(int x, int y)
{
    for (int i = 0; i < 4; ++i)
    {
        int newx = x + dir[i][0], newy = y + dir[i][1];
    if (flex[newx][newy] && table[newx][newy]!=-1 && isnprime(table[x][y]+table[newx][newy]))return false;
    }
    return true;
}
void dfs(pair<int, int> now)
{   
    int x = now.first, y = now.second;
    if(x==0 && y==0)
    {
        ans++;
        return;
    }
    for(auto val: able[x][y])
    {
        table[x][y] = val;
        if(isok2(x, y))dfs(nxt[x][y]), printf("%d ", val);
    }
    table[x][y] = -1;
    return;
}
int main(void)
{
    scanf("%d %d", &n, &m);
    int x=0,y=0;
    for(int i=0;i<n;++i)
    {
        scanf("%s", line+1);
        for(int j=1;j<=m;++j)
        {
            if(line[j]=='?'){
                flex[i][j] = 1;
                table[i][j] = -1;
                nxt[x][y] = make_pair(i, j);
                x = i, y = j;
            }
            else table[i][j] = line[j]-'0';
        }
    }
    // 预处理 able
    pair<int,int> now = nxt[0][0];
    while(now.first!=0||now.second!=0)
    {
        for(int i=0;i<=9;++i)
        {
            table[now.first][now.second] = i;
            if(isok(now.first, now.second))able[now.first][now.second].push_back(i);
        }
        now = nxt[now.first][now.second];
    }
    // 搜索
    dfs(nxt[0][0]);
    printf("%d\n", ans);
    return 0;
}
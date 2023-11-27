#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int table[maxn][maxn];
int min_turn[maxn][maxn];   // 到达该点的最小转向次数
int m, n, st_x, st_y, ed_x, ed_y;
int direct[4][2] = {{0, 1},{0, -1},{1, 0},{-1, 0}};
struct Point
{
    int x, y; 
    int dir; 
    int turn;
    Point(int x, int y, int dir, int turn):x(x), y(y), dir(dir), turn(turn){};
};// 就算是同一个点，不同的方向也有不同的优势
bool bfs()
{
    queue<Point> q;
    for (int i = 0; i < 4; i++)
    { // 初始化四个方向的点
        int x, y;
        x = st_x + direct[i][0];
        y = st_y + direct[i][1];
        min_turn[x][y] = 1;
        q.push(Point(x, y, i, 1));
    }
    while (!q.empty())
    {
        Point now = q.front(); q.pop();
        if (now.x == ed_x && now.y == ed_y) return true;
        for (int i = 0; i < 4; i++)
        { // 对当前点遍历四个方向
            Point nxt = Point(now.x + direct[i][0], now.y + direct[i][1], i, now.turn);
            if (nxt.dir != now.dir) nxt.turn++;

            if (nxt.turn > 3 || nxt.x < 0 || nxt.y < 0 || nxt.x > m - 1 || nxt.y > n - 1) continue;
            if (table[nxt.x][nxt.y] != 0 && table[nxt.x][nxt.y] != table[ed_x][ed_y]) continue;
            if (min_turn[nxt.x][nxt.y] == 0 || min_turn[nxt.x][nxt.y] >= nxt.turn) min_turn[nxt.x][nxt.y] = nxt.turn, q.push(nxt);                
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> m >> n;
    for (int i = 0; i < m; i++)for (int j = 0; j < n; j++)cin >> table[i][j];
    cin >> st_x >> st_y >> ed_x >> ed_y;
    if(bfs()) cout<< "TRUE" << endl;
    else cout<< "FALSE" << endl;
    return 0;
}
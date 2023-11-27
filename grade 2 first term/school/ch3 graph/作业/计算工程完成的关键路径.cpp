/**
 * @file 计算工程完成的关键路径.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 数据结构与算法题解
 * @version 0.1
 * @date 2023-11-03
 * 
 * @copyright Copyright (c) 2023
 * 
 */

// 由于需要判环，所以直接使用拓扑排序更新
// 不是Dijkstra不好，而是拓扑跑的更快（仅限DAG）
// 要输出 字典序最小的 拓扑排序 ,使用小根堆
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1005;
char mark[maxn][55];
struct edge
{
    int to;
    int w;
    edge(int v, int w) : to(v), w(w){};
};
vector<edge> g[maxn];
vector<int> pre[maxn]; // 用来记录路径
vector<int> nxt[maxn]; // pre反向版本，用于打印路径
int n, m, dis[maxn], in[maxn], out[maxn], s, t;
priority_queue<int, vector<int>, greater<int>> q;    // 默认大根堆，要改成 小根堆！！！
int topuOrder[maxn], tot;
bool topu()
{
    for (int u = 0; u < n; ++u)
    {
        if (in[u] == 0)
            s = u; // 源点
        else if (out[u] == 0)
            t = u; // 终点
    }
    q.push(s);
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top();
        q.pop();
        topuOrder[++tot] = u; // 以出队序列为拓扑序列
        for (auto ed : g[u])
        {
            int v = ed.to, w = ed.w;
            // 更新最短路相关
            if (dis[v] < dis[u] + w)
            {
                pre[v].clear();
                pre[v].push_back(u);
                dis[v] = dis[u] + w;
            }
            else if (dis[v] == dis[u] + w)
                pre[v].push_back(u);
            in[v]--;
            if (!in[v])
                q.push(v);
        }
    }
    if (tot == n)
        return true;
    return false;
}
char line[1005];
void getData()
{   // 这题的读取真恶心
    scanf("%d,%d", &n, &m);
    getchar();
    scanf("%s", line);
    int l = strlen(line);
    int num = 0;
    for (int i = 0; i < l;)
    {
        int j = 0;
        while ((line[i + j] != ',') && (line[i + j] != '\0'))
        {
            mark[num][j] = line[i + j];
            j++;
        }
        mark[num++][j] = '\0';
        // printf("%s\n", mark[num - 1]);
        i = i + j + 1;
    }
    getchar();
    int u, v, w;
    for (int i = 1; i <= m; ++i)
    {
        getchar();
        scanf("%d,%d,%d", &u, &v, &w);
        getchar();
        getchar();
        // printf("%d %d %d", u, v, w);
        g[u].push_back(edge(v, w));
        out[u]++;
        in[v]++;
    }
}
int path[maxn], cnt;
void dfs(int now)
{
    path[++cnt]=now;
    if(now == t){  // 到达终点，得到一条路径
        printf("%s", mark[path[1]]);
        for(int i=2;i<=cnt;++i)
            printf("-%s", mark[path[i]]);
        printf("\n");
        --cnt;
        return;
    }
    for(int i=0;i<nxt[now].size();++i) dfs(nxt[now][i]);
    --cnt;
    return;
}
void printPath()
{
    // pre数组构建了一个关于最长路全部信息的DAG
    // 先把pre数组构建的图转换成反向图
    for(int i=0;i<n;++i)
        for(int u : pre[i])nxt[u].push_back(i);
    // 对nxt进行字典序排序
    for(int i=0;i<n;++i) sort(nxt[i].begin(), nxt[i].end());    
    // 对nxt构成的DAG进行dfs
    dfs(s);
}
void printTopologicalOrder()
{
    printf("%s", mark[topuOrder[1]]);
    for(int i=2;i<=tot;++i)
        printf("-%s", mark[topuOrder[i]]);
    printf("\n");
}
int main(void)
{
    getData();
    if (!topu())
    {
        printf("NO TOPOLOGICAL PATH\n");
        return 0;
    }
    printTopologicalOrder();
    printPath();
    return 0;
}

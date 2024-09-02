// TSP 即 找最小的哈密顿回路 //
#include<bits/stdc++.h>
using namespace std;
struct edge{
    int v;
    int w;
    edge(int v, int w):v(v), w(w){};
};
vector<edge> g[1005];
int n, m;
bool instk[1005], flag;
int vAns[1005], ans, s;   // s为起点
int curAns[1005], top;
void Dfs_TSP(int x, int cur_val)    // 由于cur_val在回溯的时候不好复原，所以放到递归栈内
{
    if(top==n && x==s){  
        flag = 1; // 有答案
        if(cur_val<ans) {
            ans = cur_val;
            for(int i=1;i<=n;++i){
                vAns[i] = curAns[i];
            }
        }
        return;
    }
    if(instk[x]){
        return;
    }
    curAns[++top] = x;
    instk[x] = 1;
    for(auto ed: g[x]){
        int v = ed.v;
        int w = ed.w;
        Dfs_TSP(v, cur_val + w);
    }
    --top;
    instk[x] = 0;
}
void PrintAns()
{
    if(!flag) {
        cout<< "该图没有哈密顿回路" <<endl;
        return;
    }

    for(int i=1;i<=n;++i){
        cout<< vAns[i] << ' ';
    }
    cout<< "\n权值为:" << ans << '\n';
    return;
}
int main(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v,w;
        cin>>u>>v>>w;
        g[u].push_back(edge(v, w));
        g[v].push_back(edge(u, w));
    }
    ans = 0x3f3f3f3f;
    flag = 0;
    top=0;
    s = 1;  // 设置起点
    Dfs_TSP(s, 0);
    PrintAns();
    return 0;
}

/*
input: 
4 6
1 4 4
1 2 30
1 3 6
2 3 5
2 4 10
3 4 20
*/
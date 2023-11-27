// BFS 解法 //
// BFS + 状态图 //
#include<bits/stdc++.h>
using namespace std;
#define N 8
int ans;
typedef struct node{
    int queen[N+1];
    int deep;
} NODE;
queue<NODE> q;   // 队列实现BFS
bool check(NODE cur)
{    
    for(int i=1;i<cur.deep;++i)
    {
        if(cur.queen[i]==cur.queen[cur.deep]||abs(cur.deep-i)==abs(cur.queen[cur.deep]-cur.queen[i]))
            return false;
    }
    return true;
}
void bfs()
{
    NODE cur;
    // 初始化 cur , 不初始化会导致无结果//
    for(int i=1;i<=N;++i)
        cur.queen[i] = 0;
    cur.deep = 0;  // 目前深度为0
    q.push(cur);
    
    while(!q.empty())
    {
        NODE next;
        next = cur;
        next.deep++;
        if(next.deep<=N)
        {
            for(int i=1;i<=N;++i)
            {
                next.queen[next.deep] = i;   // deep行第i列为皇后
                if(check(next))
                {
                    q.push(next);
                }
            }
        }
        // 出去的判断是否为解
        if(cur.deep==N)
            ++ans;
        q.pop();   // 弹出顶层元素
        cur = q.front();  // 更新cur
    }
    return;
}
int main(void)
{
    ans = 0;
    bfs();
    cout<<ans<<endl;
    return 0;
}
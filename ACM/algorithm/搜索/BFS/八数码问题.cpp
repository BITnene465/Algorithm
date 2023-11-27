// BFS + 状态图 //
#include<bits/stdc++.h>
using namespace std;
// node 存储数码状态图， 即排列 + 目前步数 //
typedef struct node
{
    int state[9];
    int dis;
} NODE;
// 队列用于bfs搜索 //
queue<NODE> q;
int dir[4] = {1,-3,-1,3};
int ans;
int vis[362880];
NODE start,goal;      // 起点和终点,在main函数中读取数据
bool end_check(NODE cur)
{
    int i;
    for(i=0;i<9;i++)
    {
        if(cur.state[i]!=goal.state[i])
            return false;
    }
    return true;
}

// cantor函数部分
const int fact[] = {1,1,2,6,24,120,720,5040,40320,362880}; //阶乘常数
int cantor(int state[],int n)
{
    int i,j;
    int result = 0;
    for(i=0;i<n;i++)
    {
        int counted = 0;
        for(j=i+1;j<n;j++)
        {
            if(state[i]>state[j])
                ++counted;    // 判断state[i]是当前未出现数的第几个，从第0个开始数
        }
        result += counted*fact[n-i-1];
    }
    return result;
}
// cantor end 
// 并不是题目要求，但是来点过程的可视化
void print_cur(NODE cur)
{
    int i,j;
    for(i=0;i<3;++i)
    {
        for(j=0;j<3;++j)
            printf("%2d",cur.state[3*i+j]);
        printf("\n");
    }
    printf("step=%d\n\n",cur.dis);
    printf("=================================\n\n");
    return;
}
//

int bfs(NODE cur)
{
    q.push(cur);
    //
    print_cur(cur);
    //
    if(end_check(cur))
        return 0;
    
    while(!q.empty())
    {
        // 找0的位置 //
        int loc;
        for(loc=0;loc<9;loc++)
        {
            if(cur.state[loc]==0)
                break;
        }
        //
        for(int i=0;i<4;i++)
        {
            int newloc = loc+dir[i];
            if(newloc>=0&&newloc<9)
            {
                NODE next = cur;
                next.dis = cur.dis + 1;
                swap(next.state[loc],next.state[newloc]);
                if(!vis[cantor(next.state,9)])
                {
                    q.push(next);
                    //
                    print_cur(next);
                    //
                    if(end_check(next))
                        return next.dis;
                }
                else
                    continue;
            }
            else
                continue;
        }
        q.pop();
        cur = q.front();
    }
    return -1;   // 没找到
}

int main(void)
{
    int i;
    for(i=0;i<9;++i)
        scanf("%d",start.state+i);
    start.dis = 0;
    for(i=0;i<9;++i)
        scanf("%d",goal.state+i);
    
    ans = bfs(start);
    cout<<ans<<endl;
    return 0;
}

/*
sample:
1 2 3 0 8 4 7 6 5
1 0 3 8 2 4 7 6 5
output:
2
sample:
2 8 3 1 0 4 7 6 5
1 2 3 8 0 4 7 6 5
output:
4
*/
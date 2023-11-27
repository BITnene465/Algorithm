//  皇后问题  //
// DFS 解法 //
#include<bits/stdc++.h>
using namespace std;
#define N 8
int ans;
int queen[N+1];    // 记录每一行Queen所在的列，因为每一行有且只有一个queen 
bool check(int x,int y)
{
    for(int i=1;i<x;++i)
    {
        if(queen[i]==y||abs(queen[i]-y)==abs(i-x))
            return false;
    }
    return true;
}
void dfs(int n)
{
    if(n>N)
    {
        ++ans;
        return;    // 找到一个有效解，回溯
    }
    else
    {
        for(int i=1;i<=N;i++)
        {
            if(check(n,i))
            {
                queen[n] = i;
                dfs(n+1);
            }
            else
                continue;
        }
        return;    // 此分支无解，回溯
    }
}
int main(void)
{
    ans = 0;
    dfs(1);
    cout<<ans<<endl;
    return 0;
}
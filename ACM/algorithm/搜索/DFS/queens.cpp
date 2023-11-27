// d:1~N  i:0~N-1  //
// 皇后问题 //
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#define N 8
using namespace std;
vector<int> ans;
int vis[N+1][N+1];
int cou = 0;
void show()
{
    for(int i=0;i<ans.size();i++)
    {
        int t = ans[i];
        for(int j=0;j<N;j++)
        {
            char ch;
            if(j==t)    ch = '#';
            else    ch = '*';
            printf("%c ",ch);
        }
        printf("\n");
    }
    printf("\n\n");   
    return;
}
bool check(int d,int x)
{
    int i,j;
    for(i=d-1,j=x-1;i>=1&&j>=0;i--,j--)
    {
        if(ans[i-1]==j)
            return false;
        else
            continue;
    }
    for(i=d-1,j=x+1;i>=1&&j<N;i--,j++)
    {
        if(ans[i-1]==j)
            return false;
        else
            continue;
    }
    for(i=d-1;i>=1;i--)
    {
        if(ans[i-1]==x)
            return false;
        else
            continue;
    }
    return true;
}
void dfs(int d)
{
    if(d==N+1){
        cou++;
        show();
        return;
    }
    else{
        int i;
        for(i=0;i<N;i++)
        {
            if(check(d,i))
            {
                ans.push_back(i);    //表示第d行的第i个为皇后
                vis[d][i] = 1;
                dfs(d+1);
                vis[d][i] = 0;
                ans.pop_back();
            }
        }
    }
}
int main(void)
{
    dfs(1);
    cout<<"共有："<<cou<<"个"<<endl;
    getchar();
    return 0;
}
// 又是一道暴搜题 //
#include<bits/stdc++.h>
using namespace std;
int n, m, ans;
int queen[12];   
void printTable()
{
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            if(j==queen[i])printf("# ");
            else printf("* ");
        }
        printf("\n");
    }
    printf("\n\n\n");
}
bool judge()
{
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            bool flag = 0;
            for(int k=1;k<=n;++k){
                if(!queen[k])continue;
                if(i==k||j==queen[k]||abs(i-k)==abs(queen[k]-j)){flag=1;break;}   
            }
            if(!flag)return 0;
        }
    }
    return 1;
}
bool check(int row, int col)
{
    for(int i=1;i<=row-1;++i){
        if(queen[i]==0)continue;
        if(abs(queen[i]-col)==abs(row-i)||queen[i]==col)return 0;
    }
    return 1;
}
void Dfs(int x, int y)   // 搜索第x层，已经放置了y个皇后
{
    if(y==m){
        if(judge()){
            ans++;
            // printTable();
        }
        return;
    }
    if(x==n+1){
        return;   // 因为此时 y!=m
    }
    queen[x] = 0;
    Dfs(x+1, y);
    for(int i=1;i<=n;++i){
        if(check(x, i)){
            queen[x] = i;
            Dfs(x+1, y+1);
        }
    }
    queen[x] = 0;   // 最后必须复原！！！
}
int main(void)
{
    scanf("%d %d",&n,&m);
    Dfs(1, 0);  
    printf("%d\n",ans);
    return 0;
}
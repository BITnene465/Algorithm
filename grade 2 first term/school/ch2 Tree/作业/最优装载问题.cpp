// 01背包问题，但是要打印最优方案，（虽然一直觉得简单，但是上手后发现有点不好写） （可以使用 pre 数组来实现，但是此处用了个麻烦一点的 flag 数组来实现） //
// 采用 DP 算法 //
#include<bits/stdc++.h>
using namespace std;
const int maxw = 1e5 + 10;
const int maxn = 105;
int n,c,w[maxn],flag[maxn][maxw],dp[maxn][maxw];
void PrintPath(int n, int c)
{
    int stk[105],top=0;
    int val = dp[n][c];
    for(int i=n;i>=1;--i){
        if(flag[i][val]){
            val = val - w[i];
            stk[++top] = i;
        }
    }
    // Print
    while(top){printf("%d ",stk[top--]);}
    printf("\n");
    return;
}
int main(void)
{
    scanf("%d %d",&c,&n);
    for(int i=1;i<=n;++i)scanf("%d",w+i);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=c;++j){ 
            if(j>=w[i] && dp[i-1][j-w[i]]+w[i]>dp[i-1][j]){    // 一定要用大于号
                dp[i][j] = dp[i-1][j-w[i]] + w[i];
                flag[i][j] = 1;
            }
            else{
                dp[i][j] = dp[i-1][j];
                flag[i][j] = 0;
            }
        }
    }
    // print
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=c;++j){
    //         printf("%d ",flag[i][j]);
    //     }
    //     printf("\n");
    // }
    printf("%d\n",dp[n][c]);
    PrintPath(n, c);
    return 0;
}
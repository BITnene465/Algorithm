/**
 * @file 运动员最佳配对问题.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 爆搜 + 剪枝
 * @version 0.1
 * @date 2023-10-30
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// 直接暴搜 O(n!)， 一个类似于皇后问题的配对问题，转换为在一个 n*n 矩阵内找 n 个刚好占据每行每列的数中的最大和 //
#include<bits/stdc++.h>
using namespace std;
int man[13][13], feman[13][13], n;
int mat[13][13], best[15];   // best[i] 记录一个从第i行开始往后匹配的一个能力和上界（不一定准确）
int vis[13];
int ans;
// 还需要 剪枝，感觉会TLE
void dfs(int i, int sum)  // 搜索第 i 个man
{
    if(i==n+1){
        ans = max(ans,sum);
        return;
    }
    if(sum+best[i]<=ans)return;     // 剪枝，防止TLE，快了不止一点点
    for(int j=1;j<=n;++j){
        if(vis[j]) continue;
        vis[j] = 1;
        dfs(i+1, sum+mat[i][j]);
        vis[j] = 0;  // 复原
    }
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",&man[i][j]);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d",&feman[i][j]);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)mat[i][j] = man[i][j] * feman[j][i];
    // 预处理 best 数组
    for(int i=n;i>=1;--i){
        int temp = 0;
        for(int j=1;j<=n;++j){
            temp = max(temp, mat[i][j]);
        }
        best[i] = temp+best[i+1];
    }
    dfs(1, 0);
    printf("%d\n",ans);
    return 0;
}
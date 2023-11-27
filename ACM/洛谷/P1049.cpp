// DP解法->化为01背包 //
#include<bits/stdc++.h>
using namespace std;
const int maxN = 31;
const int maxV = 20001;
int n,V;
int vol[maxN];
int dp[2][maxV];    // 前i件物品取，体积不超过j，所得最大价值
int solve()
{
    memset(dp[0],0,sizeof(dp[0]));    // 初始化
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<=V;j++)    // 从0开始更新
        {
            if(j>=vol[i])    dp[i%2][j] = max(dp[(i-1)%2][j-vol[i]]+vol[i],dp[(i-1)%2][j]);
            else    dp[i%2][j] = dp[(i-1)%2][j];
        }
    }
    return V-dp[(i-1)%2][V];
}
int main(void)
{
    scanf("%d%d",&V,&n);
    for(int i=1;i<=n;i++)
        scanf("%d",vol+i);
    
    cout<<solve()<<endl;
    return 0;
}
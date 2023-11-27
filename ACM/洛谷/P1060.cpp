// P1060 开心的金明 //
// dp解法，01背包 //
#include<bits/stdc++.h>
using namespace std;
const int Max_money = 30000;
const int Max_item = 25;
int dp[2][Max_money];   // dp[i][j]表示前i个物品，金额j所达到的最大价值
//   但是采用滚动数组以节省内存   //
struct node
{
    int w;
    int v;    // 直接价值
}item[Max_item];
int n,m;     // 分别为总钱数和要买的物品个数
int solve()
{
    memset(dp,0,sizeof(dp));    // 初始化
    int i;
    for(i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>=item[i].w)    dp[i%2][j] = max(dp[(i-1)%2][j-item[i].w]+item[i].v,dp[(i-1)%2][j]);
            else    dp[i%2][j] = dp[(i-1)%2][j];
        }
    }
    return dp[(i-1)%2][n];
}
int main(void)
{
    // 读入数据
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&item[i].w,&item[i].v);
        item[i].v = item[i].v*item[i].w;
    }
    //
    cout<<solve()<<endl;
    return 0;
}
// 01背包 ， dp数组需要二维，记录物品取放信息和重量信息 //
// 通过滚动数组减少空间复杂度 //
#include<bits/stdc++.h>
using namespace std;
const int item_num = 20;   //最多物品数
const int weight_max = 100;  //最大背包承重
typedef struct item{
    int w;
    int v;
}Item;
Item goods[item_num+1];
int N,W;      // N个物品，W背包总承重
int dp[2][weight_max+1];   //滚动dp数组 dp[i][j]原本表示前i个物品中取，重量为j的最大价值
void solve()
{
    memset(dp[0],0,sizeof(dp[0]));   // 将dp[0][i]全部初始化为0
    int i;
    for(i=0;i<N;++i)   // 一共要执行N次该循环
    {
        for(int j=0;j<=W;j++)
        {
            if(j<goods[i+1].w)     // 防止溢出
                dp[(i+1)%2][j] = dp[i%2][j];
            else
                dp[(i+1)%2][j] = max(dp[i%2][j],dp[i%2][j-goods[i+1].w]+goods[i+1].v);
        }   
    }
    // print
    cout<<"max_value="<<dp[i%2][W]<<endl;
}
int main(void)
{
    int T;  //测试用例数
    cin>>T;
    while(T--)
    {
        cin>>N>>W;
        for(int i=1;i<=N;++i)
            scanf("%d %d",&goods[i].w,&goods[i].v);
        solve();
    }
    return 0;
}


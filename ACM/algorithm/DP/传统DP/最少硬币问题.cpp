#include<bits/stdc++.h>
using namespace std;
const int VALUE = 5;  // 5种面值的硬币
const int coin[VALUE] = {1,5,10,25,50};  // 五种面值
const int money = 251;  // 定义最大金额
int Min[money];       // 不能和min函数重名了，表示面额为money时的最小硬币数
// 打表
void solve()
{
    // 初始化
    Min[0] = 0;
    for(int i=1;i<money;++i)
        Min[i] = INT_MAX;
    // 状态转移，同时防止溢出（这个写法真的很奇妙）
    for(int i=0;i<VALUE;++i)
        for(int j=coin[i];j<money;++j)
            Min[j] = min(Min[j],Min[j-coin[i]]+1);
    // 注1：若Min[i][j]表示考虑前i种硬币，面额为j的最小硬币数，使用一维滚动数组之后就是这么写的
    // 注2：类似于无限背包
}
int main(void)
{
    int m;
    solve();
    while(cin>>m)
        cout<<Min[m]<<endl;
    return 0;
}
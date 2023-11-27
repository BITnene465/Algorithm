// hdu 2069 "coin change" //
// 硬币总数 num <= 100 & 金额 <= 250 //
// 用更高维的dp来记录更详细的状态 //
#include<bits/stdc++.h>
using namespace std;
const int money = 251;
const int coin_num = 101;
const int type_num = 5;
const int type[type_num] = {1,5,10,25,50};
int dp[money][coin_num];    //dp[i][j]表示使用j枚硬币达到金额i的组合数
int ans[money];    //ans[i]表示金额i的合法方案数
void solve()
{
    // init //
    dp[0][0] = 1;   // 剩余的dp[i][0] = 0
    //
    for(int i=0;i<type_num;++i)
        for(int j=1;j<coin_num;++j)
            for(int k=type[i];k<money;++k)
                dp[k][j] = dp[k][j] + dp[k-type[i]][j-1];
    //
    for(int i=0;i<money;++i)
        for(int j=0;j<coin_num;++j)
            ans[i] += dp[i][j];
}
int main(void)
{   
    solve();
    int m;
    while(cin>>m)
        cout<<ans[m]<<endl;
    return 0;
}
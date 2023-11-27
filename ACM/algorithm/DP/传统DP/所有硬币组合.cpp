// 只要求方案数量，也可以用生成函数解决 //
#include<bits/stdc++.h>
using namespace std;
const int type_num = 5;
const int type[type_num] = {1,5,10,25,50};
const int money = 251;   // 最大面额
int dp[money];
void solve()
{
    // init start //
    for(int i=1;i<money;++i)
        dp[i] = 0;
    dp[0] = 1;    // 规定
    // init end //
    for(int i=0;i<type_num;++i)
        for(int j=type[i];j<money;++j)
            dp[j] = dp[j] + dp[j-type[i]];
}
int main(void)
{
    solve();
    int m;
    while(cin>>m)
        cout<<dp[m]<<endl;
    return 0;
}

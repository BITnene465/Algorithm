#include<bits/stdc++.h>
using namespace std;
const int VALUE = 5;  // 5种面值的硬币
const int coin[VALUE] = {1,5,10,25,50};  // 五种面值
const int money = 251;  // 定义最大金额
int Min[money];       // 不能和min函数重名了，表示面额为money时的最小硬币数
int min_path[money];  // 路径记录表
// 打表
void solve()
{
    // 初始化
    Min[0] = 0;
    for(int i=1;i<money;++i)
        Min[i] = INT_MAX;
    // 状态转移，同时防止溢出，同时记录路径
    for(int i=0;i<VALUE;++i)
        for(int j=coin[i];j<money;++j)
        {
            if(Min[j]>Min[j-coin[i]]+1)
            {
                Min[j] = Min[j-coin[i]]+1;
                min_path[j] = coin[i];    // 达到金额j的最后一枚硬币的面额为coin[i] 
            }
        }
}
void print_path(int m)
{
    while(m)
    {
        cout<<min_path[m]<<" ";
        m=m-min_path[m];
    }
    cout<<endl;
}
int main(void)
{
    int m;
    solve();
    while(cin>>m)      // 常用技巧，读到EOF结束
    {
        cout<<Min[m]<<endl;
        print_path(m);
    }
    return 0;
}
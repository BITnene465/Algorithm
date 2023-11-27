// 01背包进阶版->不装也能有价值//
// 最大的数不会超过10^9，所以还是用 int //
#include<bits/stdc++.h>
using namespace std;
const int maxFri = 1001;
const int maxMed = 1001;
int dp[2][maxMed];   
// 滚动数组，dp[i][j]表示和前i个好友对决，在使用j瓶药的情况下可获得最大经验值
struct node{
    int lose;
    int win;
    int use;
}fri[maxFri];
int n,x;
int solve()
{
    memset(dp[0],0,sizeof(dp[0]));
    int i;
    for(i=1;i<=n;i++)
    {
        for(int j=0;j<=x;j++)    // 注意必须从j=0开始更新 //
        {
            if(j<fri[i].use)    dp[i%2][j]=fri[i].lose+dp[(i-1)%2][j];
            else    dp[i%2][j] = max(fri[i].lose+dp[(i-1)%2][j],fri[i].win+dp[(i-1)%2][j-fri[i].use]);
        }
    }
    return dp[(i-1)%2][x];
}
int main(void)
{
    cin>>n>>x;
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&fri[i].lose,&fri[i].win,&fri[i].use);
    //
    long long ans = solve();     // 数据范围的锅，最后转换一下即可
    printf("%lld\n",5*ans);    
    return 0;
}

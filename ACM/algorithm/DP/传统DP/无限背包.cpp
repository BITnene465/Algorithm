// 无限背包 //
// 易于01背包，dp数组只需一维，记录重量信息即可 //
#include<bits/stdc++.h>
using namespace std;
const int item_num = 20;
const int weight_max = 100;
typedef struct item{
    int w;
    int v;
} Item;
Item goods[item_num+1];
int N,W;
int dp[weight_max];
void solve()
{
    memset(dp,0,sizeof(dp));  
    for(int i=1;i<=W;i++)    // dp[0]=0一定成立
        for(int j=1;j<=N;j++)
        {
            if(i>=goods[j].w)
                dp[i] = max(dp[i],dp[i-goods[j].w]+goods[j].v);
        }
    cout<<"max_value="<<dp[W]<<endl;
}
int main(void)
{
    int T;
    cin>>T;
    while(T--)
    {
        cin>>N>>W;
        for(int i=1;i<=N;i++)
            scanf("%d %d",&goods[i].w,&goods[i].v);
        solve();
    }
    return 0;
}
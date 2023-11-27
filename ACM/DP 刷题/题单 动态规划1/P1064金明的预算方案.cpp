// 类似 0/1 背包， 不过有五种决策：不选该主件，只选该主件，选主件+第一附件，选主件+第二附件，选主件+第一、二附件 //
// 构成一个分组背包模型 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e4+5;
const int maxm=61;
int dp[maxn],v[maxm][3],w[maxm][3],n,m;    // dp[i][j]表示前i个物品，j元，可得最大价值 -> 此处滚动数组省略第一维度
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int fac,p,q;
        cin>>p>>fac>>q;
        if(q)
        {
            if(v[q][1])
            {
                v[q][2]=fac*p;
                w[q][2]=p;
                continue;
            }
            v[q][1]=fac*p;
            w[q][1]=p;
            continue;
        }
        v[i][0]=fac*p;
        w[i][0]=p;
    }
    // DP
    // 起始dp全为0
    for(int i=1;i<=m;++i)
    {
        if(!w[i][0])continue;
        for(int j=n;j>=w[i][0];--j)
        {
            dp[j]=max(dp[j],dp[j-w[i][0]]+v[i][0]);
            if(w[i][1]&&j>=w[i][0]+w[i][1])dp[j]=max(dp[j],dp[j-w[i][0]-w[i][1]]+v[i][0]+v[i][1]);
            if(w[i][2]&&j>=w[i][0]+w[i][2])dp[j]=max(dp[j],dp[j-w[i][0]-w[i][2]]+v[i][0]+v[i][2]);
            if(w[i][1]&&w[i][2]&&j>=w[i][0]+w[i][1]+w[i][2])dp[j]=max(dp[j],dp[j-w[i][0]-w[i][1]-w[i][2]]+v[i][0]+v[i][1]+v[i][2]);
        }
    }
    // for(int i=1;i<=n;++i)cout<<dp[cnt][i]<<endl;
    cout<<dp[n]<<endl;
    return 0;
}
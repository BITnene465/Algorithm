// 一个无向图中有多少包含点1的k元环？ //
// A 图 rating赛1 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll mod =998244353;
ll n,m,k,f[5005][5005];   // f[i][j]表示顶点1到顶点j，i长的路径有多少条
ll sum[5005];   // 前缀和优化
vector<ll> g[5005];
int main(void)
{
    cin>>n>>m>>k;
    for(ll i=1;i<=m;i++)
    {
        ll u,v;
        scanf("%lld %lld",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    // #dp部分
    // ##初始化
    for(ll i=1;i<=n;i++)
        f[1][i] = 1;
    f[1][1] = 0;
    for(auto u:g[1])
        f[1][u] = 0;
    sum[1] = 0;
    for(ll i=1;i<=n;i++)
        sum[1] = sum[1] + f[1][i];
    // ##递推部分
    for(ll i=2;i<=k;i++)
    {   
        sum[i] = 0;
        for(ll j=1;j<=n;j++)
        {
            f[i][j] = (sum[i-1] - f[i-1][j]%mod+mod)%mod;         // 防止出现
            for(auto u:g[j])
                f[i][j] = (f[i][j]%mod -  f[i-1][u]%mod+mod)%mod;
            sum[i] = (sum[i]+f[i][j])%mod;
        }
    }
    cout<<f[k][1]%mod<<endl;
    return 0;
}
// 贪心是人类的本性 但是不对//
// DP + 枚举 //
// AC //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
const int INF = 0x3f3f3f3f;
int a[maxn],n,o,ans,f[maxn][10*maxn];   // f[i][j] 考虑前i对数，把上-下调整到 j-5*n 所需要的最小步数  
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    o = 5*n;
    int sum=0;
    for(int i=1;i<=n;++i)
    {
        int b,c;
        cin>>b>>c;
        a[i]=b-c;
        sum+=a[i];
    }
    // init
    for(int i=1;i<=n;++i)for(int j=0;j<=10*n;++j)f[i][j]=INF;
    f[1][sum+o]=0;
    f[1][sum+o-2*a[1]]=1;
    // DP
    for(int i=2;i<=n;++i)
    {
        for(int j=0;j<=10*n;++j)
        {
            if(j-2*a[i]>=0&&j-2*a[i]<=10*n)f[i][j-2*a[i]]=min(f[i-1][j-2*a[i]],f[i-1][j]+1);
        }
    }
    // find
    int find1,find2;
    for(int i=o;i<=10*n;++i)if(f[n][i]!=INF){find1=i;break;}
    for(int i=o-1;i>=0;--i)if(f[n][i]!=INF){find2=i;break;}
    // cout<<find1<<' '<<find2<<endl;
    if(find1-o<o-find2)ans=f[n][find1];
    else if(find1-o==o-find2)ans=min(f[n][find1],f[n][find2]);
    else ans=f[n][find2-o];
    // cout<<f[n][find1]<<' '<<f[n][find2]<<endl;
    cout<<ans<<endl;
    return 0;
}
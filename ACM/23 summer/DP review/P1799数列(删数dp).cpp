// f[i][j] 表示前i个数，删掉j个数，前i个数中满足条件的整数的个数 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+5;
int f[maxn][maxn],n,a[maxn];
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    for(int j=0;j<=n;++j)f[0][j]=0;
    for(int i=1;i<=n;++i)
    {
        f[i][0]=f[i-1][0]+(a[i]==i);
        for(int j=1;j<=i;++j)f[i][j]=max(f[i-1][j]+(a[i]==(i-j)),f[i-1][j-1]);
    }
    int ans=0;
    for(int i=0;i<=n;++i)ans=max(ans,f[n][i]);
    cout<<ans<<endl;
    return 0;
}
// 多重求和，数论分段，转换到前缀和预处理进行优化 //
// 只有在 a>b>c 时才对总和有贡献 //
// 错啦 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=5005;
const ll mod=1<<32;
ll sum_c[maxn];
ll arr[maxn],n,ans;
void pre(ll c)
{
    sum_c[c-1]=0;
    for(int i=c;i<=n;i++)
        sum_c[i]=sum_c[i-1]+i/c;
    return;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    ans=0;
    for(int i=1;i<=n;++i)cin>>arr[i];
    for(ll c=1;c<=n-2;++c)
    {
        pre(c);
        for(ll b=c+1;b<=n-1;++b)
        {
            ll tmp=0;
            for(ll k=1;k<=n/b-1;++k)
            {
                tmp+=k*(sum_c[(k+1)*b-1]-sum_c[k*b-1]);
            }
            if(n%b!=0) tmp+=n/b*(sum_c[n]-sum_c[n/b*b-1]);
            else    tmp+=n/c;
            ans+=b/c*tmp;
        }
    }
    cout<<ans%mod<<endl;
    return 0;
}
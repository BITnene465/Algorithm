// Golden Sword //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,w,s;
ll f[5005][5005],a[5005];   // 空间够，就不用滚动数组优化了
deque<ll> q;
int main(void)
{
    cin>>n>>w>>s;
    for(ll i=1;i<=n;i++)
        scanf("%lld",a+i);
    // init_start
    for(ll i=1;i<=n;i++)
        for(ll j=0;j<=w;j++)
            f[i][j] = -INF;
    f[1][1] = a[1];
    // init_end
    for(ll i=2;i<=n;i++)
    {
        q.clear();   // 清空队列
        for(ll j=0;j<=min(w-1,s-1);j++)  // 初始化队列
        {
            while(!q.empty()&&f[i-1][q.back()]<=f[i-1][j])  q.pop_back();
            q.push_back(j);
        }
        for(ll j=1;j<=min(i,w);j++)
        {
            while(!q.empty()&&q.front()<j-1)    q.pop_front();
            if(j+s-1<=w)    //右侧区间改变，需要维护
            {
                while(!q.empty()&&f[i-1][q.back()]<=f[i-1][j+s-1])  q.pop_back();
                q.push_back(j+s-1);
            }
            if(f[i-1][q.front()]!=-INF) f[i][j] = f[i-1][q.front()]+j*a[i];
        }
    }
    ll ans = -INF;
    for(ll i=1;i<=w;i++)
        if(ans<f[n][i]) ans = f[n][i];
    cout<<ans<<endl;
    return 0;
}
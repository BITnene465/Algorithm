#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[505], b[505], ans;
bool vis[505];
void upd_b()
{
    for (ll i = 1; i <= n; ++i)
    {
        b[i] = 0;
        for (ll j = 1; i * j <= n; ++j)
            if(!vis[i*j])b[i] += a[i * j];
    }
}
int main(void)
{
    scanf("%lld", &n);
    for (ll i = 1; i <= n; ++i)
        scanf("%lld", a + i), ans+=a[i];
    upd_b();

    while(1){
        ll id=0, now=0;
        for (ll i = 1; i <= n; ++i)
        {
            if (vis[i])
                continue;
            if (b[i]<now){id=i;now=b[i];}
        }
        if(id==0)break;
        ans-=now;
        // ¸üÐÂ
        for(ll j=1;j*id<=n;++j)vis[j*id]=1;
        upd_b();
    }
    printf("%lld\n", ans);
    return 0;
}
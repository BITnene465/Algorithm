// DP + 线段树
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 100005;
ll n, l[maxn], r[maxn], hot[maxn], dp[maxn];
ll tr[maxn << 2 + 5];            
void update(ll cur, ll cl, ll cr, ll id, ll k) // 将 a[id]设置为 k,调用方法 update(1,1,n,id,k)
{
    if (id > cr || id < cl)
        return;
    if (cl == cr)
    {
        tr[cur] = k;
        return;
    }
    ll mid = cl + cr >> 1;
    update(2 * cur, cl, mid, id, k);
    update(2 * cur + 1, mid + 1, cr, id, k);
    tr[cur] = max(tr[2 * cur], tr[2 * cur + 1]);
    return;
}
ll query(ll cur, ll cl, ll cr, ll vl, ll vr) // 查询区间 a[vl]~a[vr] 的最大值 调用方法：query(1,1,n,vl,vr)
{
    if (cl > vr || cr < vl)
        return 0;
    if (vl <= cl && cr <= vr)
        return tr[cur];
    ll mid = cl + cr >> 1;
    return max(query(2 * cur, cl, mid, vl, vr), query(2 * cur + 1, mid + 1, cr, vl, vr));
}
int main(void)
{
    scanf("%lld", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%lld", hot + i);
    for (int i = 2; i <= n; ++i)
        scanf("%lld %lld", l + i, r + i);
    // 初始化线段树
    update(1, 1, n, 1, hot[1] + 1);
    for(int i=2;i<=n;++i) update(1, 1, n, i, LONG_LONG_MIN);
    // end
    for(int u=2;u<=n;++u)
    {
        dp[u] = query(1, 1, n, l[u], r[u]) + hot[u] - u; 
        update(1, 1, n, u, dp[u]+u);
    }
    printf("%lld\n", dp[n]);
    return 0;
}
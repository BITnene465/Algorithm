// 线段树优化 LIS //
// 时间复杂度 O(nlogn) //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll ans,n,dp[maxn],a[maxn],idx[maxn];
ll tr[maxn<<2+5];  // 用于实现线段树,初始时全为 0 ,用静态完全二叉树实现
void update(ll cur,ll cl,ll cr,ll id,ll k)   // 将 a[id]设置为 k,调用方法 update(1,1,n,id,k)
{
    if(id>cr||id<cl)return;
    if(cl==cr)
    {
        tr[cur]=k;
        return;
    }
    ll mid=cl+cr>>1;
    update(2*cur,cl,mid,id,k);update(2*cur+1,mid+1,cr,id,k);
    tr[cur]=max(tr[2*cur],tr[2*cur+1]);
    return;
}
ll query(ll cur,ll cl,ll cr,ll vl,ll vr)   // 查询区间 a[vl]~a[vr] 的最大值 调用方法：query(1,1,n,vl,vr)
{
    if(cl>vr||cr<vl)return 0;
    if(vl<=cl&&cr<=vr)return tr[cur];
    ll mid=cl+cr>>1;
    return max(query(2*cur,cl,mid,vl,vr),query(2*cur+1,mid+1,cr,vl,vr));
}
bool cmp(ll x,ll y)
{
    return    a[x]<a[y];
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(ll i=1;i<=n;++i)cin>>a[i],idx[i]=i;
    sort(idx+1,idx+n+1,cmp);   // idx[i]存储第i大的a数组元素的索引
    // DP
    dp[1]=1;
    update(1,1,n,1,1);
    for(ll i=2;i<=n;++i)
    {
        ll id = idx[i];
        dp[i] = query(1,1,n,1,id)+1;
        update(1,1,n,id,dp[i]);
    }
    // print
    for(ll i=1;i<=n;++i)ans=max(ans,dp[i]);
    cout<<ans<<endl;
    return 0;
}
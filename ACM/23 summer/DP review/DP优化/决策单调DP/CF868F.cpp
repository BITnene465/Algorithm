// AC //
// 决策单调,静态转移，使用分治法 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1e5+5;
const ll INF = 0x3f3f3f3f3f3f3f3f;
ll n,k,dep,a[maxn],f[maxn][25];   // f[i][j]表示考虑前i个数，分成j段，最小值
ll v_cnt,buc[maxn],lastL,lastR;     // 类似于莫队的暴力区间移动（但是比暴力预处理要好很多）
ll cnt(ll l,ll r)     
{
    while(lastL>l)  v_cnt+=buc[a[--lastL]]++;
    while(lastR<r)  v_cnt+=buc[a[++lastR]]++;
    while(lastL<l)  v_cnt-=--buc[a[lastL++]];
    while(lastR>r)  v_cnt-=--buc[a[lastR--]];  
    return v_cnt;
}
void solve(ll l,ll r,ll L,ll R)     // DP决策单调，分治法优化
{
    if(r<l) return;
    ll mid=l+(r-l>>1),id=-1,minn=INF;
    for(ll k=L;k<=min(R,mid-1);k++)
        if(id==-1||f[k][dep-1]+cnt(k+1,mid)<minn)  id=k,minn=f[k][dep-1]+cnt(k+1,mid);
    f[mid][dep] = minn;  // 更新f[mid]
    solve(mid+1,r,id,R);
    solve(l,mid-1,L,id);
}
int main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        buc[a[i]]++;
    }
    for(int i=1;i<=n;i++)
        v_cnt+=(buc[i]-1)*buc[i]/2;
    lastL=1,lastR=n;
    // init
    for(ll i=n;i>=1;i--)
        f[i][1] = cnt(1,i);
    // init_end
    for(ll i=2;i<=k;i++)
        dep=i,solve(1,n,1,n);
    cout<<f[n][k]<<endl;
    return 0;
}
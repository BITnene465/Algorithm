#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn = 1e5+5;
ll x[maxn],y[maxn],n;
ll X,Y;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>x[i]>>y[i];
    X=Y=0;
    // 先解决纵坐标 
    sort(y+1,y+n+1);
    ll y0=y[1+n>>1];
    for(int i=1;i<=n;++i)Y+=y[i]-y0>0?y[i]-y0:y0-y[i];
    // 再解决横坐标
    sort(x+1,x+n+1);
    for(int i=1;i<=n;++i)x[i]-=i;
    sort(x+1,x+n+1);
    ll x0=x[1+n>>1];
    for(int i=1;i<=n;++i)X+=x[i]-x0>0?x[i]-x0:x0-x[i];
    // print
    cout<<X+Y<<endl;
    return 0;
}
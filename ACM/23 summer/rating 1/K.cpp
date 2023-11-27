#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7;
ll t[41],v[41],n;
ll cnt;
void dfs(ll sumv,ll sumt,ll d,ll last)
{
    if(sumv==sumt&&d==last+1)  cnt++;
    if(d>n) return;
    dfs(sumv+v[d],sumt+t[d],d+1,d);
    dfs(sumv,sumt,d+1,last);
    return;
}
int main(void)
{
    cin>>n;
    for(ll i=1;i<=n;i++)
        scanf("%lld",t+i);
    for(ll i=1;i<=n;i++)
        scanf("%lld",v+i);
    dfs(0,0,1,0);
    cout<<cnt<<endl;
    return 0;
}
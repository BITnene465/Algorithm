#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,ans;
struct node{
    ll t;
    ll a;
}p[100005];
bool mycmp(node p1, node p2)
{
    return (1+2*p2.t)*p1.a > (1+2*p1.t)*p2.a;
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d %d",&p[i].t,&p[i].a);
    sort(p+1,p+1+n,mycmp);
    for(int i=1;i<=n;++i)ans+=p[i].t*p[i].a;
    ll cnt = 0;
    ll sum_t = 0;
    for(int i=1;i<=n;++i){
        ans += (2*sum_t + cnt)*p[i].a;
        cnt++;
        sum_t += p[i].t;
    }
    printf("%lld\n",ans);
    return 0;
}
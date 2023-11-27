#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, W, C, w[1000005];
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>W>>C;
    for(int i=1;i<=n;++i) cin>>w[i];
    sort(w+1, w+n+1);
    ll ans = 0;
    int i =1;
    while(C - w[i]>=0)
    {
        ans += W - w[i];
        C -= w[i];
        i++;
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll M=1e9+7;   // 大质数
const ll B=233317;     // 进制数
const ll maxn=1e4+1;
const ll maxm=1501;
ll h[maxn],Bpow[maxm];
ll n;
string s;
void pre()
{
    Bpow[0]=1;
    for(ll i=1;i<maxm;++i)
        Bpow[i]=Bpow[i-1]*B%M;
    return;
}
ll get_hash(string &s)
{
    int n=(int)s.length();
    ll res=0;
    for(int i=0;i<n;++i)
        res=(res+Bpow[n-1-i]*(ll)s[i])%M;
    return res;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    pre();
    for(ll i=1;i<=n;++i)
    {
        cin>>s;
        h[i]=get_hash(s);
    }
    sort(h+1,h+n+1);
    int ans=1;
    for(int i=1;i<=n-1;++i)
    {
        if(h[i+1]!=h[i])++ans;
    }
    cout<<ans<<endl;
    return 0;
}
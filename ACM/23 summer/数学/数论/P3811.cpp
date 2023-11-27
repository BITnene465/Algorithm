// 线性区间内所有整数的逆元 => 采用线性递推 //
// 模板题 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e6+5;
ll n,p;
// inverse--逆元//
ll inv[maxn];
int main(void)
{
    cin>>n>>p;
    inv[1]=1;
    for(ll i=2;i<=n;i++)
        inv[i]=((p-p/i)*inv[p-(p/i)*i])%p;
    for(ll i=1;i<=n;i++)
        printf("%d\n",inv[i]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e7+10;
// euler 筛法 O(n)//
ll n,cnt=0,pri[maxn];
bool vis[maxn];
void linear_prime(ll n)
{
    vis[1]=true;  // 1不是素数
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i])pri[++cnt]=i;
        for(ll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j]==0)break;
        }
    }
}
int main(void)
{
    n=100;
    linear_prime(n);
    printf("1~%lld的素数有：\n",n);
    for(ll i=1;i<=cnt;i++)
    {
        printf("%lld ",pri[i]);
        if(i%4==0)printf("\n");
    }
    printf("共有%lld个\n",cnt);
    return 0;
}
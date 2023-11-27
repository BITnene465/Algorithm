#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll maxn=1e7+10;
//筛法//
ll n,cnt,pri[maxn],phi[maxn];
bool vis[maxn];
void linear_prime(ll n)
{
    cnt=0;phi[0]=0;phi[1]=1;
    for(ll i=2;i<=n;++i)
    {
        if(!vis[i]){pri[++cnt]=i;phi[i]=i-1;}  // i是素数
        for(ll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j])    phi[i*pri[j]]=phi[i]*phi[pri[j]];  // 积性函数
            else
            {
                phi[i*pri[j]]=phi[i]*pri[j];
                break;
            }
        }
    }
}
int main(void)
{
    cin>>n;
    linear_prime(n);
    printf("1~%lld的欧拉函数：\n",n);
    for(ll i=1;i<=n;i++)
    {
        printf("phi(%lld)=%lld ",i,phi[i]);
        if(i%4==0)printf("\n");
    }
    return 0;
}
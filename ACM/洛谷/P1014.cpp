#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(void)
{
    ll N;
    ll x,y;
    scanf("%lld",&N);
    ll dif;
    ll n = (ll)sqrt(2*N);
    while(n*(n+1)/2<N) n++;
    dif = n*(n+1)/2 - N;
    //
    if(n%2==0)
    {
        y = 1+dif;
        x = n+1-y;
    }
    else
    {
        x = 1+dif;
        y = n+1-x;
    }
    printf("%lld/%lld\n",x,y);
    return 0;
}
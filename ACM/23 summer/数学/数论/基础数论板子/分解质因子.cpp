// B3715 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,T;
int main(void)
{
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld",&n);
        for(ll i=2;i<=sqrt(n)+1;i++)
        {
            if(n%i==0)
            {
                while(n%i==0)
                {
                    n=n/i;
                    printf("%lld ",i);
                }
            }
        }
        if(n!=1)printf("%lld ",n);
        printf("\n");
    }
    return 0;
}
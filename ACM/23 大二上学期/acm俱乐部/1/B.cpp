#include<bits/stdc++.h>
using namespace std;
long long n;
int main(void)
{
    scanf("%lld",&n);
    if(n%2==1){printf("-1\n");return 0;}
    while(n%2==0)n>>=1;
    printf("%lld\n",n);
    return 0;
}
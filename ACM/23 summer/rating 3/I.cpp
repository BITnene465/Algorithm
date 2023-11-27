#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,q,k,x,y;
int gcd(int x,int y)
{
    if(x<y)swap(x,y);
    int t;
    while(y)
    {
        t=x%y;
        x=y;
        y=t;
    }
    return x;
}
int main(void)
{
    cin>>n>>q>>k;
    while(q--)
    {
        scanf("%d %d",&x,&y);
        int g=gcd(x,y);
        if(abs(x-g)+abs(y-g)<=k)printf("lai\n");
        else    printf("rulai\n");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n, T;
int special = 142857;
bool isGood(int x)
{
    int l=1, base=1;
    int org=x;
    while(x=x/10)l++, base*=10;
    x = org;
    for(int i=1;i<l;++i)
    {
        x = x/base + x%base*10;
        if(x % org != 0) return false;
    }
    return true;
}
int calc(int n)
{
    int res = 0;
    if(n>=special)res++;
    int l = 1, base = 1;
    int x = n;
    while(x=x/10)l++, base=base*10+1;
    res += 9*(l-1);
    res += n/base;
    return res;
}
int main(void)
{
    // for(int i=1;i<=100000000;++i)
    //     if(isGood(i))printf("%d\n", i);
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d",&n);
        printf("%d\n", calc(n));
    }
    return 0;
}
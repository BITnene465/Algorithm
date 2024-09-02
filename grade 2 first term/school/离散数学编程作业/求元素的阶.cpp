// 模18整数加群的阶
#include<bits/stdc++.h>
using namespace std;
int gcd(int x, int y)
{   //  求两个数的最大公约数
    int t;
    if(x<y) swap(x, y);
    while(y)
    {
        t = y;
        y = x%y;
        x = t;
    }
    return x;
}
int main(void)
{
    int a;
    scanf("%d", &a);
    printf("%d\n", 18/gcd(18, a));   // 答案即 18/gcd(18, a)
    return 0;
}
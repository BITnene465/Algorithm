#include<bits/stdc++.h>
using namespace std;
int a[100001];
int g[100001];   // 区间gcd值，gcd[i][j]表示区间[i,j]的最大公约数
// 此处使用滚动数组进行压缩
int n;
int gcd(int x,int y)
{
    int t;
    if(x<y) swap(x,y);
    while(y)
    {
        t = x%y;
        x = y;
        y = t;
    }
    return x;
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        g[i] = a[i];   // 初始化
        if(a[i]==1)
        {
            printf("%d\n",n-1);
            return 0;
        }
    }
    for(int len=2;len<=n;len++)
    {
        for(int i=n-len+1;i>=1;i--)
        {
            int j = i+len-1;
            g[j] = gcd(g[j-1],a[j]);
            if(g[j]==1)  
            {
                printf("%d\n",len+n-2);
                return 0;
            }
        }
    }
    printf("-1\n");
    return 0;
}
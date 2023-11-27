// floyd 图的传递闭包 模板题 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
int f[maxn][maxn];
int n;
void floyd()
{
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                f[i][j]=f[i][j]|f[i][k]&f[k][j];
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            scanf("%d",&f[i][j]);
    floyd();
    for(int i=1;i<=n;i++)
        {for(int j=1;j<=n;j++)
            printf("%-2d",f[i][j]);
        printf("\n");
        }
    return 0;
}
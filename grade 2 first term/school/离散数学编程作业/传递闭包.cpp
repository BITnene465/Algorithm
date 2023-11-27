#include<bits/stdc++.h>
using namespace std;
int arr[10000];
int mat[100][100], n;
int main(void)
{
    // input
    int val;
    while(~scanf("%d", &val)) arr[++n] = val;
    n = (int)sqrt(n);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            mat[i][j] = arr[(i-1)*n+j];
    // DP
    for(int k=1;k<=n;++k)
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j)
                mat[i][j] = max(mat[i][j], mat[i][k]&mat[k][j]);
    for(int i=1;i<=n;++i)
    {
        printf("%d", mat[i][1]);
        for(int j=2;j<=n;++j)printf(" %d", mat[i][j]);
        printf("\n");
    }
    return 0;
}
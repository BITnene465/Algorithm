#include<bits/stdc++.h>
using namespace std;
int n, indeg[1005], outdeg[1005], g[1005][1005];
int main(void)
{
    scanf("%d", &n);
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)scanf("%d", &g[i][j]);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j){
            outdeg[i] += g[i][j];
            indeg[j] += g[i][j];
        }
    }
    if(n==5){
        for (int i = 1; i <= n - 1; ++i)
            printf("%d %d\n", outdeg[i], indeg[i]);
        printf("%d %d\n", outdeg[n], indeg[n]);
        return 0;
    }
    for(int i=1;i<=n;++i)printf("%d %d\n", outdeg[i], indeg[i]);
    return 0;
}
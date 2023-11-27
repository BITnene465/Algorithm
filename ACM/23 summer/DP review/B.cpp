#include<bits/stdc++.h>
using namespace std;
int arr[701];
int n;
int f[701][701][2];
void solve()
{
    
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    solve();
    if(f[1][n][0]==1)   printf("Yes\n");
    else    printf("No\n");
    return 0;
}
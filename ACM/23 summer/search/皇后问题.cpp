#include<bits/stdc++.h>
using namespace std;
int queen[14];   // 每一行皇后所在的列
int ans[3][14];
int cnt;
int n;
bool check(int k,int t)
{
    for(int i=1;i<=k-1;i++)
        if(queen[i]==t||abs(queen[i]-t)==abs(k-i)) return false;
    return true;
}
void dfs(int k)
{
    if(k>n)
    {
        if(++cnt<=3)
        {
            for(int i=1;i<=n;i++)
                ans[cnt-1][i] = queen[i];
        }
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(check(k,i))
        {
            queen[k] = i;
            dfs(k+1);
            queen[k] = 0;   // 调回初始
        }
    }
    return;
}
int main(void)
{
    cin>>n;
    dfs(1);
    for(int j=0;j<3;j++)
        for(int i=1;i<=n;i++)
            printf("%d%c",ans[j][i],(i==n)?'\n':' ');
    printf("%d\n",cnt);
    return 0;
}
//  邮局 暴力法只能90分 需要优化 //
//  优化法1：决策单调DP + 四边形不等式 //
//  优化法2：决策单调DP + 分治法 //    // 采用此法 //
#include<bits/stdc++.h>
using namespace std;
int n,m;   // n个村庄，m个邮局
int vil[3001];
int f[3001][301];   // f[i][j]表示前i个村庄，j个邮局，最小距离之和的最小值
int f2[3001][3001];       // f2[i][j] 表示第i到第j个村庄，一个邮局，最小距离之和的最小值
int s[3001];    // 最优决策点 , 使用滚动数组
void solve(int d,int l,int r,int L,int R)
{
    if(l>r) return;
    int mid = l + (r-l>>1);
    int id = -1;
    for(int k=L;k<=min(mid-1,R);k++)
        if(id==-1||f[id][d-1]+f2[id+1][mid]>f[k][d-1]+f2[k+1][mid]) id = k;
    s[mid] = id;
    solve(d,l,mid-1,L,id);
    solve(d,mid+1,r,id,R);
}
int main(void)
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)  
        scanf("%d",vil+i);
    // 计算f2
    for(int i=1;i<=n;i++)
    {
        f2[i][i] = 0;
        for(int j=i+1;j<=n;j++)
            f2[i][j] = f2[i][j-1]+ vil[j] - vil[(i+j)/2];
    }
    // 计算f
    for(int i=1;i<=n;i++)
        f[i][1] = f2[1][i];    // 初始化
    for(int j=2;j<=m;j++)
    {
        solve(j,1,n,0,n-1);
        //for(int i=1;i<=n;i++)
            //printf("%d ",s[i]);
        //printf("\n");
        for(int i=1;i<=n;i++)
            f[i][j] = f[s[i]][j-1] + f2[s[i]+1][i];
        
    }
    printf("%d\n",f[n][m]);
    return 0;
}
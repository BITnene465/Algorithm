// 全部枚举将会是O(n^4) 的算法 //
// 单调栈 O(n^2)//
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005][1005],ans,top,stk[1005];
int f[1005][1005],pre[1005][1005],nxt[1005][1005];   // pre，nxt 分别记录前或后第一个比该元素小的元素的索引 0~m+1
// n行m列
int read()
{
    char c;
    while(1)
    {
        c = getchar();
        if(c=='R')return 0;
        else if(c=='F')return 1;
    }
}
void solve()
{
    ans = 0;
    // pre f
    for(int j=1;j<=m;++j)
    {
        f[0][j]=0;
        for(int i=1;i<=n;++i)
        {
            if(a[i][j]==1) f[i][j]=f[i-1][j]+1;
            else f[i][j]=0;
        }
    }
    // for(int i=1;i<=n;++i){
    //     for(int j=1;j<=m;++j){
    //         printf("%d ",f[i][j]);
    //     }
    //     printf("\n");
    // }
    // 枚举行，每次用单调栈
    for(int i=1;i<=n;++i)
    {   
        // 单调栈经典模板
        top=0;
        f[i][m+1] = -100;
        for(int cur=1;cur<=m+1;++cur)
        {
            while(top&&(f[i][stk[top]]>f[i][cur])){nxt[i][stk[top]]=cur;--top;}
            stk[++top]=cur;
        }
        top=0;
        f[i][0] = -100;
        for(int cur=m;cur>=0;--cur)
        {
            while(top&&f[i][stk[top]]>f[i][cur]){pre[i][stk[top]]=cur;--top;}
            stk[++top]=cur;
        }
        // debug
        // for(int j=1;j<=m;++j)printf("%d",pre[i][j]);
        // printf("\n");
        // for(int j=1;j<=m;++j)printf("%d",nxt[i][j]);
        // printf("\n");
        // 求该行的max
        for(int j=1;j<=m;++j)ans=max(ans,(nxt[i][j]-pre[i][j]-1)*f[i][j]);
    }
}
int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)a[i][j]=read();
    ans=0;
    solve();
    printf("%d",3*ans);
    return 0;
}
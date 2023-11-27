// 枚举每一种情况爆搜，时间复杂度为 O(T*4^16) , TLE //
#include<bits/stdc++.h>
using namespace std;
int T;
char s[20][20];
int cnt[6][6],ans,cnt_ans[6][6];
bool used[16];
int tonum(char ch)   // 正常返回值0~15
{
    if(ch>='0'&&ch<='9')return ch-'0';
    else if(ch>='A'&&ch<='F')return ch-'A'+10;
    else return -1;
}
// 旋转代码没有任何问题
void rotate(int x,int y)  // 小块（x，y），顺时针转90(也即矩阵转置)
{
    int row_st=4*x-4;
    int col_st=4*y-4;
    char tmp[5][5];
    const int N = 4;
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=4;++j)
        {
            tmp[j][N-i+1]=s[row_st+i][col_st+j];     // 顺时针旋转九十度的公式
        }
    }
    for(int i=1;i<=4;++i)
    {
        for(int j=1;j<=4;++j)
        {
            s[row_st+i][col_st+j]=tmp[i][j];
            // printf("%c ",tmp[i][j]);
        }
        //  printf("\n");
    }
    return;
}
bool check(int x,int y)
{
    // printf("check %d %d:\n",x,y);
    // for(int i=1;i<=4;++i){for(int j=1;j<=4;++j)printf("%d ",cnt[i][j]);printf("\n");}
    // for(int i=1;i<=16;++i)puts(s[i]+1);
    // puts("\n\n");
    if(x!=4&&y!=4) return 1;  // 不判断，直接向下搜索
    else if(x!=4&&y==4)  // x!=4,y=4时,只检查行
    {
        int st=4*x-4;
        for(int i=1;i<=4;++i)
        {
            memset(used,0,sizeof(used));
            int now=st+i;
            for(int j=1;j<=16;++j)
            {
                if(used[tonum(s[now][j])]){return 0;}
                used[tonum(s[now][j])]=1;
            }
        }
        return 1;
    }
    else if(x==4&&y!=4)   // x=4&&y!=4的时候,只查列
    {
        int st=4*y-4;
        for(int i=1;i<=4;++i)
        {
            memset(used,0,sizeof(used));
            int now=st+i;
            for(int j=1;j<=16;++j)
            {
                if(used[tonum(s[j][now])]){return 0;}
                used[tonum(s[j][now])]=1;
            }
        }
        return 1;
    }
    else // x=y=4的时候，检查行和列
    {
        // 查行
        int st=4*x-4;
        for(int i=1;i<=4;++i)
        {
            memset(used,0,sizeof(used));
            int now=st+i;
            for(int j=1;j<=16;++j)
            {
                if(used[tonum(s[now][j])])return 0;
                used[tonum(s[now][j])]=1;
            }
        }
        // 查列
        st=4*y-4;
        for(int i=1;i<=4;++i)
        {
            memset(used,0,sizeof(used));
            int now=st+i;
            for(int j=1;j<=16;++j)
            {
                if(used[tonum(s[j][now])])return 0;
                used[tonum(s[j][now])]=1;
            }
        }
        return 1;
    }
}
void dfs(int n)    // 搜第n块
{
    if(n==17)   // n=17说明是合法的方案
    {
        int sum=0;
        for(int i=1;i<=4;++i)for(int j=1;j<=4;++j)sum+=cnt[i][j];
        if(sum<ans)   // 更新
        {
            ans=sum;
            memcpy(cnt_ans,cnt,sizeof(cnt));
        }
        return;
    }
    int x=(n-1)/4+1,y=(n-1)%4+1;
    for(int i=3;i>=0;--i)
    {
        rotate(x,y);
        cnt[x][y]=i;
        if(check(x,y))dfs(n+1);   // 继续向下探索
    }
}
void solve()
{
    memset(cnt,0,sizeof(cnt));
    ans=1000000;
    dfs(1);
    printf("%d\n",ans);
    for(int i=1;i<=16;++i)
    {
        int x=(i-1)/4+1,y=(i-1)%4+1;
        for(int j=1;j<=cnt_ans[x][y];++j)printf("%d %d\n",x,y);
    }
    return;
}
int main(void)
{
    scanf("%d",&T);
    getchar();
    while(T--)
    {
        for(int i=1;i<=16;++i){scanf("%s",s[i]+1);getchar();}
        solve();
    }
    return 0;
}
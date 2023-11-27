#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int f[N][N];   // f[i][j] 表示区间[i,j]子串的最小折叠长度
int n;
char s[N];
void solve()
{
    memset(f,126,sizeof(f));    // 初始化为很大的数
    for(int i=0;i<n;i++)
        f[i][i] = 1;     // 初始化
    for(int len=2;len<=n;len++)
    {
        for(int i=0;i<=n-len;i++)
        {
            int j = i+len-1;
            // situation 1
            for(int k=i;k<j;k++)
                f[i][j] = min(f[i][j],f[i][k]+f[k+1][j]);
            // situation 2
            for(int k=1;k<=len/2;k++)
            {
                if(len%k==0)
                {
                    int t = len/k;
                    int t1;
                    for(t1=0;t1<k;t1++)
                    {
                        int t2 = 1;
                        while(t2<t&&s[i+t1+k*t2]==s[i+t1])  t2++;
                        if(t2!=t)   break;
                    }
                    if(t1==k)
                    {
                        if(t<10)    f[i][j]=min(f[i][j],f[i][i+k-1]+3);    
                        else f[i][j]=min(f[i][j],f[i][i+k-1]+4);    // 至关重要
                    }
                }
            }
        }
    }
}
int main(void)
{
    scanf("%s",s);
    n = strlen(s);
    solve();
    cout<<f[0][n-1]<<endl;
    return 0;
}
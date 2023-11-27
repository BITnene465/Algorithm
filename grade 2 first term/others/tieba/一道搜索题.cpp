#include<bits/stdc++.h>
using namespace std;
int n, cnt, prime[30], ans, ans_stk[105], ans_top;
bool isnprime[105], vis[30];
void init(int n)
{  // 欧拉筛预处理出1~n的所有素数
    for(int i=2;i<=n;++i)
    {
        if(!isnprime[i])prime[++cnt]=i;
        for(int j=1;j<=cnt&&i*prime[j]<=n;++j)
            isnprime[i*prime[j]] = 1;
    }
}
void PrintSolution(){
    printf("%d= %d", n, ans_stk[1]);
    for(int i=2;i<=ans_top;++i)printf("+%d", ans_stk[i]);
    printf("\n");
    return;
}
void dfs(int sum, int now)
{
    if(sum > n || now > cnt){
        return;
    }
    if(sum==n){
        if(ans_top>=2){   // 去除形如 n = n 的解
            ans++;
            PrintSolution();
        }
        return;
    }
    ans_stk[++ans_top] = prime[now];
    dfs(sum+prime[now], now);
    --ans_top;
    dfs(sum, now+1);
}
int main(void)
{
    scanf("%d", &n);
    init(n);
    for(int i=1;i<=cnt;++i)printf("%d ",prime[i]);
    printf("%d~%d中共有%d个素数\n",1, n, cnt);
    dfs(0, 1);
    printf("共有%d组答案\n", ans);
    return 0;
}
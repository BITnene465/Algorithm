// 采用dfs暴搜 //
// nnd 这乐学还能检测我用什么算法? //
#include<bits/stdc++.h>
using namespace std;
const int maxw = 1e5 + 10;
const int maxn = 105;
int n,c,w[maxn],ans,used[maxn],ans_used[maxn];
void Dfs(int x, int sum)
{
    // printf("DFS: x=%d, sum=%d\n",x, sum);
    if(sum>c)return;
    if(x==n+1){
        if(sum>ans){
            for(int i=1;i<=n;++i){
                ans_used[i] = used[i];
            }
            ans = sum;
        }
        return;
    }
    // 先搜 1 后搜 0
    used[x] = 1;
    Dfs(x+1, sum+w[x]);
    used[x] = 0;
    Dfs(x+1, sum);
}
int main(void)
{
    scanf("%d %d",&c,&n);
    for(int i=1;i<=n;++i)scanf("%d",w+i);
    Dfs(1, 0);
    // print
    printf("%d\n",ans);
    for(int i=1;i<=n;++i){
        if(ans_used[i])printf("%d ",i);
    }
    printf("\n");
    return 0;
}
// hdu 1520 "Aniversary Party" //
// 树形DP //
#include<bits/stdc++.h>
using namespace std;
const int N = 6005; //最多节点数
vector<int> tree[N];  // 孩子表示法
int value[N]; // 权值
int n;   // 点的数量
int father[N];  // 用于寻找根节点
int dp[N][2];  // dp[i][0]和dp[i][1]分别表示不选用和选用节点i，以i为根节点，可得到的最大权值和
void dfs(int x)
{
    dp[x][0] = 0;
    dp[x][1] = value[x];
    for(int i=0;i<tree[x].size();i++)
    {
        int child = tree[x][i];
        dfs(child);    // 先深搜一下，使得后面有值可加
        dp[x][0] += max(dp[child][1],dp[child][0]);
        dp[x][1] += dp[child][0];
    }
    return;
} 
int main(void)
{
    while(~scanf("%d",&n))
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",value+i);
            tree[i].clear();  // 初始化
            father[i] = -1;   // 初始化
        }
        int a,b;
        while(1)
        {
            scanf("%d %d",&a,&b);
            if(a==0&&b==0)  break;
            tree[b].push_back(a);
            father[a] = b;    // b是a的父亲
        }
        int root=1;
        while(father[root]!=-1) root = father[root];  // 寻找根节点
        dfs(root);
        cout<<max(dp[root][0],dp[root][1])<<endl;
    }
    return 0;
}
/*
sample:
5
1
1
1
1
1
1 3
2 3
4 5
3 5
0 0

ans = 3
*/
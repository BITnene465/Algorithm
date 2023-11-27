// 采用DFS 爆搜 //
// 王道搜索思路，时间复杂度为O(2^n),n为物品数 //
#include<bits/stdc++.h>
using namespace std;
const int Max_money = 30000;
const int Max_item = 25;
struct node
{
    int w;    // 价格
    int v;    // 价值
}item[Max_item];
int ans;
int n,m;     // 分别为总钱数和要买的物品个数
void dfs(int i,int value,int res)     // res表示当前剩余可支配钱数,value表示当前总价值
{
    if(i==m+1)
    {
        if(value>ans)   ans = value;
        return;
    }
    else
    {
        if(res>=item[i].w)
            dfs(i+1,value+item[i].v,res-item[i].w);    // 选择第i件
        dfs(i+1,value,res);   // 不选第i件
    }
}
int main(void)
{
    // 读入数据
    scanf("%d %d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d %d",&item[i].w,&item[i].v);
        item[i].v = item[i].v*item[i].w;
    }
    //
    ans = 0;
    dfs(1,0,n);    // 从第一个物品开始搜索
    printf("%d\n",ans);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,q;
struct node1{
    int a,b,c;
}item[1005];            // 物品，三个属性
struct node2{
    int m,s,k;
    int id;
}query[1000005];       // 询问，离线储存
int f[100001]; 
int ans[1000005];    // 离线记录答案   
// f[i][j]表示选出物品a属性不超过i，c属性的和恰好为j时，b[i]最小值的最大值。 此处为滚数组，信息为第二维度
bool cmp1(struct node1 x,struct node1 y)
{
    return x.a<y.a;
}
bool cmp2(struct node2 x,struct node2 y)
{
    return x.m<y.m;
}
void solve()
{
    int j = 1;
    f[0] = INT_MAX;    // 初始化
    for(int i=1;i<=q;i++)
    {
        while(j<=n&&item[j].a<=query[i].m)     // a<=10^9 只是幌子，实际上只要计算<=n次
        {
            for(int k=100000;k>=item[j].c;k--)
                f[k] = max(f[k],min(f[k-item[j].c],item[j].b));   // 转移方程，更新
            j++;
        }
        if(f[query[i].k]>query[i].m+query[i].s)   ans[query[i].id] = 1;
    }
    return;
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d %d %d",&item[i].c,&item[i].a,&item[i].b);
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d %d %d",&query[i].m,&query[i].k,&query[i].s);
        query[i].id = i;
    }
    sort(item+1,item+n+1,cmp1);
    sort(query+1,query+q+1,cmp2);
    solve();
    for(int i=1;i<=q;i++)
    {
        if(ans[i]==1)   printf("TAK\n");
        else    printf("NIE\n");
    }
    return 0;
}
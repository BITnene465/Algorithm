//  恐怖的末尾淘汰 可并堆模板题 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
int n,q,vis[maxn]; // vis表示是否淘汰
// 左偏树 leftist tree / leftist heap //
struct lheap{
    int val;  // 权值
    int fa;   // father，根节点的父节点为0
    int ls,rs;   // left son & right son ->  没有即为0(若用指针表示就是NULL)
    int dist;   // 距离，0号节点初始化为-1，其余初始化为0或不初始化均可
}tr[maxn];
// 合并操作
int Merge(int x,int y)
{
    if(!x||!y)  return x+y;  // 返回x，y中的非零者或0
    if(tr[x].val>tr[y].val) swap(x,y);   // 以小根堆举例，此处保证x节点的权值比y节点的权值小，然后把y插入x
    int &ur=tr[x].rs,&ul=tr[x].ls;
    ur=Merge(ur,y);    // 为什么要与柚子树合并？ 因为dist[rs]<=dist[ls],这是左偏树的性质,该性质保证了合并时的复杂度
    tr[ur].fa=x;   // 不能忘记，因为合并的时候，可能交换过左右子树
    // 合并完了，看看是否还符合左偏树的结构，调整结构
    if(tr[ur].dist>tr[ul].dist) swap(ur,ul);
    tr[x].dist=tr[ur].dist+1;   // 更新该节点的距离
    return x;  // 返回该节点
}
// 删除根节点 , 同时返回根节点的值
int Erase(int x)
{
    int ans=tr[x].val;
    int ur=tr[x].rs,ul=tr[x].ls;
    tr[x].val=-1;   // 用一个值表式该点未初始化，或单独用flag数组表示也可以
    tr[x].ls=0,tr[x].rs=0;
    int r=Merge(ur,ul);   // 返回新的根节点
    tr[r].fa=0;   // 根节点的父亲是0
    return ans;
}
// 找到根节点 , O(logn)姑且可以接受 //
int find_root(int x)
{
    int r=x;while(tr[r].fa) r=tr[r].fa;
    return r;   
}
int main(void)
{
    scanf("%d %d",&n,&q);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&tr[i].val);
        tr[i].fa=0;   // 此时是根节点
        tr[i].ls=tr[i].rs=0;
        tr[i].dist=0;
        vis[i]=0;   // 初始化vis数组
    }
    tr[0].dist=-1;   // 必须设置 
    // 询问 //
    while(q--)
    {
        int flag;
        scanf("%d",&flag);
        if(flag==1)
        {
            int x,y;
            scanf("%d %d",&x,&y);
            if(vis[x]||vis[y])  continue;
            int r1=find_root(x),r2=find_root(y);
            if(r1==r2)continue;
            Merge(r1,r2);
        }
        else
        {
            int x;
            scanf("%d",&x);
            if(vis[x]) {printf("-1\n");continue;}
            int r=find_root(x);
            vis[r]=1;    // 淘汰该员工 
            printf("%d\n",Erase(r));
        }
    }
    return 0;
}
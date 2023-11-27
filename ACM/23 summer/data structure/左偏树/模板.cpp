#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int n,rt;   // rt记录根节点
// 左偏树 leftist tree / leftist heap //
struct lheap{
    int val;  // 权值
    int fa;   // father，根节点的父节点为0
    int ls,rs;   // left son & right son ->  没有即为0(若用指针表示就是NULL)
    int dist;   // 距离
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
// 插入操作
// 一个节点x 插入以root为根的左偏树，可以把单节点x看做一棵左偏树，然后合并
void Insert(int root,int x)
{
    Merge(root,x);
    return;
}
// 删除根节点
void Erase(int x)
{
    int ur=tr[x].rs,ul=tr[x].ls;
    tr[x].val=-1;   // 用一个值表式该点未初始化，或单独用flag数组表示也可以
    tr[x].ls=0,tr[x].rs=0;
    rt=Merge(ur,ul);   // 返回新的根节点
    return;
}
// 删除任意节点
void Delete(int x)
{
    int fa=tr[x].fa;
    int temp=Merge(tr[x].rs,tr[x].ls);
    tr[x].val=-1,tr[x].rs=0,tr[x].ls=0;
    tr[temp].fa=fa;
    int &ur=tr[fa].rs,&ul=tr[fa].ls;
    (x==ur)?ur=temp:ul=temp;    // 看看x是左儿子还是右儿子
    tr[fa].dist=tr[tr[fa].rs].dist+1;
    // 向上维护左偏性质，直到根节点或左偏性质不再被破坏 //
    while(fa&&tr[tr[fa].rs].dist<=tr[tr[fa].ls].dist)   // 当前节点不是根节点（注：根节点的父节点为0）
    {
        swap(tr[fa].rs,tr[fa].ls);
        tr[fa].dist=tr[tr[fa].rs].dist+1;  // 更新dist
        // 向上维护
        fa=tr[fa].fa;
    }
    return;
}
// 建树操作:暴力插入 复杂度O(nlogn) //
// 前置条件，tr[1]~tr[n]的权值已经初始化完毕，只是没有连接起来 //
void Build(int n)   // 参数也可以改成一个数组或其他容器
{
    int root=1;
    for(int i=2;i<=n;i++)
        root=Merge(root,i);
    rt=root;   // 记录根节点
    return;
}

// 数据结构测试 //
queue<int> q;
deque<int> qq;
void print_data(int n,int d)
{
    printf("深度%d:节点%d val=%d lson=%d rson=%d father=%d dist=%d\n",d,n,tr[n].val,tr[n].ls,tr[n].rs,tr[n].fa,tr[n].dist);
}
void bfs(int rt)
{
    q.push(rt);
    int dep=1;
    print_data(rt,dep);
    while(1)
    {
        dep++;
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            if(tr[u].ls)    qq.push_back(tr[u].ls),print_data(tr[u].ls,dep);
            if(tr[u].rs)    qq.push_back(tr[u].rs),print_data(tr[u].rs,dep);
        }
        if(qq.empty())  break;
        while(!qq.empty())  q.push(qq.front()),qq.pop_front();
    }
    return;
}
int main(void)
{
    tr[0].dist=-1;
    n = 10;
    for(int i=1;i<=n;i++)
    {
        tr[i].dist=0;
        tr[i].ls=tr[i].rs=0;
        tr[i].fa=0;
        tr[i].val=i;  // 1~1000的整数
    }
    Build(n);
    bfs(rt);
    int x;
    cin>>x;
    Delete(x);
    bfs(rt);
    printf("end\n");
    return 0;
}
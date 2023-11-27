// 动态开点的线段树 //
// 以维护区间最大值举例 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
// rt表示整棵树的根节点，n为数组长度，cnt为当前节点个数
int n,cnt,rt;
struct segtree{
    int val=-1;
    int ls=0,rs=0;     // 若为空，则为0
}tr[maxn<<1];    // 2倍足矣，动态开点 (点开满也就2*n-1)
int a[maxn];


// 单点更新，使用方法： tree_update(rt,1,n,pos,f);
void tree_update(int &cur,int cl,int cr,int pos,int f)   // [cl,cr]是当前节点表示的区间,pos是要更改的下标，f是新值
{
    if(pos<cl||pos>cr)    return;
    if(!cur)    cur=++cnt;    // 如果当前节点为空，则设置新的节点
    if(cr==cl)
    {
        tr[cur].val=f;
        return;
    }
    int mid=(cl+cr)/2;
    tree_update(tr[cur].ls,cl,mid,pos,f);
    tree_update(tr[cur].rs,mid+1,cr,pos,f);
    tr[cur].val=max(tr[tr[cur].ls].val,tr[tr[cur].rs].val);
    return;
}
// 区间查询，使用方法：tree_query(rt,1,n,vl,vr);
// 查询之前要先更新
int tree_query(int &cur,int cl,int cr,int vl,int vr)
{
    if(cr<vl||cl>vr)    return -1;     // 假设区间内处理的数都是正整数，所以-1一定最小
    if(vl<=cl&&cr<=vr)  return tr[cur].val;
    int mid=(cl+cr)/2;
    return max(tree_query(tr[cur].ls,cl,mid,vl,vr),tree_query(tr[cur].rs,mid+1,cr,vl,vr));
}

// ds test //
int main(void)
{
    n=10000;
    for(int i=1;i<=n;i++)
        a[i]=rand()%100+1,printf("%d ",a[i]),tree_update(rt,1,n,i,a[i]);
    printf("\n");
    printf("cnt=%d\n",cnt);
    while(1)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        if(x==0||y==0)  break;
        printf("最大值为:%d\n",tree_query(rt,1,n,x,y));
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[1001];
struct node{
    int sum;
    int tag;   // lazy tag
}tree[4000];
int n;
void tree_build(int l,int r,int root)
{
    if(l==r)
    {
        tree[root].sum = a[l];
        tree[root].tag = 0;   // 初始化
        return; 
    }
    int mid=l+((r-l)>>1);
    tree_build(l,mid,root*2);   // 左子树
    tree_build(mid+1,r,root*2+1);  // 右子树
    tree[root].sum = tree[root*2].sum + tree[root*2+1].sum;
    tree[root].tag = 0;   // 初始化
    return;
}
// 下放lazy tag给子节点
void pushdown(int cur,int cl,int cr,int mid)
{
    tree[2*cur].tag += tree[cur].tag;     // 左子树更新
    tree[2*cur].sum += (mid-cl+1)*tree[cur].tag;
    tree[2*cur+1].tag += tree[cur].tag;   // 右子树更新
    tree[2*cur+1].sum += (cr-mid)*tree[cur].tag;
    tree[cur].tag = 0;       // cur标签更新
    return;
}
// 区间更新(对区间进行同一种操作)  ->  类似于区间查询
// 此处以 全部加k 举例
void update(int cl,int cr,int cur,int vl,int vr,int k)
{
    if(cr<vl||cl>vr)    return;   // 区间无交集，直接返回
    if(vl<=cl&&cr<=vr)   // 如果当前区间被包含在修改区间，进行修改
    {
        tree[cur].sum += (cr-cl+1)*k;
        tree[cur].tag += k;
        return;
    }
    // 如果当前区间与修改区间有交集且不被包含于修改区间内
    int mid = ((cr-cl)>>1)+cr;
    if(tree[cur].tag && cl!=cr) pushdown(cur,cl,cr,mid);    // 如果当前节点 懒标签不为空 且 不是树叶 -> 下放懒节点
    
    if(vl<=mid) update(cl,mid,2*cur,vl,vr,k);
    if(vr>mid) update(mid+1,cr,2*cur+1,vl,vr,k);
    tree[cur].sum = tree[2*cur].sum + tree[2*cur+1].sum;   // 懒节点不在这一层，这一层的更新必不可少
    return;
}
// 带pushdown的查询
int query(int cur,int cl,int cr,int vl,int vr)
{
    if(vl>cr||vr<cl)    return 0;
    if(vl<=cl&&cr<=vr)  return tree[cur].sum;
    int mid = cl + ((cr-cl)>>1);
    if(tree[cur].tag && cr!=cl) pushdown(cur,cl,cr,mid);
    return query(2*cur,cl,mid,vl,vr)+query(2*cur+1,mid+1,cr,vl,vr);
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    tree_build(1,n,1);
    //打印a数组
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    // 查询
    
    // 更新

    // 更新后查询
    return 0;
}
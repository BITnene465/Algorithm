#include<bits/stdc++.h>
using namespace std;
int a[1001],tree[4000];
int n;
void tree_build(int l,int r,int root)
{
    if(l==r)
    {    
        tree[root] = a[l];
        return;
    }
    else
    {
        int mid = l+((r-l)>>1);
        tree_build(l,mid,2*root);
        tree_build(mid+1,r,2*root+1);
        tree[root] = tree[2*root]+tree[2*root+1];
    }
}
// [cl,cr]为当前区间 , [vl,vr]为目标区间 , cur 为当前节点号
int tree_query(int cl,int cr,int vl,int vr,int cur)
{
    // 如果无交集
    if(vr<cl||vl>cr)  return 0;     // 这个值视情况而定（用一个无效值）
    // 当前区间被目标区间包含
    else if(vl<=cl&&cr<=vr) return tree[cur];
    // 如果不完全包含而只是有交集
    else
    {
        int mid = cl+((cr-cl)>>1);
        int sum = 0;
        if(vl<=mid) sum+=tree_query(cl,mid,vl,vr,2*cur);    
        // 代表左儿子[cl,mid]与目标区间有交集，向左儿子递归查询
        if(mid<vr) sum+=tree_query(mid+1,cr,vl,vr,2*cur+1);
        // 代表右儿子[mid+1,cr]与目标区间有交集，向右儿子递归查询
        return sum;
    }
}
// 单点更新类似于建树
// [cl,cr]是当前区间，cur为当前节点，pos为a数组要更新的位置，x为更新的值
void update(int cl,int cr,int cur,int pos,int x)
{
    if(cl>pos||cr<pos)  return;      // pos不在区间内，不搜索
    if(cl==cr)                       // 找到pos ,此时 cl=cr=pos
    {
        tree[cur] = x;
        return;
    }
    int mid = cl+((cr-cl)>>1);
    update(cl,mid,cur,pos,x);
    update(mid+1,cr,cur,pos,x);
    tree[cur] = tree[cur*2]+tree[cur*2+1];     // 将儿子节点更新完了，可以更新本节点
    return;
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
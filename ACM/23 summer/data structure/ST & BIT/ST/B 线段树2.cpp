// lazy tag 线段树, 两个lazy tag //
#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
struct node{
    ll sum;
    ll add;
    ll mul;
}tree[400005];
int n;   // 数组长度
ll a[100005];
void tree_build(int l,int r,int root)
{
    if(l==r)
    {
        tree[root].sum = a[l];
        tree[root].add = 0;
        tree[root].mul = 1;
        return;
    }
    int mid = l+((r-l)>>1);
    tree_build(l,mid,2*root);
    tree_build(mid+1,r,2*root+1);
    tree[root].sum = tree[2*root].sum + tree[2*root+1].sum;
    tree[root].add = 0;
    tree[root].mul = 1;
    return;
}
// 未修改
void pushdown(int cur,int l,int r,int mid)
{
    tree[2*cur].tag += tree[cur].tag;
    tree[2*cur].sum += (mid-l+1)*tree[cur].tag;
    tree[2*cur+1].tag += tree[cur].tag; 
    tree[2*cur+1].sum += (r-mid)*tree[cur].tag;
    tree[cur].tag = 0;    // 下放完了
    return; 
}
void update_add(int cur,int cl,int cr,int vl,int vr,int k)
{
    if(vr<cl||vl>cr)    return;
    if(vl<=cl&&cr<=vr)
    {
        tree[cur].sum += (cr-cl+1)*k;
        tree[cur].add += k;
        return;
    }
    ll mid = cl+((cr-cl)>>1);
    if(tree[cur].add && cl!=cr) pushdown(cur,cl,cr,mid);

    update_add(2*cur,cl,mid,vl,vr,k);
    update_add(2*cur+1,mid+1,cr,vl,vr,k);
    tree[cur].sum = tree[2*cur].sum + tree[2*cur+1].sum;
    return;
}
// 未修改
void update_mul(int cur,int cl,int cr,int vl,int vr,int k)
{
    if(vr<cl||vl>cr)    return;
    if(vl<=cl&&cr<=vr)
    {
        tree[cur].sum += (cr-cl+1)*k;
        tree[cur].add += k;
        return;
    }
    ll mid = cl+((cr-cl)>>1);
    if(tree[cur].add!=1 && cl!=cr) pushdown(cur,cl,cr,mid);

    update_mul(2*cur,cl,mid,vl,vr,k);
    update_mul(2*cur+1,mid+1,cr,vl,vr,k);
    tree[cur].sum = tree[2*cur].sum + tree[2*cur+1].sum;
    return;
}
ll query(int cur,int cl,int cr,int vl,int vr)
{
    if(vr<cl||vl>cr)    return 0;
    if(vl<=cl&&cr<=vr)  return tree[cur].sum;
    ll mid = cl+((cr-cl)>>1);
    if((tree[cur].add!=0||tree[cur].mul!=1) && cl!=cr) pushdown(cur,cl,cr,mid);
    return query(2*cur,cl,mid,vl,vr)+query(2*cur+1,mid+1,cr,vl,vr);
}

int main(void)
{
    int m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    tree_build(1,n,1);
    while(m--)
    {
        int flag;
        scanf("%d",&flag);
        if(flag==1){
            int x,y,k;
            scanf("%d %d %d",&x,&y,&k);
            update_add(1,1,n,x,y,k);
        }
        else{
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%lld\n",query(1,1,n,x,y));
        }
    }
    return 0;
}
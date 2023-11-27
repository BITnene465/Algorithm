#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
/**
 * @brief 实现线段树，0为空节点，约定根节点的fa是0，叶子儿子是0，空儿子也是0
 * 
 */
namespace SegTree
{
    int tot;  // 记录总的节点数动态开点, 点数从1开始
    int tr_tot;   // 记录总的线段树数量,id 从1开始
    struct node{
        int val;
        int ls,rs;
        int fa;
    }nod[MAXN];   // 用于实现节点,编号从1开始
    struct St{
        int cnt; // 节点个数
        int rt;  // 根节点所在编号
        int cl,cr;   // 记录当前根节点管理的区间
    }tr[MAXN];
    void init()
    {
        tot=0;
        memset(nod,0,sizeof(nod));
        memset(tr,0,sizeof(tr));
    }
    // 向某棵线段树插入一个元素
    void Insert()
    {
        ;
    }
    // 根据一个数组，建立一棵线段树
    void _Build(int a[],int l,int r,int cur,int id)
    {
        ++tr[id].cnt;
        if(l==r)
        {
            nod[cur].val=a[l];
            nod[cur].ls=nod[cur].rs=0;   // 如果0不是空节点就不要忘记了
            return;
        }
        int mid=l+r>>1;
        int ls=++tot;
        int rs=++tot;
        nod[cur].ls=ls,nod[cur].rs=rs;
        nod[ls].fa=nod[rs].fa=cur;
        _Build(a,l,mid,ls,id);
        _Build(a,mid+1,r,rs,id);
        nod[cur].val=nod[ls].val+nod[rs].val;
    }
    int Build(int a[],int l,int r)
    {
        if(l>r)swap(r,l);    // 保证l<=r
        int id=++tr_tot;  // 这棵树的id
        int rt=++tot;       // 这棵树的rt
        tr[id].rt=rt;
        tr[id].cr=r,tr[id].cl=l;
        nod[rt].fa=0;    // 初始化，如果0不是空节点的话，就不要忘记了
        _Build(a,l,r,rt,id);
        return id;     // 返回id，在主函数里保存后可以访问这棵树
    }
    // 查询某棵线段树的区间和
    int _Query(int cl,int cr,int vl,int vr,int cur)
    {
        if(vr<cl||vl>cr)    return 0;
        if(vl<=cl&&cr<=vr)  return nod[cur].val;
        int mid=cl+cr>>1;
        return _Query(cl,mid,vl,vr,nod[cur].ls)+_Query(mid+1,cr,vl,vr,nod[cur].rs);
    }
    int Query(int id,int l,int r)
    {
        int rt=tr[id].rt;
        int cl=tr[id].cl,cr=tr[id].cr;
        return _Query(cl,cr,l,r,rt);
    }
    // 单点更新
    void Update()
    {
        ;
    }
    // 区间更新
    void Update2()
    {
        ;
    }
}; // namespace SegTree
using namespace SegTree;
int arr[MAXN],n;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>arr[i];
    int id=Build(arr,1,n);
    int flag,l,r;
    while(cin>>flag)
    {
        if(flag==1)
        {
            cin>>l>>r;
            cout<<Query(id,l,r)<<endl;
        }
        else if(flag==2)
        {
            cin>>l;
            cout<<tr[l].rt<<" "<<tr[l].cl<<" "<<tr[l].cr<<endl; 
        }
    }
    return 0;
}
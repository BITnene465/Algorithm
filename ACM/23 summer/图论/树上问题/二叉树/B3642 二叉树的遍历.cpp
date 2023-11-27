#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch<='9'&&ch>='0'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
struct btree{
    int fa=0;
    int ls=0,rs=0;
}tr[maxn];
int n;
void preorder(int rt)
{
    if(!rt) return;
    printf("%d ",rt);
    preorder(tr[rt].ls);
    preorder(tr[rt].rs);
}
void inorder(int rt)
{
    if(!rt) return;
    inorder(tr[rt].ls);
    printf("%d ",rt);
    inorder(tr[rt].rs);
}
void postorder(int rt)
{
    if(!rt) return;
    postorder(tr[rt].ls);
    postorder(tr[rt].rs);
    printf("%d ",rt);
}
int main(void)
{
    n=read();
    int u,v;
    for(int i=1;i<=n;i++)
    {
        u=read(),v=read();
        if(u)
        {
            tr[u].fa=i;
            tr[i].ls=u;
        }
        if(v)
        {
            tr[v].fa=i;
            tr[i].rs=v;
        }
    }
    int rt=1;
    while(tr[rt].fa)    rt=tr[rt].fa;
    preorder(rt);
    printf("\n");
    inorder(rt);
    printf("\n");
    postorder(rt);
    printf("\n");
    return 0;
}
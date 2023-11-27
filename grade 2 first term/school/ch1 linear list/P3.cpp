// 访问一个单向链表的倒数第 r 个元素
// 双指针 
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    node* nxt;
    node() = default;
    node(int val,node* nxt=NULL):val(val),nxt(nxt){};
};
void build(int *a,int length,node* &Linklist)
{
    node* p = Linklist;
    for(int i=0;i<length;++i)
    {
        node* tmp = new node(a[i],NULL);
        p->nxt = tmp;
        p = p->nxt;
    }
    return;
}
node* r_find(node* &Linklist ,int r)
{
    node *p1,*p2;
    p2 = Linklist;
    for(int i=1;i<=r && p2->nxt!=NULL;++i){p2 = p2->nxt;}
    if(!(p2->nxt)){cout<<"不存在第"<<r<<"个元素"<<endl;return NULL;}
    p1 = Linklist->nxt;
    while(p2->nxt)
    {
        p1 = p1->nxt;
        p2 = p2->nxt;
    }
    return p1;
}
int main(void)
{
    node* linklist1 = new node(0,NULL);  // 新建一个链表
    int a[]={1,2,3,45,23,12,33,243,113,11,-9,-83,23};
    int r;
    build(a,sizeof(a)/sizeof(int),linklist1);
    cin>>r;
    node* idx = r_find(linklist1,r);
    int ans=-1000;
    if(idx){ans = idx->val;}
    cout<<ans<<endl;
    return 0;
}
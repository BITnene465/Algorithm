// 二叉搜索树并且维护平衡 //
#include<bits/stdc++.h>
using namespace std;
struct node{
    int val;
    int siz;    // 记录以该节点为根节点的二叉树的大小
    node *ls,*rs;
};
node* rt;
void Insert(node* &rt,int k);
void Delnode(node* p);
void rotate_L(node* &rt);
void rotate_R(node* & rt);
void preorder(node* rt);
void inorder(node* rt);
void postorder(node* rt);
void printByDepth(node* rt); 
int main(void)
{
    int k,x,flag;
    while(1)
    {
        cout<<"1: Insert vals ->the first line: numbers of number 'k'; the second line: k numbers\n";
        cout<<"2: preorder\n";
        cout<<"3: inorder\n";
        cout<<"4: postorder\n";
        cout<<"5: printByDepth\n";
        cin>>flag;
        switch (flag)
        {
        case 1:
            cin>>k;
            for(int i=1;i<=k;++i)
            {
                cin>>x;
                Insert(rt,x);
            }
            break;
        case 2:
            preorder(rt);
            cout<<'\n';
            break;
        case 3:
            inorder(rt);
            cout<<'\n';
            break;
        case 4:
            postorder(rt);
            cout<<'\n';
            break;    
        case 5:
            printByDepth(rt);
            cout<<'\n';
            break;    
        default:
            break;
        }
    }
    return 0;
}
void Insert(node* &rt,int k)
{
    if(rt==NULL)
    {
        rt = new node;
        rt->ls = rt->rs = NULL;
        rt->val = k;
        rt->siz = 1;
        return;
    }
    rt->siz+=1;
    if(k<rt->val)Insert(rt->ls,k);
    else         Insert(rt->rs,k);
}
void preorder(node* rt)
{
    if(!rt)return;
    cout<<rt->val<<' ';
    preorder(rt->ls);
    preorder(rt->rs);
}
void inorder(node* rt)
{
    if(!rt)return;
    inorder(rt->ls);
    cout<<rt->val<<' ';
    inorder(rt->rs);
}
void postorder(node* rt)
{
    if(!rt)return;
    postorder(rt->ls);
    postorder(rt->rs);
    cout<<rt->val<<' ';
}
void printByDepth(node* rt)   // 队列BFS
{
    queue<node*> q1,q2;
    int cnt = 0;
    cout<<"the "<<++cnt<<" floor:";
    cout<<rt->val<<' '<<endl;
    q1.push(rt);
    while(!q1.empty())
    {
        while(!q1.empty())
        {
            node* now = q1.front();
            q1.pop();
            if(now->ls)q2.push(now->ls);
            if(now->rs)q2.push(now->rs);
        }
        cout<<"the "<<++cnt<<" floor:";
        while(!q2.empty())
        {
            node* now = q2.front();
            q2.pop();
            cout<<now->val<<' ';
            q1.push(now);
        }
        cout<<'\n';
    }
    return;
}
void Delnode(node* p)
{
    
}
void rotate_L(node* &rt)
{

}
void rotate_R(node* & rt)
{

}

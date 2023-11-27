// hdu 1710 "Binary Tree Traversal" //
#include<bits/stdc++.h>
#define N 10000
using namespace std;
struct node{
    int value;
    node *l,*r;
};   // 二叉链表存储
int pre[N];
int in[N];
int post[N];
void build_tree(node* &root,int l,int r,int &t)  //以引用作为形参
{
    int index = -1;
    // 先序遍历的第一个肯定为根
    for(int i=l;i<=r;++i)
    {
        if(in[i]==pre[t])
        {
            index = i;
            break;
        }
    }
    if(index==-1)   return;  // 回溯
    else
    {
        ++t;
        root = new node;
        root->value = in[index];
        root->l = root->r = NULL;
        if(index>l) build_tree(root->l,l,index-1,t);
        if(index<r) build_tree(root->r,index+1,r,t);
        return;
    }
}
void preorder(node* &root)
{
    if(root!=NULL)
    {
        cout<<root->value<<" ";
        preorder(root->l);
        preorder(root->r);
    }
}
void inorder(node* &root)
{
    if(root!=NULL)
    {
        inorder(root->l);
        cout<<root->value<<" ";
        inorder(root->r);
    }
}
void postorder(node* &root)
{
    if(root!=NULL)
    {
        postorder(root->l);
        postorder(root->r);
        cout<<root->value<<" ";
    }
}
void clear_tree(node* &root)
{
    // 递归方法，会从最末端的叶子开始清除，也可用于链表
    if(root==NULL)
        return;
    else{
        clear_tree(root->l);
        clear_tree(root->r);
        delete root;      // new-delete体系
    }
}   
int main(void)
{
    node* root;
    int n;
    //
    while(~scanf("%d",&n))
    {
        int t = 0;
        for(int i=0;i<n;++i)
            scanf("%d",pre+i);    // 先输入先序遍历
        for(int i=0;i<n;++i)
            scanf("%d",in+i);    // 再输入中序遍历
        build_tree(root,0,n-1,t);
        // 调试时用于验证
        cout<<"先序遍历:";
        preorder(root);
        cout<<"中序遍历:";
        inorder(root);
        cout<<"后序遍历:";
        //    
        postorder(root);

        clear_tree(root);    // 清除树，等待下一次输入
    }
    //
    return 0;
}
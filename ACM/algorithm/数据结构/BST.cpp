#include<bits/stdc++.h>
#define N 1000
using namespace std;
struct node{
    int value;
    node *l,*r;
};
void insert_bst(node* &root,int value)
{
    if(root==NULL)
    {
        root = new node;
        root->value = value;
        root->l = root->r = NULL;
    }
    else{
        if(value<=root->value)
            insert_bst(root->l,value);
        else
            insert_bst(root->r,value);
    }
}
void build_bst(node* &root,vector<int> arr)    //建树就是按照输入顺序不断插入，这样得到的BST是唯一的
{
    for(int i=0;i<arr.size();i++)
        insert_bst(root,arr[i]);
}
void inorder(node* &root)
{
    if(root==NULL)  return;
    inorder(root->l);
    cout<<root->value<<" ";
    inorder(root->r);
}
int main(void)
{
    node* root;
    vector<int> arr;
    int n;
    while(cin>>n)   arr.push_back(n);
    // 检查输入
    printf("你的输入是:");
    for(int i=0;i<arr.size();i++)
        printf("%3d",arr[i]);
    printf("\n");
    //
    build_bst(root,arr);
    //
    printf("中序遍历为:");
    inorder(root);
    return 0;
}
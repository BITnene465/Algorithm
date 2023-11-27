#include<cstdio>
#include<iostream>
using namespace std;
typedef unsigned int uint;
class BinTree
{
    private:
    struct Element;
    struct node;
    void _clear(node*);
    uint sz;
    node* root;
    struct Element{
        int score;
        string name;
    };
    struct  node
    {
        Element p;
        node* parent;
        node  *ls,*rs;
    };
    void _clear(node* rt)
    {
        if(rt==NULL)return;
        node *lst=rt->ls,*rst=rt->rs;
        delete rt;
        _clear(lst);_clear(rst);
    }

    public:
    bool empty()
    {
        return !sz;
    }
    uint size()
    {
        return sz;
    }
    bool Init()
    {
        node* newnode = new node;
        if(newnode==NULL)return 0;
        newnode->parent = NULL;
        newnode->ls = newnode->rs = NULL;
        sz=1;
        root = newnode;
        return 1;
    }
    // 删除二叉树
    void clear()
    {
        _clear(root);
        return;
    }
    // 获取节点p存放的元素
    bool getdata(node* p,Element& x)
    {
        if(!p)return 0;
        x=p->p;
        return 1;
    }
    // 
    ;
   
};
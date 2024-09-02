#ifndef MYTREES_H
#define MYTREES_H

// forward declaration
template<typename Value, typename Key=int>
        class BiTreeNode;
template<typename Value, typename Key=int>
        class BSTree;
template<typename Value, typename Key=int>
        class AVLNode;
template<typename Value, typename Key=int>
        class AVL;

// Declaration
template<typename Value, typename Key>
class BiTreeNode{
    friend class BSTree<Value, Key>;   // 将树节点加入友元类

protected:
    Value value;   //  值
    Key key;   // 排序的依据
    BiTreeNode *leftPtr, *rightPtr;
    BiTreeNode *parentptr;
    int size;

protected:
    static void _preOrder(BiTreeNode<Value, Key>*);
    static void _inOrder(BiTreeNode<Value, Key>*);
    static void _postOrder(BiTreeNode<Value, Key>*);

    static void _insert(const Value& v,const Key& k, BiTreeNode<Value, Key>* &nodeptr);
    static void _delete(const Key& k, BiTreeNode<Value, Key>*& nodeptr, BiTreeNode<Value, Key>* parentnodePtr);
    static BiTreeNode<Value, Key>& _deleteMin(BiTreeNode<Value, Key>* nodeptr);
    static BiTreeNode<Value, Key>& _search(Key k, BiTreeNode<Value, Key>* &nodeptr);


public:
    using BiTreeNodePtr = BiTreeNode<Value, Key>*;
    BiTreeNode(const BiTreeNode<Value, Key> & other);

    BiTreeNode(Value value, Key key, BiTreeNode<Value, Key> *leftPtr= nullptr, BiTreeNode<Value, Key> *rightPtr= nullptr, int size=0);

    Value GetValue();
    Key GetKey();
    BiTreeNode<Value, Key>& Left();
    BiTreeNode<Value, Key>& Right();
};

template<typename Value, typename Key>
class BSTree{
private:
    BiTreeNode<Value, Key>* rootptr;
public:
    using BSTreePtr = BSTree<Value, Key>*;

    BSTree();
    BSTree(const BiTreeNode<Value, Key>& r);
    BSTree(const BSTree& other);   // 复制整棵树
    
    BiTreeNode<Value, Key>& Root();
    BiTreeNode<Value, Key>* &RootPtr();     // 注意此处写法

    // 遍历
    void preOrder();
    void inOrder();
    void postOrder();

    // 插入删除
    void Insert(Value v, Key k);
    void Delete(Key key);
    void Search(Key key);

};

template<typename Value, typename Key>
class AVLNode: public BiTreeNode<Value, Key>{
    friend class AVL<Value, Key>;   // 将平衡树加入友元

protected:
    int height;
    static void _insert(const Value &v, const Key &k, AVLNode<Value, Key>* &rtptr);



public:
    int Height();
    int BalanceFactor();

};




#include "MyTrees_imp.h"

#endif
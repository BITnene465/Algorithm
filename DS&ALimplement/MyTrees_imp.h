#ifndef MYTREES_IMP_H
#define MYTREES_IMP_H

template<typename Value, typename Key>
BiTreeNode<Value, Key>::BiTreeNode(Value value, Key key, BiTreeNode<Value, Key> *leftPtr, BiTreeNode<Value, Key> *rightPtr, int size):value(value), key(key), leftPtr(leftPtr), rightPtr(rightPtr), size(size) {}


template<typename Value, typename Key>
BiTreeNode<Value, Key>::BiTreeNode(const BiTreeNode<Value, Key> &other) {
    value = other.value;
    key = other.key;
    leftPtr = other.leftPtr;
    rightPtr = other.rightPtr;
}

template<typename Value, typename Key>
Value BiTreeNode<Value, Key>::GetValue() {
    return value;
}

template<typename Value, typename Key>
Key BiTreeNode<Value, Key>::GetKey() {
    return key;
}

template<typename Value, typename Key>
BiTreeNode<Value, Key> &BiTreeNode<Value, Key>::Left() {
    return *leftPtr;
}

template<typename Value, typename Key>
BiTreeNode<Value, Key> &BiTreeNode<Value, Key>::Right() {
    return *rightPtr;
}

template<typename Value, typename Key>
void BiTreeNode<Value, Key>::_preOrder(BiTreeNode<Value, Key> * nodeptr) {
    if(nodeptr== nullptr) return ;
    std::cout << "(" << nodeptr->value << ", " << nodeptr->key << ")  ";
    _preOrder(nodeptr->leftPtr);
    _preOrder(nodeptr->rightPtr);
}

template<typename Value, typename Key>
void BiTreeNode<Value, Key>::_inOrder(BiTreeNode<Value, Key> * nodeptr) {
    if(nodeptr== nullptr) return ;
    _inOrder(nodeptr->leftPtr);
    std::cout << "(" << nodeptr->value << ", " << nodeptr->key << ") ";
    _inOrder(nodeptr->rightPtr);
}

template<typename Value, typename Key>
void BiTreeNode<Value, Key>::_postOrder(BiTreeNode<Value, Key> * nodeptr) {
    if(nodeptr== nullptr) return ;
    _postOrder(nodeptr->leftPtr);
    _postOrder(nodeptr->rightPtr);
    std::cout << "(" << nodeptr->value << ", " << nodeptr->key << ") ";
}

template<typename Value, typename Key>
void BiTreeNode<Value, Key>::_insert(const Value& v,const Key& k, BiTreeNode<Value, Key>*& nodeptr) {
    if(nodeptr== nullptr) {
        nodeptr = new BiTreeNode<Value, Key>(v, k);     // 同时更改了根节点
        return;
    }
    if(k < nodeptr->key) _insert(v, k, nodeptr->leftPtr);
    else _insert(v, k, nodeptr->rightPtr);
}

template<typename Value, typename Key>
BiTreeNode<Value, Key>& BiTreeNode<Value, Key>::_deleteMin(BiTreeNode<Value, Key> *nodeptr) {
    if (nodeptr== nullptr) throw "输入的节点为空，请检查输入"; // 特判

    BiTreeNode<Value, Key> *chPtr, *paPtr;
    chPtr = nodeptr;
    paPtr = nullptr;
    while(chPtr->leftPtr != nullptr){
        paPtr = chPtr;
        chPtr = chPtr->leftPtr;
    }

    // 特判根节点
    if(paPtr== nullptr){
        return *chPtr;
    }
    // 1. chPtr 是这棵子树最小的节点， 它至多有一个子节点(并且为右子节点)  2. chPtr 一定是 paPtr 的左节点
    if(chPtr->leftPtr== nullptr && chPtr->rightPtr== nullptr){
        paPtr->leftPtr = nullptr;
        return *chPtr;
    }
    if(chPtr->rightPtr!= nullptr){
        paPtr->leftPtr = chPtr->rightPtr;
        chPtr->rightPtr = nullptr;
        return *chPtr;
    }
}

template<typename Value, typename Key>
void BiTreeNode<Value, Key>::_delete(const Key& k, BiTreeNode<Value, Key> *& nodeptr, BiTreeNode<Value, Key> * parentnodePtr) {
    BiTreeNode<Value, Key> *paPtr, *chPtr;
    chPtr = nodeptr;
    paPtr = parentnodePtr;
    int pa_type = 0;   // 标识是左或右儿子
    while(chPtr->key!=k && chPtr!= nullptr){
        paPtr = chPtr;
        if(k<chPtr->key) chPtr = chPtr->leftPtr, pa_type=0;
        else chPtr = chPtr->rightPtr, pa_type=1;
    }
    if(chPtr== nullptr) throw "未找到需要删除的节点";
    // 若找到，进行下一步
    // 特判根节点(要删除根节点)
    if(paPtr== nullptr){
        if(chPtr->rightPtr== nullptr){
            nodeptr = chPtr->leftPtr;
            delete chPtr;
            return;
        }
        nodeptr = chPtr->rightPtr;    // 更改树的根节点（通过引用）
        BiTreeNode<Value, Key>* minNodePtr = chPtr->rightPtr;
        while(minNodePtr->leftPtr != nullptr) minNodePtr = minNodePtr->leftPtr;
        minNodePtr->leftPtr = chPtr->leftPtr;
        delete chPtr;
        return;
    }

    // 1. no child node
    if(chPtr->leftPtr== nullptr && chPtr->rightPtr== nullptr){
        if(!pa_type) paPtr->leftPtr = nullptr;
        else paPtr->rightPtr = nullptr;

        delete chPtr;
    }
    // 2. only one child node
    else if(chPtr->leftPtr== nullptr && chPtr->rightPtr!= nullptr){
        if(!pa_type) paPtr->leftPtr = chPtr->rightPtr;
        else paPtr->rightPtr = chPtr->rightPtr;
        delete chPtr;
    }

    else if(chPtr->leftPtr!= nullptr && chPtr->rightPtr== nullptr){
        if(!pa_type) paPtr->leftPtr = chPtr->leftPtr;
        else paPtr->rightPtr = chPtr->leftPtr;
        delete chPtr;
    }

    // 3. have two child node
    else{
        BiTreeNode<Value, Key>& minNode = _deleteMin(chPtr->rightPtr);
        minNode.leftPtr = chPtr->leftPtr;
        minNode.rightPtr = chPtr->rightPtr;
        if(!pa_type) paPtr->leftPtr = &minNode;
        else paPtr->rightPtr = &minNode;

        delete chPtr;
    }
}

template<typename Value, typename Key>

BiTreeNode<Value, Key> &BiTreeNode<Value, Key>::_search(Key k, BiTreeNode<Value, Key> *&nodeptr) {  // 此处使用递归，也可以直接循环
    if (nodeptr == nullptr) {
        throw "输入节点为空，请检查输入";
    }
    if (k == nodeptr->key) {
        return *nodeptr;
    } else if (k < nodeptr->key) {
        return _search(k, nodeptr->leftPtr);
    } else {
        return _search(k, nodeptr->rightPtr);
    }
}

template<typename Value, typename Key>
BSTree<Value, Key>::BSTree(): rootptr(nullptr) {}

template<typename Value, typename Key>
BSTree<Value, Key>::BSTree(const BiTreeNode<Value, Key>& r) {
    this->rootptr = new BiTreeNode<Value, Key>(r);
}


template<typename Value, typename Key>
BSTree<Value, Key>::BSTree(const BSTree<Value, Key> &other) {
// 复制整棵树
rootptr = nullptr;





}

template<typename Value, typename Key>
BiTreeNode<Value, Key> &BSTree<Value, Key>::Root() {
    return *rootptr;
}

template<typename Value, typename Key>
BiTreeNode<Value, Key>* &BSTree<Value, Key>::RootPtr() {
    return rootptr;
}

template<typename Value, typename Key>
void BSTree<Value, Key>::preOrder() {
    BiTreeNode<Value, Key>::_preOrder(rootptr);
    std::cout << std::endl;
}

template<typename Value, typename Key>
void BSTree<Value, Key>::inOrder() {
    BiTreeNode<Value, Key>::_inOrder(rootptr);
    std::cout << std::endl;
}

template<typename Value, typename Key>
void BSTree<Value, Key>::postOrder() {
    BiTreeNode<Value, Key>::_postOrder(rootptr);
    std::cout << std::endl;
}

template<typename Value, typename Key>
void BSTree<Value, Key>::Insert(Value v, Key k) {
    BiTreeNode<Value, Key>::_insert(v, k, rootptr);
}

template<typename Value, typename Key>
void BSTree<Value, Key>::Delete(Key key) {
    BiTreeNode<Value, Key>::_delete(key, rootptr, nullptr);
}

template<typename Value, typename Key>
void BSTree<Value, Key>::Search(Key key) {
    BiTreeNode<Value, Key>::_search(key, rootptr);
}

#endif
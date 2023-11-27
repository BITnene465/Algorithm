/**
 * @file AVL.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 平衡二叉搜索树练习
 * @version 0.1
 * @date 2023-11-04
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// 仅作为数据结构练习，所以不封装了

#include <bits/stdc++.h>
using namespace std;
// AVL树节点的结构
struct Node
{
    int data;
    Node *ls, *rs;
    int height; // 节点的高度

    Node(int value) : data(value), ls(nullptr), rs(nullptr), height(1) {}
};

int getHeight(Node *node)
{
    if (node == nullptr)
        return 0;
    return node->height;
}
void updateHeight(Node *node)
{
    node->height = 1 + max(getHeight(node->ls), getHeight(node->rs));
}
int getBalanceFactor(Node *node)
{
    if (node == nullptr)
        return 0;
    return getHeight(node->ls) - getHeight(node->rs);
}

// 左旋转
void leftRotate(Node *&xx)
{
    Node *x = xx;
    Node *y = x->rs;
    Node *T2 = y->ls;

    y->ls = x;
    x->rs = T2;

    updateHeight(x);
    updateHeight(y);

    xx = y;
}

// 右旋转
void rightRotate(Node *&yy)
{
    Node *y = yy;
    Node *x = y->ls;
    Node *T2 = x->rs;

    x->rs = y;
    y->ls = T2;

    updateHeight(y);
    updateHeight(x);

    yy = x;
}

// 插入节点
void insert(Node* &root, int value)
{
    if (root == nullptr)
    {
        root = new Node(value);
        return;
    }
    if (value <= root->data) insert(root->ls, value);
    else if (value > root->data) insert(root->rs, value);
    // 更新节点的高度
    updateHeight(root);
    // 获取节点的平衡因子,为左子树高度减去右子树高度
    int balance = getBalanceFactor(root);
    // 平衡维护, 既然balance不是0，那么一定有字数，所以无需判断NULL了
    if (balance > 1)
    {
        int balance2 = getBalanceFactor(root->ls);
        if (balance2>=0)
        {
            // LL情况
            rightRotate(root);
            return;
        }
        else
        {
            // LR情况
            leftRotate(root->ls);
            rightRotate(root);
            return;
        }
    }

    if (balance < -1)
    {
        int balance2 = getBalanceFactor(root->rs);
        if (balance2<=0)
        {
            // RR情况
            leftRotate(root);
            return;
        }
        else
        {
            // RL情况
            rightRotate(root->rs);
            leftRotate(root);
            return;
        }
    }
}
void inOrderTraversal(Node *root)  // 二叉搜索树的中序遍历即为排序
{
    if (root)
    {
        inOrderTraversal(root->ls);
        cout << root->data << " ";
        inOrderTraversal(root->rs);
    }
}

/*
    由GPT编写的可视化的函数
*/
// 获取AVL树的最大宽度
int getMaxWidth(Node *root)
{
    if (root == nullptr)
        return 0;

    int maxWidth = 0;
    int levelWidth;
    Node *current;

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        levelWidth = q.size();
        maxWidth = max(maxWidth, levelWidth);

        while (levelWidth--)
        {
            current = q.front();
            q.pop();

            if (current->ls)
            {
                q.push(current->ls);
            }
            if (current->rs)
            {
                q.push(current->rs);
            }
        }
    }

    return maxWidth;
}

// 在控制台上可视化显示AVL树
void printAVLTree(Node *root)
{
    int treeHeight = getHeight(root);
    int maxWidth = getMaxWidth(root);

    int space = 3;

    // 计算树的宽度，用于设置缩进
    int treeWidth = int(pow(2, treeHeight - 1)) * (2 * space);

    queue<Node *> q;
    q.push(root);

    for (int level = 0; level < treeHeight; level++)
    {
        int levelWidth = int(pow(2, level));
        int nodeSpacing = treeWidth / (levelWidth + 1);

        for (int i = 0; i < levelWidth; i++)
        {
            if (i == 0)
            {
                cout << string(nodeSpacing, ' ');
            }
            else
            {
                cout << string(2 * space, ' ');
            }

            if (!q.empty())
            {
                Node *current = q.front();
                q.pop();

                if (current)
                {
                    cout << current->data;
                    q.push(current->ls);
                    q.push(current->rs);
                }
                else
                {
                    cout << " ";
                    q.push(nullptr);
                    q.push(nullptr);
                }
            }
            else
            {
                q.push(nullptr);
                q.push(nullptr);
                cout << " ";
            }

            cout << string(nodeSpacing - space, ' ');
        }

        cout << endl;

        // 减小间距，以便下一层
        space = (space - 1) / 2;
    }
}
// 测试部分
int main()
{
    Node *root = nullptr;
    insert(root, 10);
    insert(root, 20);
    insert(root, 30);
    insert(root, 40);
    insert(root, 50);
    insert(root, 25);

    cout << "中序遍历结果: ";
    inOrderTraversal(root);
    cout << endl;

    cout << "AVL树可视化:\n";
    printAVLTree(root);


    while(1)
    {
        int val;
        cout<< "要插入的元素:" ;
        cin>> val;
        insert(root, val);
        cout << "AVL树可视化:\n";
        printAVLTree(root);
        cout << "当前AVL树的高度:" << getHeight(root) << endl;
    }
    return 0;
}
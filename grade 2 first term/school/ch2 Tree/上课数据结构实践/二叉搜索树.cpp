/**
 * @file 二叉搜索树.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 数据结构与算法练手
 * @version 0.1
 * @date 2023-11-04
 *
 * @copyright Copyright (c) 2023
 *
 */
// BST,二叉搜索树
// 和顺序表中的二分查找相同
// 先学基本原理，封装的事情之后再搞
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    Node *rs, *ls;
    Node(int val) : val(val), rs(NULL), ls(NULL){};
};
int n, arr[1005];
void insert(int val, Node *&rt)
{
    if (rt == NULL)
    {
        rt = new Node(val);
        return;
    }
    if (val <= rt->val)
        insert(val, rt->ls);
    else
        insert(val, rt->rs);
}
void build(int *arr, int l, int r, Node *&root) // 通过不断插入来建树
{
    for (int i = l; i <= r; ++i)
        insert(arr[i], root);
}
int find_max(int x, Node *&rt) // 搜索第一个>=x的数
{
    if (rt->val == x)
        return x;
    if (rt->val > x)
    {
        if (rt->ls == NULL)
            return rt->val;
        if (rt->ls->val < x)
            return rt->val;
        return find_max(x, rt->ls);
    }
    else
    {
        if (rt->rs == NULL)
            return INT_MAX; // 原表中不存在
        return find_max(x, rt->rs);
    }
}
int find_min(int x, Node *&rt) // 搜索第一个<=x的数
{
    if (rt->val == x)
        return x;
    if (rt->val > x)
    {
        if (rt->ls == NULL)
            return INT_MIN; // 原表中不存在
        return find_min(x, rt->ls);
    }
    else
    {
        if (rt->rs == NULL)
            return rt->val;
        if (rt->rs->val > x)
            return rt->val;
        return find_min(x, rt->rs);
    }
}
void InOrder(Node *rt) // 中序遍历，即为排序！！
{
    if (rt == NULL)
        return;     // 别忘记终止条件！！！
    InOrder(rt->ls);
    printf("%d ", rt->val);
    InOrder(rt->rs);
}

// 由GPT写的可视化部分
/// 打印二叉搜索树以可视化方式
void printBST(Node *root, int level = 0, const string &prefix = "", bool isLeft = false)
{
    if (root == nullptr)
    {
        return;
    }

    if (level > 0)
    {
        cout << "\n"
             << setw(level * 4) << " ";
    }

    cout << (isLeft ? "├──" : "└──") << root->val;

    printBST(root->ls, level + 1, "L:", true);
    printBST(root->rs, level + 1, "R:", false);
}

// 测试函数
int main(void)
{
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i)
        scanf("%d", arr + i);
    Node *root = NULL;
    build(arr, 1, n, root);
    printf("序列排序后为：");
    InOrder(root);
    printf("\n");

    // 可视化部分,GPT编写
    printf("可视化BST:\n");
    printBST(root);
    printf("\n");
    //

    while (1)
    {
        printf("你要查询的数：");
        int x;
        scanf("%d", &x);
        printf("第一个大于他的元素为:%d 第一个小于他的元素为:%d\n", find_max(x, root), find_min(x, root));
    }
    return 0;
}
/**
 * @file 排序二叉树(new).cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 重写的版本，仍然用数组存储二叉树
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    int ls, rs;
    int depth;
} tr[1000005];
int rt, tot;
void insert(int val, int &rt)
{
    if (!rt)
    {
        rt = ++tot;
        tr[rt].val = val;
        tr[rt].ls = tr[rt].rs = 0;
        return;
    }
    if (tr[rt].val < val)
        insert(val, tr[rt].rs);
    else
        insert(val, tr[rt].ls);
}
void preDep(int rt)   // 预处理一棵静态树的深度
{   
    queue<int> q;
    q.push(rt);
    int nowdep = 0;
    while(!q.empty())
    {
        int cnt = q.size();
        nowdep++;
        while(cnt-- >0)
        {
            int u = q.front(); q.pop();
            tr[u].depth = nowdep;
            if(tr[u].ls) q.push(tr[u].ls);
            if(tr[u].rs) q.push(tr[u].rs);
        }
    }
}
void printTree(int rt)
{ // 类似于中序遍历，但是需要width
    if (!rt)
        return;
    printTree(tr[rt].ls);
    for(int i=1;i<=tr[rt].depth-1;++i) printf("    ");
    printf("%d\n", tr[rt].val);
    printTree(tr[rt].rs);
}
void inorderTraverse(int rt)
{
    if (!rt)
        return;
    inorderTraverse(tr[rt].ls);
    printf(" %d", tr[rt].val);
    inorderTraverse(tr[rt].rs);
}
int main(void)
{
    // rt 初始时为 0，代表是空树
    while (1)
    {
        int val;
        scanf("%d", &val);
        if (!val)
            break;
        insert(val, rt);
    }
    preDep(rt);
    printTree(rt);
    printf("\n");
    inorderTraverse(rt);
    printf("\n");
    return 0;
}
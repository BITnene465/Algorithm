/**
 * @file 平衡二叉树.cpp
 * @author tanjingyuan (nene_465@foxmail.com)
 * @brief 采用数组实现AVL，并且采用凹入表示打印AVL
 * @version 0.1
 * @date 2023-11-10
 * 
 * @copyright Copyright (c) 2023
 * 
 */
// 还有点问题 //
#include<bits/stdc++.h>
using namespace std;
struct Node{
    char val;
    int ls, rs;
    int depth;
    int height;
}avlNode[10005];
int tot; int rt; char s[105];
void updHeight(int rt);
int getHeight(int rt);
void leftRotate(int& rt);
void rightRotate(int& rt);
void build(int& rt, char* s);
void insert(int& rt, char ch);
void preDep(int rt);
void printTree(int rt);
void preOrder(int rt);
void inOrder(int rt);
void postOrder(int rt);
// 测试代码
int main(void)
{
    scanf("%s", s);
    build(rt, s);
    printf("Preorder: ");
    preOrder(rt);
    printf("\n");
    printf("Inorder: ");
    inOrder(rt);
    printf("\n");
    printf("Postorder: ");
    postOrder(rt);
    printf("\n");

    // leftRotate(rt);   // 题目要求左旋90
    preDep(rt);
    printf("Tree:\n");
    printTree(rt);
    return 0;
}
// 建树相关
void build(int& rt, char* s)
{
    int l = strlen(s);
    for(int i=0;i<l;++i)insert(rt, s[i]);
}   
void insert(int& rt, char ch)   // 多半是这里的问题
{
    if(!rt){
        rt = ++tot;
        avlNode[rt].val = ch;
        avlNode[rt].ls = avlNode[rt].rs = 0;
        return;
    }
    if(ch<=avlNode[rt].val) insert(avlNode[rt].ls, ch);  
    else insert(avlNode[rt].rs, ch);
    // 更新高度
    updHeight(rt);
    // 旋转调整
    int& rs = avlNode[rt].rs;
    int& ls = avlNode[rt].ls;
    if(getHeight(ls) - getHeight(rs) > 1)
    {   
        if(getHeight(avlNode[ls].ls) > getHeight(avlNode[ls].rs)){ // LL ， 反正二者也不可能相等
            rightRotate(rt);
            return;
        }
        else {  // LR
            leftRotate(ls);
            rightRotate(rt);
            return;
        }
    }
    else if(getHeight(ls) - getHeight(rs) < -1)
    {
        if (getHeight(avlNode[rs].rs) > getHeight(avlNode[rs].ls))
        { // RR
            leftRotate(rt);
            return;
        }
        else
        { // RL
            rightRotate(rs);
            leftRotate(rt);
            return;
        }
    } 
    // 如果左右子树的高度相差不大于1，那么无需旋转调整
}
int getHeight(int rt)
{
    if(!rt)return -1;   // 不能是0，必须是-1
    else return avlNode[rt].height;
}
void updHeight(int rt)
{
    avlNode[rt].height = max(getHeight(avlNode[rt].ls), getHeight(avlNode[rt].rs)) + 1;
}
void leftRotate(int& rt)
{
    int t = rt;
    rt = avlNode[rt].rs;
    avlNode[t].rs = avlNode[rt].ls;
    avlNode[rt].ls = t;

    // 千万不要忘记更新高度
    updHeight(t);
    updHeight(rt);
}
void rightRotate(int& rt)
{
    int t = rt;
    rt = avlNode[rt].ls;
    avlNode[t].ls = avlNode[rt].rs;
    avlNode[rt].rs = t;

    // 千万不要忘记更新高度
    updHeight(t);
    updHeight(rt);
}
// 三种遍历
void preOrder(int rt)
{
    if (!rt)
        return;
    printf("%c", avlNode[rt].val);
    preOrder(avlNode[rt].ls);
    preOrder(avlNode[rt].rs);
}
void inOrder(int rt)
{
    if (!rt)
        return;
    inOrder(avlNode[rt].ls);
    printf("%c", avlNode[rt].val);
    inOrder(avlNode[rt].rs);
}
void postOrder(int rt)
{
    if (!rt)
        return;
    postOrder(avlNode[rt].ls);
    postOrder(avlNode[rt].rs);
    printf("%c", avlNode[rt].val);
}
// 预处理深度,bfs by floor
void preDep(int rt)
{
    queue<int> q;
    q.push(rt);
    int nowdep = 0;
    while(!q.empty())
    {
        int cnt = q.size();
        nowdep++;
        while(cnt-- > 0)
        {
            int u = q.front();
            q.pop();
            avlNode[u].depth = nowdep;
            if (avlNode[u].ls)
                q.push(avlNode[u].ls);
            if (avlNode[u].rs)
                q.push(avlNode[u].rs);
        }
    }
}
// 打印凹入表示的树
void printTree(int rt)
{ // 奇怪的题目，得先右再左
    if (!rt)
        return;
    printTree(avlNode[rt].rs);
    for (int i = 1; i <= avlNode[rt].depth - 1; ++i)
        printf("    ");
    printf("%c\n", avlNode[rt].val);
    printTree(avlNode[rt].ls);
}
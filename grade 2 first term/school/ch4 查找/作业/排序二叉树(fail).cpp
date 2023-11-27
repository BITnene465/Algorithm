// 也就是二叉搜索树 //
// 链表形式写腻了，所以直接使用顺序表来实现 //
// 这个版本的代码对于二叉树的凹入表示理解错了，其他部分符合要求 //
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int val;
    int ls, rs;
}tr[1000005];
int rt, tot;
void insert(int val, int &rt)
{
    if(!rt){
        rt = ++tot;
        tr[rt].val = val;
        tr[rt].ls = tr[rt].rs = 0;
        return;
    }
    if(tr[rt].val < val) insert(val, tr[rt].rs);
    else insert(val, tr[rt].ls);
}
int getStartWidth(int rt)
{
    if(!rt)return 0;
    int width = 0;
    while (tr[rt].ls)
    {
        width += 4;
        rt = tr[rt].ls;
    }
    width = max(width, getStartWidth(tr[rt].rs) - 4);
    return width;
}
void printTree(int rt)
{
    int startWidth = getStartWidth(rt);
    queue<pair<int, int>> q;
    q.push(make_pair(rt, startWidth));
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount-- > 0)
        {
            auto p = q.front();
            q.pop();
            for(int i=1;i<=p.second;++i)cout<<" ";
            cout<<tr[p.first].val<<endl;
            if (tr[p.first].ls != 0)
                q.push(make_pair(tr[p.first].ls, p.second - 4));
            if (tr[p.first].rs != 0)
                q.push(make_pair(tr[p.first].rs, p.second + 4));
        }
    }
}
void inorderTraverse(int rt)
{
    if(!rt) return;
    inorderTraverse(tr[rt].ls);
    printf(" %d", tr[rt].val);
    inorderTraverse(tr[rt].rs);
}
int main(void)
{
    // rt 初始时为 0，代表是空树
    while(1)
    {
        int val;
        scanf("%d", &val);
        if(!val) break;
        insert(val, rt);
    }
    printTree(rt);
    inorderTraverse(rt);
    return 0;
}
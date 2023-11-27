// 利用前序遍历和中序遍历建树请见 hdu 1710 ， 此处完全类似 //
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    node *ls,*rs;
};
typedef node* BiTree;
char in[10005];
char post[10005];
// 打印层次遍历序列 , 第一次该函数出现了 RE （所以说现版本是稳定的）
void PrintByLevelOrder(node* tr)
{
    if (tr == NULL)  return;
    queue<node*> q;
    q.push(tr);
    while (!q.empty())
    {
        int nodeCount = q.size();
        while (nodeCount-- > 0)
        {
            node* p = q.front();
            cout << p->data;
            q.pop();
            if (p->ls != NULL)q.push(p->ls);
            if (p->rs != NULL)q.push(p->rs);
        }
    }
    cout << endl;
}
void BuildTreeByInAndPost(BiTree &tr, int l, int r, int &cur){
    // 递归建树 , 调用方式 BuildTreeByInAndPost(T, 0, n-1, cur) 其中 cur初始化为 n-1,因为后序遍历需要从后面找根节点
    if(cur<0)return;  // 边界条件
    int idx = -1;
    for(int i=l;i<=r;++i){
        if(in[i]==post[cur]){
            idx = i;
            break;
        }
    }
    if(idx==-1)return;   // 没找到
    tr = new node;
    tr->ls = tr->rs = NULL;
    tr->data = in[idx];
    // 递归建树 , 先右儿子，再左儿子，因为这是后序遍历
    --cur;
    if(idx<r) BuildTreeByInAndPost(tr->rs, idx+1, r, cur);
    if(idx>l) BuildTreeByInAndPost(tr->ls, l, idx-1, cur);
}
int main(void)
{
    scanf("%s",in);
    scanf("%s",post);
    int n = strlen(in);
    BiTree T = NULL;   // 创建一棵空二叉树
    int cur = n - 1;
    BuildTreeByInAndPost(T, 0, n-1, cur);
    // 按层输出二叉树
    PrintByLevelOrder(T);
    return 0;
}
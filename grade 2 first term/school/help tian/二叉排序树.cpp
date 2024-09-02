#include <bits/stdc++.h>
using namespace std;
int n, arr[100005], delv, arr2[100005];
struct Node
{
    int value;
    Node *rs, *ls;
    Node(int val) : value(val), ls(NULL), rs(NULL){};
};
typedef Node *BiTree;
void Insert(Node *&root, int val)
{
    if (root == NULL)
    {
        root = new Node(val);
        return;
    }
    if (root->value < val)
    {
        Insert(root->rs, val);
    }
    else
    {
        Insert(root->ls, val);
    }
}
void Create(BiTree &root, int arr[], int n)
{
    for (int i = 1; i <= n; ++i)
        Insert(root, arr[i]);
}
void Inorder(Node *rt)
{
    if (rt == NULL)
        return;
    Inorder(rt->ls);
    printf(" %d", rt->value);
    Inorder(rt->rs);
}
int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    cin >> delv;
    // operate
    printf("原始数据：");
    for (int i = 1; i <= n; ++i)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");

    BiTree tr = NULL; // 必须赋初值！！！
    Create(tr, arr, n);
    printf("中序遍历结果：");
    Inorder(tr);
    printf("\n");

    int cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        if (arr[i] != delv)
            arr2[++cnt] = arr[i];
    }
    BiTree tr2 = NULL;
    Create(tr2, arr2, cnt);
    printf("删除结点后结果：");
    if(cnt!=n)Inorder(tr2);
    else printf("没有%d节点", delv);
    printf("\n");
    return 0;
}

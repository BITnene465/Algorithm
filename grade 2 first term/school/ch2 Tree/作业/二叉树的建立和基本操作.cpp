#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct node{
    char val;
    node *ls,*rs;
};
typedef node* Bitree;    // Bitree 实际就是指向节点的指针
void CreateTreeByString(Bitree &tr, string s, int &i)   // 调用方式 CreateTreeByString(T,s,0)
{
    if(i>=s.length())return;   // 终止函数
    if(s[i] == '#'){
        tr = NULL;
        return;
    }
    tr = new node;
    tr->val = s[i];
    CreateTreeByString(tr->ls, s, ++i);
    CreateTreeByString(tr->rs, s, ++i);
}
void PreOrder(Bitree tr)
{
    if(tr==NULL)return;
    printf("%c",tr->val);
    PreOrder(tr->ls);
    PreOrder(tr->rs);
}
void InOrder(Bitree tr)
{
    if(tr==NULL)return;
    InOrder(tr->ls);
    printf("%c",tr->val);
    InOrder(tr->rs);
}
void PostOrder(Bitree tr)
{
    if(tr==NULL)return;
    PostOrder(tr->ls);
    PostOrder(tr->rs);
    printf("%c",tr->val);
}
// 辅助函数
void Dfs(Bitree tr ,int &cnt){
    if(tr==NULL)return;
    if(tr->ls==NULL && tr->rs==NULL){
        cnt++;
        return;
    }
    if(tr->ls)Dfs(tr->ls,cnt);
    if(tr->rs)Dfs(tr->rs,cnt);
}
int GetLeafNumber(Bitree tr)
{
    int cnt = 0;
    Dfs(tr, cnt);
    return cnt;
}
void SwapAllLRSon(Bitree& tr)
{
    if(tr==NULL)return;
    SwapAllLRSon(tr->ls);
    SwapAllLRSon(tr->rs);
    swap(tr->rs,tr->ls);
}
void PrintAsPreConcave(Bitree tr,int depth)   // 调用方法 PrinAsPreConcave(T, 0)
{
    if(tr==NULL)return;
    for(int i=0;i<4*depth;++i)putchar(' ');
    putchar(tr->val);
    putchar('\n');
    PrintAsPreConcave(tr->ls, depth+1);
    PrintAsPreConcave(tr->rs, depth+1);
}
int main(void)
{
    string s;
    cin>>s;
    Bitree T;    // 创建一棵空树
    int cur = 0;
    CreateTreeByString(T, s, cur);
    printf("BiTree\n");
    PrintAsPreConcave(T, 0);
    printf("pre_sequence  : ");
    PreOrder(T);
    printf("\n");
    printf("in_sequence   : ");
    InOrder(T);
    printf("\n");
    printf("post_sequence : ");
    PostOrder(T);
    printf("\n");
    printf("Number of leaf: %d\n",GetLeafNumber(T));
    SwapAllLRSon(T);
    printf("BiTree swapped\n");
    PrintAsPreConcave(T, 0);
    printf("pre_sequence  : ");
    PreOrder(T);
    printf("\n");
    printf("in_sequence   : ");
    InOrder(T);
    printf("\n");
    printf("post_sequence : ");
    PostOrder(T);
    printf("\n");
    return 0;
}

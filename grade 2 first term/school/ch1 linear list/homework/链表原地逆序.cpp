#include <iostream>  
using namespace std;  
  
typedef int ElemType;  
typedef struct node  
{   ElemType    data;  
    struct node * next;  
} NODE;  
typedef NODE * LinkList;  
  
void output( LinkList );  
// void change( int, int, NODE * );   // 无用的函数，直接注释掉
LinkList createList( ElemType );  
void inverse( LinkList );   
  
LinkList createList( ElemType finish )  //finish：数据结束标记   
{  
    ElemType x;  
    NODE *newNode;   
    LinkList first = new NODE;   // 建立头结点  
    first->next = NULL;  
    first->data = finish;  
    cin >> x;                 // 约定以finish结束连续输入  
    while ( x != finish )  
    {  
        newNode = new NODE;      // 建立新结点  
        newNode->data = x;  
        newNode->next = first->next; // ①  
        first->next = newNode;       // ②  
        cin >> x;  
    }  
    return first;  
}  
  
void output( LinkList head )  
{   cout << "List:";  
    while ( head->next != NULL )  
    {   cout << head->next->data << ",";  
        head = head->next;  
    }  
    cout << endl;  
}  
  
int main(int argc, char** argv)   
{  
    LinkList head;  
  
    head = createList( -1 );  
    output( head );  
    inverse( head );  
    output( head );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
// 原地翻转单向链表： 从链表一号节点（头结点的下一个节点）开始，翻转所有链表指针的指向  //
void inverse(LinkList L)
{
    if(!(L->next)||!(L->next->next))return;   // 只有一个或0个元素就不用反转了
    node* pre = NULL;   // 挺好的，原来的首元素的前一个默认为 NULL
    node* p = L->next;
    node* tmp;
    while(p)
    {
        tmp = p->next;
        p->next = pre;
        pre = p;
        p = tmp;
    }
    // 此时 pre 是末尾元素（原）
    L->next = pre;
    return;
}
/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */  
 
#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
NODE * find( NODE * , int * );  
void outputring( NODE * );  
void change( int , int , NODE * );  
void outputring( NODE * pring )  
{   NODE * p;  
    p = pring;  
    if ( p == NULL )  
        printf("NULL");  
    else  
        do  {   printf("%d", p->data);  
            p = p->next;  
        } while ( p != pring );  
    printf("\n");  
    return;  
}  
  
int main()  
{   int n, m;  
    NODE * head, * pring;  
  
    scanf("%d%d", &n, &m);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
  
    change( n, m, head );  
    pring = find( head, &n );  
    printf("ring=%d\n", n);  
    outputring( pring );  
  
    return 0;  
}  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

// 直接从上一道题借来的
void change(int n,int m,node* head)
{
    // init
    node* pnode;
    node* tmp[10005];
    pnode = head;
    //
    int length = 10004;   // 最大长度
    int q[10005],r[10005];  // 商和余数, data[i] = q[i-1]/m , q[i] = r[i]*10 , r[i] = q[i-1]%m
    r[0] = n;
    q[0] = r[0]*10;
    int idx,flag=0;
    for(int i=1;i<=length&&q[i-1];++i)   // q[i-1] == 0 时说明从第 i 位开始全部是0 ，不用写了
    {
        int data = q[i-1]/m;
        r[i] = q[i-1]%m;
        q[i] = r[i]*10;
        
        pnode->next = new node();
        pnode = pnode->next;
        pnode->data = data;
        pnode->next = NULL;
        // 空间换时间
        tmp[i] = pnode;
        // check start
        for(int j=0;j<i;++j){if(q[j]==q[i]){idx=j;flag=1;break;}}
        if(flag)break;
        // check end
    }
    if(flag)// 如果找到了循环节，那么要将 pnode->next 指向 链表的第 idx+1 号元素
    {
        pnode->next = tmp[idx+1];
        return;
    }
    // 没找到说明是有限小数 直接返回即可
    return;
}
// 找到循环节
NODE* find(node* head, int* n ) 
{ 
    node* tmp[10005];
    tmp[0] = head;
    node* pnode=head->next;
    int idx = 0,flag = 0;
    int idxx;
    while(pnode)
    {
        tmp[++idx]=pnode;
        pnode = pnode->next;
        for(int i=1;i<idx;++i)if(tmp[idx]==tmp[i]){idxx=i;flag=1;break;}
        if(flag)break;
    }
    if(flag)
    {
        *n = idx-idxx;
        return tmp[idxx];
    }
    *n = 0;
    return NULL;
}  
  
  
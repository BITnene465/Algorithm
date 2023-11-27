#include <stdio.h>  
#include <stdlib.h>  
typedef struct node  
{   int    coef, exp;  
    struct node  *next;  
} NODE;  
  
void multiplication( NODE *, NODE * , NODE * );  
void input( NODE * );  
void output( NODE * );  
  
void input( NODE * head )  
{   int flag, sign, sum, x;  
    char c;  
  
    NODE * p = head;  
  
    while ( (c=getchar()) !='\n' )  
    {  
        if ( c == '<' )  
        {    sum = 0;  
             sign = 1;  
             flag = 1;  
        }  
        else if ( c =='-' )  
             sign = -1;  
        else if( c >='0'&& c <='9' )  
        {    sum = sum*10 + c - '0';  
        }  
        else if ( c == ',' )  
        {    if ( flag == 1 )  
             {    x = sign * sum;  
                  sum = 0;  
                  flag = 2;  
          sign = 1;  
             }  
        }  
        else if ( c == '>' )  
        {    p->next = ( NODE * ) malloc( sizeof(NODE) );  
             p->next->coef = x;  
             p->next->exp  = sign * sum;  
             p = p->next;  
             p->next = NULL;  
             flag = 0;  
        }  
    }  
}  
  
void output( NODE * head )  
{  
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
}  
  
int main()  
{   NODE * head1, * head2, * head3;  
  
    head1 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head1 );  
  
    head2 = ( NODE * ) malloc( sizeof(NODE) );  
    input( head2 );  
  
    head3 = ( NODE * ) malloc( sizeof(NODE) );  
    head3->next = NULL;  
    multiplication( head1, head2, head3 );  
  
    output( head3 );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  

void multiplication( NODE * p1, NODE * p2 , NODE * p3)
{
    node *pnode1,*pnode2;
    for(pnode1=p1;pnode1->next;pnode1=pnode1->next);
    for(pnode2=p2;pnode2->next;pnode2=pnode2->next);
    int max_exp1 = pnode1->exp, max_exp2 = pnode2->exp;
    int* new_coef = new int[(max_exp1+max_exp2+1)];   // 分配动态内存，不浪费空间
    for(int i=0;i<=max_exp1+max_exp2;++i)new_coef[i]=0;
    // 遍历链表
    for(pnode1=p1->next;pnode1;pnode1=pnode1->next)
        for(pnode2=p2->next;pnode2;pnode2=pnode2->next)
            new_coef[pnode1->exp+pnode2->exp] += pnode1->coef*pnode2->coef;
    // 存入新链表
    node *pnode;
    pnode = p3;
    for(int i=0;i<=max_exp1+max_exp2;++i)
    {
        if(!new_coef[i])continue;   // 为0就没必要存了
        pnode->next = new node();
        pnode = pnode->next;
        pnode->next = NULL;
        pnode->exp = i;
        pnode->coef = new_coef[i];
    }
    // 管理内存
    delete[] new_coef;
    return;
}  
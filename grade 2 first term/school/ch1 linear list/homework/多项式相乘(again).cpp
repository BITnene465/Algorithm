#include <stdio.h>  
#include <stdlib.h>  
#include<bits/stdc++.h>
using namespace std;
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
    if(head->next==NULL){printf("<0,0>,\n");return;}   // 0多项式也是一个坑点!!!!
    while ( head->next != NULL )  
    {   head = head->next;  
        printf("<%d,%d>,", head->coef, head->exp );  
    }  
    printf("\n");  
    return;
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
map<int,int> m;
void multiplication( NODE * p1, NODE * p2 , NODE * p3)
{
    node *pnode1,*pnode2;
    // 遍历链表
    for(pnode1=p1->next;pnode1;pnode1=pnode1->next)
        for(pnode2=p2->next;pnode2;pnode2=pnode2->next)
        {
            int coef = pnode1->coef*pnode2->coef;
            int exp = pnode1->exp+pnode2->exp;
            if(m.count(exp))m[exp] += coef;
            else m[exp] = coef;
        }
    // 存入新链表
    node *pnode;
    pnode = p3;
    for(auto kv:m)
    {
        if(!kv.second) continue;  // 是 0 直接跳过
        pnode->next = new node();
        pnode = pnode->next;
        pnode->next = NULL;
        pnode->exp = kv.first;
        pnode->coef = kv.second;
    }
    return;
}  
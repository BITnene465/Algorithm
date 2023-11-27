#include <stdio.h>  
#include <stdlib.h>  
  
typedef struct node  
{   int         data;  
    struct node * next;  
} NODE;  
  
void output( NODE *, int );  
void change( int, int, NODE * );  
  
void output( NODE * head, int kk )  
{   int k=0;  
  
    printf("0.");  
    while ( head->next != NULL && k<kk )  
    {   printf("%d", head->next->data );  
        head = head->next;  
        k ++;  
    }  
    printf("\n");  
}  
  
int main()  
{   int n, m,k;  
    NODE * head;  
  
    scanf("%d%d%d", &n, &m, &k);  
    head = (NODE *)malloc( sizeof(NODE) );  
    head->next = NULL;  
    head->data = -1;  
    change( n, m, head );  
    output( head,k );  
    return 0;  
}  
  
/* PRESET CODE END - NEVER TOUCH CODE ABOVE */  
void change(int n,int m,node* head)
{
    // init
    node* pnode;
    node* tmp[105];
    pnode = head;
    //
    int length = 104;   // 最大长度
    int q[105],r[105];  // 商和余数, data[i] = q[i-1]/m , q[i] = r[i]*10 , r[i] = q[i-1]%m
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


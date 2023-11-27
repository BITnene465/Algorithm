// 自己设计代码，为了追求简单，选择使用不带有头结点的广义表来实现 //
// 挺逆天不写了

#include<iostream>
#include<cstdio>
using namespace std;
typedef enum{SUCCESS,FAIL} Status;
struct node{
    bool isAtom;
    union{
        char atom;
        node* hp;
    } ptr;
    node* tp;
    // 构造方法
};
bool isalpha(char ch)
{
    if(ch>='a'&&ch<='z'||ch>='A'&&ch<='Z')return 1;
    return 0;
}
typedef node* GList;
Status CreateGList(GList &L,string s); // 根据字符串 s 表示的广义表内容建立广义表数据结构
GList GetHead(GList L);   // 取表头运算
GList GetTail(GList L);   // 取表尾运算
void DestroyGList(GList &L);  // 销毁广义表L
void PrintGList(GList L);    // 打印广义表的内容
int main(void)
{
    string s;
    cin>>s;
    GList L;
    CreateGList(L,s);   // 创建一个广义表
    cout<<"generic list: ";
    PrintGList(L);
    cout<<'\n';
    //  主循环
    int flag;
    while(cin>>flag)
    {
        if(flag==1){ // 取表头
            cout<<"destroy tail"<<'\n';
            cout<<"free list node"<<'\n';
            L = GetHead(L);
            if(L==NULL)break;
            cout<<"generic list: ";
            PrintGList(L);
            cout<<'\n';
        }
        else if(flag==2){ // 取表尾
            cout<<"free head node"<<'\n';
            cout<<"free list node"<<'\n';
            L = GetTail(L);
            cout<<"generic list: ";
            PrintGList(L);
            cout<<'\n';
        }
    }
    return 0;
}
Status CreateGList(GList &L,string s)
{
    int l = (int)s.length();
    L = new node();
    node* cur;
    cur = L;
    for(int i=1;i<l-1;++i)   // 去掉首尾括号
    {
        char ch=s[i];
        if(isalpha(ch)){
            cur->tp = new node();
            cur->tp->isAtom = 1;
            cur->tp->ptr.atom = ch;
            cur->tp->tp = NULL; 
        }
        else if(ch==','){
            cur = cur->tp;
        }
        else if(ch=='('){
            int sublen = 1;
            while(s[i+sublen-1]!=')')sublen++;
            cur->tp = new node();
            cur->tp->isAtom = 0;
            CreateGList(cur->tp->ptr.hp,s.substr(i,sublen));
            i = i+sublen-1;
        }
    }
    L = L->tp;
    return SUCCESS;
}
GList GetHead(GList L)
{
    if(L==NULL)
    {
        cout<<"failed to gethead"<<'\n';
        return L;
    }
    else if(L->isAtom){
        cout<<"generic list: "<<L->ptr.atom<<'\n';  // 特判
        return NULL;
    }
    GList newL;
    newL = L->ptr.hp;
    L = L->tp;
    DestroyGList(L);
    return newL;
}
GList GetTail(GList L)
{
    if(L==NULL){
        cout<<"failed to gettail"<<'\n';
    }
    GList newL = L->tp;
    L->tp = NULL;
    DestroyGList(L);
    return newL;
}
void DestroyGList(GList &L)
{
    while(L!=NULL)
    {
        node* tmp = L;
        L = L->tp;
        if(tmp->isAtom){
            delete tmp;
        }
        else {
            DestroyGList(tmp->ptr.hp);
        }
    }
}
void PrintGList(GList L)
{
    if(L==NULL){
        cout<<"()";
        return;
    }
    cout<<'(';
    if(L->isAtom){
        cout<<L->ptr.atom;
    }
    else {
        PrintGList(L->ptr.hp);
    }
    L = L->tp;
    while(L!=NULL)
    {
        if(L->isAtom){
            cout<<','<<L->ptr.atom;
        }
        else{
            cout<<',';
            PrintGList(L->ptr.hp);
        }
        L = L->tp;
    }
    cout<<')';
    return;
}

// 采用数组风格建立树，  就当算法题写了， 链表实现之后再补wwwww //
// 这个写的还不错，可以当模板了 //
// 命名为 "树的顺序表表示" //
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    vector<int> sons;   // 在顺序表中，整数就是指针
};
struct Tree{
    node tnode[10005];  // 0 不用，从 1 开始计数
    int tot;    // 当前的大小
    int root = 0;    // 记录根节点, root 为 0 表示空树
    map<int, int> _m;   // 用于记录预处理出的括号对应关系

    void _createTree(char s[], int left, int right, int fa)  // 为了能够递归建树，使用辅助函数
    {
        if(right==left+1)return;  // 空树
        int now = ++tot;   // 记录一下当前创建的节点
        tnode[now].data = s[left+1];
        tnode[fa].sons.push_back(now);
        for(int i=left+2;i<=right-1;){   // 不管两边的括号
            if(s[i]==','){
                i++;
            }
            else if(s[i]=='('){
                int nxt = _m[i];
                _createTree(s, i, nxt, now);
                i=nxt+1;
            }
        }
    }
    Tree(char s[], int l)   // 构造方法, 接受一个广义表形式的字符串 s 以及他的长度 l
    {   
        tot = 0;
        if(l==2)return;     // 空树
        root = 1;
        // 预处理一下字符串，得到括号的对应下标 , 存在 _m 里面
        stack<int> stk;
        for(int i=0;i<=l-1;i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else if(s[i]==')'){
                _m[stk.top()] = i; 
                stk.pop();
            }
        }
        // 调用可以递归的创建函数
        _createTree(s, 0, l-1, 0);
    }
    void printDegreeOfTreeAndNodes()    // 树的度就是所有节点的度的最大值
    {
        map<int, int> m;
        int ma = 0;
        for(int i=1;i<=this->tot;++i){
            int deg = tnode[i].sons.size();
            ma = max(ma, deg);
            if(!m.count(deg))m[deg] = 1;
            else m[deg]++;
        }

        printf("Degree of tree: %d\n", ma);
        for(int deg=0; deg<=ma; ++deg){
            int num;
            if(m.count(deg))num=m[deg];
            else num=0;
            printf("Number of nodes of degree %d: %d\n", deg, num);
        }
        return;
    }
    void _printASConcave(int rt, int depth)    // 辅助函数，为了可以递归调用    // todo 用栈重写函数的递归调用
    {
        for(int i=0;i<4*depth;i++){
            putchar(' ');
        }
        putchar(tnode[rt].data);
        putchar('\n');
        for(auto son: tnode[rt].sons){
            _printASConcave(son, depth+1);
        }
        return;
    }
    void printAsConcave()   // 打印层次结构，但不是按层输出 有区别！！
    {
        if(this->root)_printASConcave(this->root, 0);
        return;   
    }
    void info()   // 打印树的大致信息
    {
        printAsConcave();
        printDegreeOfTreeAndNodes();
        return;
    }
};
char s[10005];
int main(void)
{
    cin>>s;
    Tree T = Tree(s, strlen(s));
    T.info();
    return 0;
}

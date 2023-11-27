// 决策很好想，结果又变成的大模拟题，实属难绷 //
// 这博弈树看似需要二染色，实际上就是简单的树形 DP 即可解决，每个节点都是相对独立的 //
// 思维不难，在算法设计上并没有难度，采取模块化设计（本题还小小的封装了一下），以此来解决这种大模拟题 //
#include<bits/stdc++.h>
using namespace std;
struct node{
    char data;
    int height;
    int win = -1;   // 是否选择到达该节点就能赢,-1是未更新状态
    vector<int> sons;   // 在顺序表中，整数就是指针
};
struct Tree{
    node tnode[10005];  // 0 不用，从 1 开始计数
    int tot;    // 当前的大小
    int root = 0;    // 记录根节点, root 为 0 表示空树
    map<int, int> _m;   // 用于记录预处理出的括号对应关系 , 在创建树的时候使用
    map<char, int> _mm;   // 用于用data查节点，要是早点看懂题目也就不需要它了

    void _createTree(char s[], int left, int right, int fa)  // 为了能够递归建树，使用辅助函数
    {
        if(right==left+1)return;  // 空树
        int now = ++tot;   // 记录一下当前创建的节点
        tnode[now].data = s[left+1];
        _mm[s[left+1]] = now;
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
        // 建树完成后，预处理一下
        InitHeight();
        InitWinNode();
    }
    void _InOrder(int rt)
    {
        printf("%c\n",tnode[rt].data);
        for(auto son:tnode[rt].sons){
            _InOrder(son);
        }
    }
    void InOrder()
    {
        _InOrder(this->root);
        return;
    }
    void InitHeight()   // 建树完成后，预处理树的节点高度
    {   
        _Dfs(root);
        return;
    }   
    int _Dfs(int now){   // 辅助函数，方便递归调用，使用记忆化搜索
        if(tnode[now].height)return tnode[now].height;
        if(isLeaf(now))return 0;
        int res = 0;
        for(auto son: tnode[now].sons){
            res = max(res, _Dfs(son)+1);
        }
        return tnode[now].height = res;
    }
    void InitWinNode()   // 建树完成后，预处理出所有后手就能win的节点
    {
        _Dfs2(root);
        return;
    }
    int _Dfs2(int now){  // 辅助函数，记忆化搜索，方便递归调用
        if(tnode[now].win!=-1) return tnode[now].win;
        if(isLeaf(now))return tnode[now].win = 1;
        int win=1;
        for(auto son: tnode[now].sons){
            win&= _Dfs2(son)^1;
        }
        return tnode[now].win = win;
    }
    // 为实现游戏的功能函数
    bool isLeaf(int x){
        if(!tnode[x].sons.size())return 1;
        return 0;
    }
    bool isLegalMove(int now, char nxt){
        for(auto son: tnode[now].sons){
            if(nxt == tnode[son].data)return 1;
        }
        return 0;
    }
    int getIndexByData(char ch){
        if(!_mm.count(ch))return -1;  // 没有找到
        return _mm[ch];
    }
    char getDataByIndex(int idx){
        if(idx<=0 || idx>tot)return '0';
        return tnode[idx].data;
    }
    int makeDecision(int now)    // 决策函数，只需要当前当前的信息即可，与之前的操作无关，这个博弈还蛮好懂的
    {
        // 如果有必胜策略，有多个，选高度最小的那个; 如果还有多个，选靠左的那个
        int winwinwin = -1;
        for(int i=0;i<tnode[now].sons.size();++i){
            int son = tnode[now].sons[i];
            if(tnode[son].win==1){   // 懒得改了
                if(winwinwin==-1)winwinwin=son;
                else if(tnode[son].height<tnode[winwinwin].height)winwinwin=son;
            }
        }
        if(winwinwin!=-1)return winwinwin;
        // 没有必胜策略，那么选择一个高度最大的孩子节点作为下一步; 如果有多个选择，选左边的
        int d_son = 0;
        for(int i=1;i<tnode[now].sons.size();++i){
            int son = tnode[now].sons[i];
            if(tnode[son].height>tnode[d_son].height)d_son = son;
        }
        return d_son;
    }
};
char s[10005];
int main(void)
{
    cin>>s;
    Tree T = Tree(s, strlen(s));
    T.InOrder();
    char isContinue;
    int whoIsFirst; 
    // mainloop
    do{
        printf("Who play first(0: computer; 1: player )?\n");
        cin >> whoIsFirst;
        int whoIsCur = whoIsFirst;
        int nowPlace = T.root;

        while(1){   // 一局游戏的循环，分出胜负后退出循环
            if(T.isLeaf(nowPlace)){   // 胜负以分
                if(whoIsCur){
                    printf("Sorry, you lost.\n");
                    break;
                }
                else {
                    printf("Congratulate, you win.\n");
                    break;
                }
            }
            
            if(whoIsCur){
                while(1){
                    printf("player:\n");
                    char nxt;
                    cin >> nxt;
                    if(T.isLegalMove(nowPlace, nxt)){
                        nowPlace = T.getIndexByData(nxt);
                        break;
                    }
                    printf("illegal move.\n");
                }
            }
            else{
                int nxtPlace = T.makeDecision(nowPlace);
                printf("computer: %c\n",T.getDataByIndex(nxtPlace));
                nowPlace = nxtPlace;
            }

            whoIsCur^=1;   // 更新
        }   

        printf("Continue(y/n)?\n");
        cin >> isContinue;
    }while(isContinue=='y');
    // mainloop end
    return 0;
}

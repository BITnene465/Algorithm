/*
1. 一旦有 ) 直接下放所有运算符号，无论后面符号的优先级
2. 如果cur的优先级<top的优先级，那么将top弹出，直到不能再弹出时再将cur加入;否则直接将cur加入
3. 运算符号先进后出（栈）
^^^ 4. 注意乘方符号的结合性：从右到左 ！！！
*/
#include<bits/stdc++.h>
using namespace std;
int n;
string input_expression,output_expression;
string InToSuffix(string inex)
{
    stack<pair<char,int>> stk;
    string sufex;
    for(auto ch: inex){
        if(ch=='('){
            stk.push(make_pair('(',0));     // 应当为最低的优先级x   upd: 需要特判该符号，入队时不弹出任何符号，当且仅当右括号可以使其出队
        }
        else if(ch=='+'||ch=='-'){
            int pri=1;
            while(!stk.empty()&&stk.top().second>=pri){sufex.push_back(stk.top().first);stk.pop();}
            stk.push(make_pair(ch,pri));
        }
        else if(ch=='*'||ch=='/'){
            int pri=2;
            while(!stk.empty()&&stk.top().second>=pri){sufex.push_back(stk.top().first);stk.pop();}
            stk.push(make_pair(ch,pri));
        }
        else if(ch=='^'){
            int pri=3;
            while(!stk.empty()&&stk.top().second>pri){sufex.push_back(stk.top().first);stk.pop();}   //乘方的结合率不同，要特殊处理
            stk.push(make_pair(ch,pri));
        }
        else if(ch==')'){
            while(!stk.empty()&&stk.top().first!='('){sufex.push_back(stk.top().first);stk.pop();}
            stk.pop();  // 弹出 '('
        }
        else if(ch=='#'){
            break;   // 退出循环
        }
        else if(('a'<=ch && 'z'>=ch)||('A'<=ch && 'Z'>=ch)){
            sufex.push_back(ch);    // 添加字符要用此方法
        }
        // cout<<sufex<<endl;
    }
    // 清空栈
    while(!stk.empty()){sufex.push_back(stk.top().first);stk.pop();}
    return sufex;
}
int main(void){
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>input_expression;
        // cout<<input_expression;
        output_expression = InToSuffix(input_expression);
        cout<<output_expression<<endl;
    
    }
    return 0;
}
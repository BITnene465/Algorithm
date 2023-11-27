// 沿用上一题的接口函数，并且稍加改动，将数值用"#value#"包围起来 //
// 本题代码的基础上，预处理输入的中缀表达式（去掉空格和无用字符，使得表达式符合规范）,则可以处理更加一般的计算式,可以写个小程序，并且加上图像界面 //
#include<bits/stdc++.h>
using namespace std;
string input_expression,output_expression;
string InToSuffix(string inex)
{
    stack<pair<char,int>> opt_stk;
    string sufex;
    int l = (int)inex.length();
    for(int i=0;i<l;++i){
        char ch = inex[i];
        if(ch=='('){
            opt_stk.push(make_pair('(',0));     // 应当为最低的优先级
        }
        else if(ch=='+'||ch=='-'){   // 需要特判一下负数和正数
            // start
            if(i==0||((inex[i-1]>'9'||inex[i-1]<'0')&&(inex[i+1]<='9'&&inex[i+1]>='0')))
            {
                sufex.push_back('#');
                sufex.push_back(ch);
                ch = inex[++i];
                while(ch>='0'&&ch<='9'){
                    sufex.push_back(ch);
                    ch = inex[++i];
                }
                i--;
                sufex.push_back('#');
                continue;
            }
            // end
            int pri=1;
            while(!opt_stk.empty()&&opt_stk.top().second>=pri){sufex.push_back(opt_stk.top().first);opt_stk.pop();}
            opt_stk.push(make_pair(ch,pri));
        }
        else if(ch=='*'||ch=='/'||ch=='%'){
            int pri=2;
            while(!opt_stk.empty()&&opt_stk.top().second>=pri){sufex.push_back(opt_stk.top().first);opt_stk.pop();}
            opt_stk.push(make_pair(ch,pri));
        }
        else if(ch=='^'){
            int pri=3;
            while(!opt_stk.empty()&&opt_stk.top().second>pri){sufex.push_back(opt_stk.top().first);opt_stk.pop();}   // 乘方的结合率不同，要特殊处理
            opt_stk.push(make_pair(ch,pri));
        }
        else if(ch==')'){
            while(!opt_stk.empty()&&opt_stk.top().first!='('){sufex.push_back(opt_stk.top().first);opt_stk.pop();}
            opt_stk.pop();  // 弹出 '('
        }
        else {  // 添加整数，以'#'开头和结尾
            sufex.push_back('#');
            while(ch>='0'&&ch<='9'){
                sufex.push_back(ch);
                ch = inex[++i];
            }
            i--;
            sufex.push_back('#');
        }
        // cout<<sufex<<endl;
    }
    // 清空栈
    while(!opt_stk.empty()){sufex.push_back(opt_stk.top().first);opt_stk.pop();}
    return sufex;
}
void calc(string sufex)
{
    int l = (int)sufex.length();
    stack<int> num_stk;
    for(int i=0;i<l;++i)
    {
        char ch = sufex[i];
        if(ch=='#')    // 读取整数
        {
            ch=sufex[++i];
            int x=0,f=1;
            if(ch=='-')
            {
                f=-1;
                ch=sufex[++i];
            }
            while(ch>='0'&&ch<='9')
            {
                x=x*10+ch-'0';
                ch = sufex[++i];
            }
            num_stk.push(f*x);
        }
        else if(ch=='+')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()+num1;
        }
        else if(ch=='-')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()-num1;
        }
        else if(ch=='*')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()*num1;
        }
        else if(ch=='/')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            if(num1==0){cout<<"Divide 0."<<'\n';return;}
            num_stk.pop();
            num_stk.top() = num_stk.top()/num1;
        }
        else if(ch=='%')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            if(num1==0){cout<<"Divide 0."<<'\n';return;}
            num_stk.pop();
            num_stk.top() = num_stk.top()%num1;
        }
        else if(ch=='^')
        {
            if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            if(num1<0){cout<<"error."<<'\n';return;}     // 乘方的特判，题目的要求
            num_stk.pop();
            num_stk.top() = (int)pow(num_stk.top(),num1);
        }
    }
    // output ans
    if(num_stk.size()>1){cout<<"error."<<'\n';return;}
    else{
        cout<<num_stk.top()<<endl;
        num_stk.pop();
        return;
    }      
}
bool check(string input)
{
    int l = (int)input.length();
    int left=0;
    for(int i=0;i<l;++i)
    {
        if(input[i]=='('){left++;}
        else if(input[i]==')'){if(--left<0)return 0;}
    }
    if(left==0)return 1;
    return 0;
}
int main(void){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>input_expression;
        // cout<<input_expression;
        if(check(input_expression)){   // 只检查括号是否合理
            output_expression = InToSuffix(input_expression);
            // cout<<output_expression<<endl;
            calc(output_expression);
        }
        else cout<<"error."<<'\n';
    }
    return 0;
}
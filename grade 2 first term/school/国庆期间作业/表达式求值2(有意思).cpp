/*
1. 假定表达式都正确
2. 赋值语句都是 var=expression 的形式
3. 我们用map存变量名和值的对应关系，用上题的函数接口来计算表达式的值（变量名中不会有'#',所以我们仍然可以使用'#'）
4. 
*/
#include<bits/stdc++.h>
using namespace std;
map<string,int> vars;
stack<int> num_stk;
stack<pair<char,int>> opt_stk;
string input_expression,output_expression;
bool isvar_char(char ch)
{
    if((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z')) return 1;
    return 0;
}
bool isopt(char ch)
{
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^'||ch=='%'||ch=='(')return 1;
    return 0;
}
string InToSuffix(string inex)
{
    // 清空
    while(!opt_stk.empty())opt_stk.pop();
    //
    string sufex;
    int l = (int)inex.length();
    for(int i=0;i<l;++i){
        char ch = inex[i];
        if(ch=='('){
            opt_stk.push(make_pair('(',0));     // 应当为最低的优先级
        }
        else if(ch=='+'||ch=='-'){   // 需要特判一下负数和正数
            // start
            if(i==0||(isopt(inex[i-1])&&(isvar_char(inex[i+1]))))
            {
                sufex.push_back('#');
                sufex.push_back(ch);
                ch = inex[++i];
                while(isvar_char(ch)){
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
        else {  // 添加整数或变量，以'#'开头和结尾
            sufex.push_back('#');
            while(isvar_char(ch)){
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
int calc(string sufex)
{
    // 清空栈
    while(!num_stk.empty())num_stk.pop();
    //
    int l = (int)sufex.length();
    for(int i=0;i<l;++i)
    {
        char ch = sufex[i];
        if(ch=='#')    // 读取整数或变量（变量会转换成整数）
        {
            ch=sufex[++i];
            int x=0,f=1;
            if(ch=='-')
            {
                f=-1;
                ch=sufex[++i];
            }
            if(ch>='0'&&ch<='9'){   // 是数值
                while(ch>='0'&&ch<='9')
                {
                    x=x*10+ch-'0';
                    ch = sufex[++i];
                }
                num_stk.push(f*x);
            }
            else { // 是变量
                int tmp_l=0;
                while(sufex[i+tmp_l]!='#')tmp_l++;
                x = vars[sufex.substr(i,tmp_l)];
                // cout<<sufex.substr(i,tmp_l)<<endl;
                i = i+tmp_l;
                num_stk.push(f*x);
            }
        }
        else if(ch=='+')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()+num1;
        }
        else if(ch=='-')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()-num1;
        }
        else if(ch=='*')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            num_stk.pop();
            num_stk.top() = num_stk.top()*num1;
        }
        else if(ch=='/')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            // if(num1==0){cout<<"Divide 0."<<'\n';return;}
            num_stk.pop();
            num_stk.top() = num_stk.top()/num1;
        }
        else if(ch=='%')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            // if(num1==0){cout<<"Divide 0."<<'\n';return;}
            num_stk.pop();
            num_stk.top() = num_stk.top()%num1;
        }
        else if(ch=='^')
        {
            // if(num_stk.size()<2){cout<<"error."<<'\n';return;}
            int num1=num_stk.top();
            // if(num1<0){cout<<"error."<<'\n';return;}     // 乘方的特判，题目的要求
            num_stk.pop();
            num_stk.top() = (int)pow(num_stk.top(),num1);
        }
    }
    // output ans (已经假定表达式合法了)
    return num_stk.top(); 
}
int main(void){
    while(1)
    {
        getline(cin,input_expression);    // 获取一行，会自动删除换行符
        if(input_expression=="end"){break;}  // 保留关键词，结束语句
        if(isvar_char(input_expression[0])){  // 开头是字母或数字，说明是赋值语句
            int idx=0;
            while(input_expression[idx]!='=')idx++;
            string varname = input_expression.substr(0,idx);
            output_expression = InToSuffix(input_expression.substr(idx+1,input_expression.length()-idx-1));   // 第二个参数是长度
            int ans = calc(output_expression);
            vars[varname]=ans;   // 更新变量的值

            // 此处可以用于调试
            // cout<<"varname:"<<varname<<endl;
            // cout<<"input_exp:"<<input_expression.substr(idx+1,input_expression.length()-idx-1)<<endl;
            // cout<<"suffix_exp:"<<output_expression<<endl;  
            // cout<<"update_value:"<<ans<<endl;
        }
        else if(input_expression[0]=='?'){   // 开头是问号，是求值语句
            string varname = input_expression.substr(2,input_expression.length()-2);
            cout<<varname<<'='<<vars[varname]<<'\n';
        }
    }
    return 0;
}
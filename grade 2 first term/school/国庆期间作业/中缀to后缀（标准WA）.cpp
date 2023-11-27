// 未考虑乘方运算的结合性 //
#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n = 0;
	scanf("%d",&n);

	stack<pair<char,int>> opt;
	stack<char> exp;

	while(n--)
	{
		while(!opt.empty())opt.pop();
		while(!exp.empty())exp.pop();
		char str[110];
		scanf("%s",str);
		char ch;	//用一个ch来表示str[i]
		int len = strlen(str);
		for(int i = 0; i < len; i++)
		{
			ch = str[i];
			if(ch == '#')	//扫描完毕则退出
				break;
			//操作数直接压栈
			if((ch >= 'a'&& ch <= 'z') || (ch >= 'A'&& ch <= 'Z') || (ch >= '0'&& ch <= '9'))
				exp.push(ch);
			else	//判断括号
			{
				if(ch == '(')//左括号直接压栈
					opt.push(make_pair(ch,0));
				else if(ch == ')')//右括号则取opt中对应的操作符存入exp中
				{
					while(opt.top().first!='(')
					{
						exp.push(opt.top().first);
						opt.pop();
					}
					opt.pop();//舍弃栈顶的左括号
				}
				else	//判断运算符
				{
					int pri;
					switch(ch){
						case '+':
						case '-':
						pri=1;break;
						case '*':
						case '/':
						pri=2;break;
						case '^':
						pri=3;break;
					}
					if(opt.empty() || pri>opt.top().second)//优先级大直接存入
					{
						opt.push(make_pair(ch,pri));
					}
					else	//优先级小，栈顶元素出栈
					{
						exp.push(opt.top().first);
						opt.pop();
						while(!opt.empty())//继续出栈
						{
							if(pri<=opt.top().second)
							{
								exp.push(opt.top().first);
								opt.pop();
							}
							else
								break;
						}
						opt.push(make_pair(ch,pri));//最后ch存入opt
					}
				}
			}

		}
		//将opt剩余运算符存入exp中
		while(!opt.empty())
		{
			exp.push(opt.top().first);
			opt.pop();
		}
		//取出exp的后缀表达式，逆序输出
		int num = 1;
		while(!exp.empty())
		{
			str[num++]=exp.top();
			exp.pop();
		}
		for(int i = num - 1; i > 0; i--)
		{
			printf("%c", str[i]);
		}
		printf("\n");
	}
	return 0;
}

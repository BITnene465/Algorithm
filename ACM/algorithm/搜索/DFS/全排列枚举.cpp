//  DFS's  application ; time complex: O(n!)//
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
using namespace std;
vector<int> ans;
int vis[12]={0};
int cou = 0;
int n;  // 这个变量需要全局使用
void show(){
    for(int i =0;i<ans.size();i++)
    {
        printf("%3d",ans[i]);
    }putchar('\n');
    return;
}

void dfs(int num)
{
    if(num==n+1)
    {
        show();
        ++cou;
        return;
    }
    else
    {
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])     // 可以到达
            {
                ans.push_back(i);  // 加入
                vis[i] = 1;   // 记录
                dfs(num+1);
                ans.pop_back();  // 删除最后一个元素 ，状态返回
                vis[i] = 0;
            }
        }
    }
}
int main(void)
{ 
    cin>>n;
    dfs(1);
    cout<<"共有："<<cou<<endl;
    return 0;
}
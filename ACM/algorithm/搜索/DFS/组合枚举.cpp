// 1~n 中所有k元子集 //
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
int n,k;
vector<int> ans;    //当链表使用
int vis[100]={0};
int cou = 0;
void show(){
    for(int i =0;i<ans.size();i++)
    {
        printf("%3d",ans[i]);
    }putchar('\n');
    return;
}

void dfs(int d)
{
    if(ans.size()==k)   //终止条件1,找到了可行解，展示并回溯
    {
        cou++;
        show();
        return;
    }
    else if(d==n+1)   //终止条件2,该路径下无可行解,直接回溯
    {
        return;
    }
    else{
        // 1
        ans.push_back(d);
        dfs(d+1);
        ans.pop_back();
        // 2
        dfs(d+1);
    }
}

int main(void)
{ 
    scanf("%d %d",&n,&k);
    dfs(1);
    cout<<"共有："<<cou<<"个"<<endl;
    return 0;
}
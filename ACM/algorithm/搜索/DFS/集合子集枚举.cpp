#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
vector<int> sets;
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
void get_set(){
    int t;
    cin>>t;
    while(t)
    {
        sets.push_back(t);
        cin>>t;
    }
    return;
}

void dfs(int n)
{
    if(n==sets.size()+1)
    {
        show();
        cou++;
        return;
    }
    else
    {
        for(int i=n-1;i<sets.size();i++)     // 注意：为了不重复搜索，此处为 n-1 ,共有2^n  ;  若改n-1为0 则为有序集合版本，共有2^n*n!
        {
            if(!vis[i])
            {
                //  有两种情况：选取sets[i] 和 不选取sets[i]  //
                //  situation 1 //
                ans.push_back(sets[i]);
                vis[i] = 1;
                dfs(n+1);
                ans.pop_back();
                vis[i] = 0;
                //  situation 2 //
                vis[i] = 1;
                dfs(n+1);
                vis[i] = 0;
            }
        }
    }
}

// 以上dfs的改进版
void dfs2(int n)
{
    if(n==sets.size()+1)
    {
        show();
        ++cou;
        return;
    }
    else
    {
        // 1
        ans.push_back(sets[n-1]);
        dfs(n+1);
        ans.pop_back();
        // 2
        dfs(n+1);
    }
}

int main(void)
{ 
    cout<<"输入一个集合,空格隔开，0为结束符"<<endl;
    get_set();
    for(int i=0;i<sets.size();i++)
        printf("%d ",sets[i]);
    cout<<"子集有:"<<endl;
    dfs2(1);
    cout<<"共有："<<cou<<endl;
    return 0;
}
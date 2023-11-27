// 题目已知弱联通，可以不判断此项 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100100
vector<int> G[MAXN];
int n,m,del[MAXN];  // del[now]表示now节点中，边(G[now][0],...,G[now][del[now]-1]都已经走过)，相当于实现了边的vis数组,初始化全为0 //
int indeg[MAXN],outdeg[MAXN],cnt1,cnt2;
int stk[MAXN],top;   // 实现手工栈
int s;     // 记录起点
void Dfs(int now)
{
    for(int i=del[now];i<G[now].size();i=del[now])
    {
        del[now]=i+1;
        Dfs(G[now][i]);
    }
    stk[++top]=now;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=m;++i)
    {
        int u,v;
        cin>>u>>v;
        G[u].push_back(v);
        indeg[v]++;outdeg[u]++;
    }
    // sort,保证字典序最小
    for(int i=1;i<=n;++i)sort(G[i].begin(),G[i].end());
    // 统计
    s=1;bool flag=1;
    for(int i=1;i<=n;++i)
    {
        if(indeg[i]==outdeg[i])continue;
        flag=0;
        if(indeg[i]-outdeg[i]==1){cnt1++;}
        else if(outdeg[i]-indeg[i]==1){cnt2++;s=i;}
        else{cout<<"No"<<endl;return 0;}
    }
    // 判断是否存在
    if(!(cnt1==cnt2&&cnt1==1)&&(!flag)){cout<<"No"<<endl;return 0;}
    // 找欧拉路或欧拉回路
    Dfs(s);
    while(top)cout<<stk[top--]<<" ";
    cout<<endl;
    return 0;
}
// 题目已知弱联通，可以不判断此项 //
// 四个WA , 不解//
#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define MAXM 200010
typedef pair<int,int> pii;
vector<pii> G[MAXN];
bool vis[MAXM];   // 实现边的vis数组,以G中pair的第二个元素对应id
int n,m;
int indeg[MAXN],outdeg[MAXN],cnt1,cnt2,del[MAXN];
int stk[MAXN],top;   // 实现手工栈
int s;     // 记录起点
void Dfs(int now)
{
    for(int i=del[now];i<G[now].size();i=max(del[now],i+1))     // 但是这样写会浪费大量时间，所以还是得要一个del数组
    {
        if(vis[G[now][i].second])continue;
        vis[G[now][i].second]=1;
        del[now]=i+1;
        Dfs(G[now][i].first);
    }
    stk[++top]=now;
}
int main(void)
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        G[u].push_back(make_pair(v,i));
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
        else{printf("No\n");return 0;}
    }
    // 判断是否存在
    if(!(cnt1==cnt2&&cnt1==1)&&(!flag)){printf("No\n");return 0;}
    // 找欧拉路或欧拉回路
    Dfs(s);
    while(top)printf("%d%c",stk[top--],top==0?'\n':' ');
    return 0;
}
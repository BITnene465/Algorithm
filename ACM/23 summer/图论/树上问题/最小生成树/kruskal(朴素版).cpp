// kruskal最小生成树算法 贪心策略：每次加入当前未加入且不会和当前树形成环的最小边 //
// 可以用归纳法证明当前贪心策略可以得到全局最优 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
const int maxm=1e7+5;
int n,m;
struct edge{
    int u,v;
    int w;
}e[maxm];
bool cmp_ed(edge a,edge b)
{
    return a.w<b.w;
}
int s[maxn];  // 实现并查集
int find_set(int x)   // 找x所属的集合
{
    int r = x;
    while(r!=s[r]) r=s[r];  // 先找到根节点
    int t;
    while(x!=r)   // 将这条链上的元素全部连到根节点
    {
        t = s[x];
        s[x] = s[r];
        x = t;
    }
    return s[r];  
}
void union_set(int x,int y)
{
    x=find_set(x);y=find_set(y);
    s[x]=s[y];return;
}
vector<int> edans;  // 记录取的边
int ans;
bool kruskal()
{
    int cnt=0;
    for(int i=1;i<=m&&cnt<n-1;i++)
    {
        int x=find_set(e[i].u),y=find_set(e[i].v);
        if(x==y)    continue;   // 表示u,v在未添加这条边之前就已经连通了 
        ans+=e[i].w;
        edans.push_back(i);
        union_set(x,y);
        cnt++;
    }
    if(cnt==n-1)    return true;
    else            return false;
}
void print_ans()
{
    printf("ans=%d\n",ans);
    for(auto id:edans)
        printf("(%d,%d) 权值=%d\n",e[id].u,e[id].v,e[id].w);
    return;
}
int main(void)
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
        cin>>e[i].u>>e[i].v>>e[i].w;
    sort(e+1,e+1+m,cmp_ed);
    ans=0;
    edans.clear();
    for(int i=1;i<=n;i++)
        s[i]=i;
    if(kruskal())   print_ans();
    else            printf("图不联通,无生成树\n");
    return 0;
}

/*
input:
7 11
1 2 7
1 4 5
2 3 8
2 4 9
2 5 7
3 5 5
4 6 6
4 5 15
5 6 8
5 7 9
6 7 11
*/

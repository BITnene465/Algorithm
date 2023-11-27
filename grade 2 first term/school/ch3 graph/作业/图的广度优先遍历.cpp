#include<bits/stdc++.h>
using namespace std;
char val[10005];
int n,m;
vector<int> g[10005];
bool vis[10005];
void bfs(int s){
    queue<int> q;
    q.push(s);
    vis[s] = 1;
    printf("%c",val[s]);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(auto v:g[u]){
            if(!vis[v])q.push(v),vis[v]=1,printf("%c",val[v]);
        }
    }
}
int main(void)
{
    n = 0;
    while(1){
        char ch;
        ch = getchar();
        getchar();
        if(ch=='*')break;
        val[n++] = ch;
    }
    while(1){
        int u,v;
        scanf("%d,%d",&u,&v);
        if(u==-1&&v==-1)break;
        g[u].insert(g[u].begin(),v);
        g[v].insert(g[v].begin(),u);
    }
    printf("the ALGraph is\n");
    for(int i=0;i<n;++i){
        printf("%c",val[i]);
        for(int j=0;j<g[i].size();++j){
            printf(" %d",g[i][j]);
        }
        printf("\n");
    }
    printf("the Breadth-First-Seacrh list:");
    for(int i=0;i<n;++i){
        if(!vis[i])bfs(i);
    }
    printf("\n");
    return 0;
}
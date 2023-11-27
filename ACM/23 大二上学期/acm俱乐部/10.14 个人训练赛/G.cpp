#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 5;
struct node{
    int in;
    int out;
}g1[maxn],g2[maxn];
int n;
bool mycmp(node x, node y)
{
    if(x.in == y.in) return x.out > y.out;   // 出度为第二优先级
    return x.in > y.in; 
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g1[u].out++;
        g1[v].in++;
    }
    for(int i=1;i<=n;++i)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        g2[u].out++;
        g2[v].in++;
    }
    // sort
    sort(g1+1, g1+1+n, mycmp);
    sort(g2+1, g2+1+n, mycmp);
    for(int i=1;i<=n;++i){
        if(g1[i].in != g2[i].in || g2[i].in != g2[i].in){printf("No\n");return 0;}
    }
    printf("Yes\n");
    return 0;
}
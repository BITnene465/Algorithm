// 最小生成树算法即可 //
#include<bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
int n,m;
int s;
namespace FLOYD
{
    int dis[1005][1005];
    queue<int> q;
    bool inque[1005];
    void init(int n){
        memset(dis, 0x3f, sizeof(dis));
        for(int i=1;i<=n;++i)dis[i][i] = 0;
        return;
    }
    void floyd(int n)
    {
        // 循环顺序不能乱 // 
        for(int k=1;k<=n;++k)
            for(int i=1;i<=n;++i)
                for(int j=1;j<=n;++j)   
                    dis[i][j] = min(dis[i][k]+dis[k][j], dis[i][j]);
    }
} // namespace FLOYD
int main(void){
    using namespace FLOYD;
    char cs;
    scanf("%d,%d,%c",&n, &m, &cs);
    s = cs-'a'+1;
    init(n);
    for(int i=1;i<=m;++i){
        getchar();
        int u,v,w;
        char cu,cv;
        scanf("<%c,%c,%d>",&cu,&cv,&w);
        u = cu-'a'+1;
        v = cv-'a'+1;
        dis[u][v] = min(dis[u][v], w);
    }
    floyd(n);
    for(int i=1;i<=n;++i){
        printf("%c:%d\n",i+'a'-1, dis[s][i]);
    }
    return 0;
}
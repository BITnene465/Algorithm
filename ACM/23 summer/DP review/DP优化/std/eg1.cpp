
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=14;
#define LL long long
const LL inf=1e15;
int n,m;
bool vis[600000][N];
LL f[600000][N],g[N][N];
void dp(int S,int depth){
    if(depth<=0)return;
    int i,j,k;if(vis[S][depth])return;
    f[S][depth]=inf;vis[S][depth]=1;
    for(i=S;i;i=(i-1)&S)if(i!=S && depth>1){
        dp(i,depth-1);
        int tmp=S-i;LL sum=0;
        rep(j,1,n)if((1<<j-1)&tmp){
            LL mn=inf;
            rep(k,1,n)if((1<<k-1)&i)mn=min(mn,(LL)g[j][k]);
            sum+=(LL)(depth-1)*mn;
        }
        f[S][depth]=min(f[S][depth],sum+f[i][depth-1]);
    }
}
int main(){//freopen("in.txt","r",stdin);
    int i,j;scanf("%d%d",&n,&m);
    rep(i,1,n)rep(j,1,n)if(i!=j)g[i][j]=inf;
    rep(i,0,(1<<n)-1)rep(j,0,n)f[i][j]=inf;
    rep(i,1,m){
        int x,y,w;scanf("%d%d%d",&x,&y,&w);
        g[x][y]=min(g[x][y],(LL)w);g[y][x]=min(g[y][x],(LL)w);
    }
    rep(i,1,n)vis[(1<<i-1)][1]=1,f[(1<<i-1)][1]=0;
    dp(11,2);
    rep(i,1,n)
        dp((1<<n)-1,i);
    LL ans=inf;
    rep(i,1,n)
        ans=min(ans,f[(1<<n)-1][i]);
    printf("%lld",ans);
}
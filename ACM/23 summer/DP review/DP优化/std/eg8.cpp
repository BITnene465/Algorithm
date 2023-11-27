
#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=2e4+10;
const int M=110;
#define LL long long
const LL inf=1e15;
int n,k;
LL d[N],s[N],cst[N],w[N],seg[N<<2],tag[N<<2];
void pushup(int rt){
    seg[rt]=min(seg[rt<<1],seg[rt<<1|1]);
}
void pushdown(int rt){
    if(tag[rt]){
        seg[rt<<1]+=tag[rt];
        seg[rt<<1|1]+=tag[rt];
        tag[rt<<1]+=tag[rt];
        tag[rt<<1|1]+=tag[rt];tag[rt]=0;
    }
}
void mdy(int rt,int l,int r,int ql,int qr,LL d){
    if(ql<=l && r<=qr){
        seg[rt]+=d;tag[rt]+=d;return;
    }
    int mid=l+r>>1;pushdown(rt);
    if(mid>=ql)mdy(rt<<1,l,mid,ql,qr,d);
    if(mid+1<=qr)mdy(rt<<1|1,mid+1,r,ql,qr,d);
    pushup(rt);
}
LL query(int rt,int l,int r,int ql,int qr){
    if(ql<=l && r<=qr)return seg[rt];
    LL res=inf;int mid=l+r>>1;pushdown(rt);
    if(mid>=ql)res=min(query(rt<<1,l,mid,ql,qr),res);
    if(mid+1<=qr)res=min(query(rt<<1|1,mid+1,r,ql,qr),res);
    return res;
}
LL f[N][2];
void build(int rt,int l,int r,int id){
    if(l==r){
        seg[rt]=f[l-1][id];tag[rt]=0;return;
    }
    tag[rt]=0;int mid=l+r>>1;
    build(rt<<1,l,mid,id);build(rt<<1|1,mid+1,r,id);
    pushup(rt);
}
int st[N],ed[N];
vector<int>h[N];
int main(){//freopen("in.txt","r",stdin);
    scanf("%d%d",&n,&k);
    int i,j;d[1]=0;
    rep(i,2,n)scanf("%lld",&d[i]);
    rep(i,1,n)scanf("%lld",&cst[i]);rep(i,1,n)scanf("%lld",&s[i]);rep(i,1,n)scanf("%lld",&w[i]);
    d[++n]=2e12;++k;
    rep(i,1,n)f[i][0]=inf;f[0][0]=0;
    rep(i,1,n){
        int l,r;l=i;r=n;
        while(l<=r){
            int mid=l+r>>1;
            if(d[mid]-d[i]<=s[i])ed[i]=mid,l=mid+1;else r=mid-1;
        }
        l=1;r=i;
        while(l<=r){
            int mid=l+r>>1;
            if(d[i]-d[mid]<=s[i])st[i]=mid,r=mid-1;else l=mid+1;
        }
    }
    rep(i,1,n)h[ed[i]].push_back(i);
    LL ans=0;
    rep(i,1,n)ans+=w[i];
    rep(j,1,k){
        rep(i,1,4*n)tag[i]=seg[i]=0;
        build(1,1,n,(j-1)&1);
        rep(i,1,n){
            f[i][j&1]=query(1,1,n,1,i)+cst[i];
            for(auto v:h[i]){
                if(st[v]>=1)mdy(1,1,n,1,st[v],w[v]);
            }
        }
        ans=min(ans,f[n][j&1]);
    }
    printf("%lld",ans);
}

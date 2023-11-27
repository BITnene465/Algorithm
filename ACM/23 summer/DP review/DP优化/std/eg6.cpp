#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define LL long long
#define D double
#define sz(X) (int)(X.size())
#define itr iterator
#define mkp make_pair
#define pr pair
#define fi first
#define se second
const int N=1e5+10;
const int M=1e5;
const LL inf=1e13;
LL k_[N<<4],b_[N<<4];
bool flg[N<<4];
int ls[N<<4],rs[N<<4],R[N],id;
void ins(int& rt,int l,int r,LL nk,LL nb){
	if(!rt){rt=++id;}
	if(!flg[rt]){flg[rt]=1;k_[rt]=nk;b_[rt]=nb;return;}
	LL l1=(LL)l*k_[rt]+b_[rt],r1=(LL)r*k_[rt]+b_[rt];
	LL l2=(LL)l*nk+nb;LL r2=(LL)r*nk+nb;
	if(l1>=l2 && r1>=r2){k_[rt]=nk;b_[rt]=nb;return;}
	if(l1<=l2 && r1<=r2)return;
	int mid=l+r>>1;
	D its=(D)(b_[rt]-nb)/(D)(nk-k_[rt]);
	if(its>=(D)mid){
		if(l2<=l1){ins(rs[rt],mid+1,r,k_[rt],b_[rt]);k_[rt]=nk;b_[rt]=nb;}
		else ins(rs[rt],mid+1,r,nk,nb);
	}else{
		if(l2>=l1){ins(ls[rt],l,mid,k_[rt],b_[rt]);k_[rt]=nk;b_[rt]=nb;}
		else ins(ls[rt],l,mid,nk,nb);
	}
}
LL mmin(LL x,LL y){return x>y ? y:x;}
LL query(int rt,int l,int r,LL k){
	if(l==r)return k*k_[rt]+b_[rt];
	if(!rt)return inf;
	int mid=l+r>>1;LL res=k_[rt]*k+b_[rt];
	if(mid>=(int)k)res=mmin(res,query(ls[rt],l,mid,k));
	else res=mmin(res,query(rs[rt],mid+1,r,k));
	return res;
}
void merg(int& u,int v,int l,int r){
	if(!u){u=v;return;}
	if(!v)return;
	int mid=l+r>>1;
	merg(ls[u],ls[v],l,mid);
	merg(rs[u],rs[v],mid+1,r);
	ins(u,l,r,k_[v],b_[v]);
}
struct edge{
	int nxt,to;
}e[N<<1];
int head[N],pos,n;
LL a[N],b[N],f[N];
void add(int u,int v){e[++pos]=(edge){head[u],v};head[u]=pos;}
void dfs(int u,int fa){
	int i;bool tag=1;
	for(i=head[u];i;i=e[i].nxt){
		int v=e[i].to;if(v==fa)continue;
		dfs(v,u);tag=0;
		merg(R[u],R[v],-M,M);
	}
	if(tag)f[u]=0;
	else f[u]=query(R[u],-M,M,a[u]);
	ins(R[u],-M,M,b[u],f[u]);//printf("%lld %lld\n",b[u],f[u]);
}
int main(){
	//freopen("in.txt","r",stdin);//freopen("o1.txt","w",stdout);
	scanf("%d",&n);int i;
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)scanf("%lld",&b[i]);
	rep(i,2,n){
		int x,y;scanf("%d%d",&x,&y);add(x,y);add(y,x);
	}
	rep(i,1,(N-10<<4))b_[i]=inf;
	dfs(1,0);
	rep(i,1,n)printf("%lld ",f[i]);
}

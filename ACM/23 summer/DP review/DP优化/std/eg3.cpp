#include <bits/stdc++.h>
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
const int N=2e5+10;
#define LL long long
LL f[2][N],cb;
inline LL c(int x){
	return (LL)x*(LL)(x-1)/2;
}
int n,k,a[N],s[N],pl,pr;
void add(int x){
	cb-=c(s[x]);++s[x];cb+=c(s[x]);
}
void del(int x){
	cb-=c(s[x]);--s[x];cb+=c(s[x]);
}
void solve(int l,int r,int L,int R,int id){
	register int mid=l+r>>1,i,j;
	if(l>r)return;
	int d=-1;
	while(pr<mid)add(a[++pr]);
	while(pr>mid)del(a[pr--]);
	while(pl<std::min(R,mid)+1)del(a[pl++]);
	while(pl>std::min(R,mid)+1)add(a[--pl]);
	dow(i,std::min(R,mid),L){
		if(d==-1 || f[id][mid]>f[id^1][i]+cb){
			d=i;f[id][mid]=f[id^1][i]+cb;
		}
		while(pl<i)del(a[pl++]);
		while(pl>i)add(a[--pl]);
	}
	solve(l,mid-1,L,d,id);solve(mid+1,r,d,R,id);
}
int main(){//freopen("in.txt","r",stdin);
	scanf("%d%d",&n,&k);register int i,j,s[N];memset(s,0,sizeof(s));
	rep(i,1,n)scanf("%d",&a[i]);
	LL cb=0;
	rep(i,1,n){
		cb-=c(s[a[i]]);++s[a[i]];cb+=c(s[a[i]]);
		f[1][i]=cb;
	}memset(s,0,sizeof(s));
	pl=1;pr=0;
	rep(j,2,k)solve(1,n,1,n,j&1);
	printf("%lld",f[k&1][n]);
}

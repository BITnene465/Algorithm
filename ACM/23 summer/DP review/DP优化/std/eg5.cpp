#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define si set<int>
#define sii set<int>::iterator
#define ms multiset<int>
#define msi multiset<int>::iterator
#define LL long long
#define vi vector<int>::iterator
#define D double
#define sz(X) (int)(X.size())
#define pb(x) push_back(x)
const int N=1e5+10;
const int K=210;
D eps=1e-9;
D inf=1e9;
int n,k,q[N],ql,qr,pt[N][K];
LL a[N],s[N],g[N],f[N];
D slope(int x,int y){
	if(s[x]==s[y])return inf;
	return (D)((g[x]-s[x]*s[x])-(g[y]-s[y]*s[y]))/(D)(s[x]-s[y]);
}
LL F(int x,int y){
	return g[x]+s[x]*(s[y]-s[x]);
}
void op(int i,int j){
	if(j==0)return;
	op(pt[i][j],j-1);
	printf("%d ",pt[i][j]);
}
int main(){//freopen("in.txt","r",stdin);freopen("o1.txt","w",stdout);
	scanf("%d%d",&n,&k);int i;
	rep(i,1,n)scanf("%lld",&a[i]);
	rep(i,1,n)s[i]=s[i-1]+a[i];int j;
	rep(j,1,k){
		ql=1;qr=0;memset(q,0,sizeof(q));
		rep(i,1,n){
			while(qr>ql && slope(q[qr-1],q[qr])<=slope(q[qr],i))--qr;
			q[++qr]=i;
			while(qr>ql && slope(q[ql],q[ql+1])>=(D)(-s[i]))++ql;
			f[i]=F(q[ql],i);pt[i][j]=q[ql];
		}
		rep(i,1,n)g[i]=f[i];
	}
	printf("%lld\n",f[n]);
	op(n,k);
}

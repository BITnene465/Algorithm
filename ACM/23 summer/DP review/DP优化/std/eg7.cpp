#include <bits/stdc++.h>
using namespace std;
#define rep(i,j,k) for(i=j;i<=k;++i)
#define dow(i,j,k) for(i=j;i>=k;--i)
#define pr pair
#define mkp make_pair
#define fi first
#define se second
const int N=1e6+10;
int l[N],r[N],bot[N],n,botcnt,id,mx[N],mx2[N],f[N],g[N],st[N][25],lg[N];
map<int,int>h;
vector<int>t[N];
int query(int l,int r){
	if(l>r)return 1<<31;
	int k=lg[r-l+1];
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
int main(){
	scanf("%d",&n);int i,j;
	rep(i,1,n){
		scanf("%d%d",&l[i],&r[i]);
		bot[++botcnt]=l[i];bot[++botcnt]=r[i];
	}
	sort(bot+1,bot+1+botcnt);
	rep(i,1,botcnt)if(i==1 || bot[i]!=bot[i-1])h[bot[i]]=++id;
	rep(i,1,n)l[i]=h[l[i]],r[i]=h[r[i]];
	//printf("-----\n");
	rep(i,1,n){//printf("%d %d\n",l[i],r[i]);
		if(l[i]>mx[r[i]])mx2[r[i]]=mx[r[i]],mx[r[i]]=l[i];else if(l[i]>mx2[r[i]])mx2[r[i]]=l[i];
		t[r[i]].push_back(i);
	}
	rep(i,1,id)st[i][0]=mx[i];
	rep(j,1,20)for(i=1;i+(1<<j)-1<=id;++i)st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
	lg[1]=0;rep(i,2,id)lg[i]=lg[i>>1]+1;
	rep(i,1,id){
		for(auto v:t[i]){
			int tmp=query(l[v],i-1);
			if(l[v]==mx[i])tmp=max(tmp,mx2[i]);else tmp=max(tmp,mx[i]);
			if(tmp<=0)continue;
			tmp=min(tmp,l[v]);
			if(tmp>1 && tmp<=id)
			f[i]=max(f[i],g[tmp-1]+1);else f[i]=max(f[i],1);
		}
		g[i]=max(g[i-1],f[i]);
	}
	printf("%d",g[id]<<1);
}

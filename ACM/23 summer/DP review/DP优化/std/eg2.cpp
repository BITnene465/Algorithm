// luogu-judger-enable-o2
#include <bits/stdc++.h>
using namespace std;
#define _l long long
int n,m,a[20][20],b[20][20];
map<_l,int>dp;
set<_l>hh;
void unzip(int* arr,_l s){
	int pos=n;
	while(s){
		arr[pos--]=s%11;s/=11;
	}
}
_l zip(int *arr){
	_l w=1;
	_l res=0;
	for(int i=n;i>0;--i,w*=11)
	res+=arr[i]*w;
	return res;
}
void dfs(_l u){
	if(hh.count(u))return;
	int pos=n,sta[20],i;
	for(i=1;i<=n+1;++i)sta[i]=0;
	unzip(sta,u);
	int cnt=0;hh.insert(u);
	for(i=1;i<=n;++i)cnt+=sta[i];++cnt;
	if(cnt%2==1)dp[u]=1<<31;else dp[u]=1<<30;
	for(i=1;i<=n;++i){
		if(i==1 || (sta[i-1]>sta[i])){
			++sta[i];if(sta[i]>m){
				--sta[i];continue;
			}
			_l k=zip(sta);
			dfs(k);
			if(cnt%2==1)dp[u]=max(dp[u],dp[k]+a[i][sta[i]]);
			else dp[u]=min(dp[u],dp[k]-b[i][sta[i]]);
			--sta[i];
		}
	}
}
int main(){//freopen("in.txt","r",stdin);//freopen("o1.txt","w",stdout);
	scanf("%d%d",&n,&m);
	int i,j;
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)for(j=1;j<=m;++j)scanf("%d",&b[i][j]);
	int arr[20];
	memset(arr,0,sizeof(arr));
	for(i=1;i<=n;++i)arr[i]=m;
	_l k=zip(arr);hh.insert(k);dp[k]=0;
	dfs(0);
	printf("%d",dp[0]);
}
/*
2 3
3 5 3 
4 4 5 
2 1 5 
5 2 3 
*/

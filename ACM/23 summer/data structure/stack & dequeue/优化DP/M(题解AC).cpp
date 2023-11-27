#include<bits/stdc++.h>
using namespace std;
int n,w,s;
long long f[5508][5508],a[5508],ans=LONG_LONG_MIN;
deque<int> q;
int main(){
	scanf("%d%d%d",&n,&w,&s);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int i=0;i<=n;i++) for(int j=0;j<=w;j++) f[i][j]=LONG_LONG_MIN;
	f[0][0]=0;
	for(int i=1;i<=n;i++){
		while(q.size()) q.pop_back();
		for(int j=1;j<=min(w,s-1);j++){
			while(q.size()&&f[i-1][j]>=f[i-1][q.back()]) q.pop_back();
			q.push_back(j);
		}
		for(int j=1;j<=min(i,w);j++){
			if(f[i-1][j-1]!=LONG_LONG_MIN) f[i][j]=f[i-1][j-1]+a[i]*j;
			while(q.size()&&q.front()<j) q.pop_front();
			if(j+s-1<=w){
				while(q.size()&&f[i-1][j+s-1]>=f[i-1][q.back()]) q.pop_back();
				q.push_back(j+s-1);
			}
			if(f[i-1][q.front()]!=LONG_LONG_MIN) f[i][j]=max(f[i][j],f[i-1][q.front()]+a[i]*j);
		}
	}
	for(int i=1;i<=w;i++) ans=max(ans,f[n][i]);
	printf("%lld",ans);
	return 0;
}
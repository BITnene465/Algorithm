// 似乎和树没有关系，可以单调栈 o(n) //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,h[100005],top,stk[100005];
ll pre[100005],nxt[100005];    // 分别记录前后第一个比h[i]小的数值的索引
ll solve()
{
    top = 0;
    h[n+1]=-1;
    for(int i=1;i<=n+1;++i){
        while(top&&h[i]<h[stk[top]]){nxt[stk[top]]=i;--top;}
        stk[++top] = i;
    }
    top = 0;
    h[0] = -1;
    for(int i=n;i>=0;--i){
        while(top&&h[i]<h[stk[top]]){pre[stk[top]]=i;--top;}
        stk[++top] = i;
    }
    ll ans = 0;
    for(int i=1;i<=n;++i)ans=max(ans,h[i]*(nxt[i]-pre[i]-1));
    return ans;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
        if(n==0)break;
        for(int i=1;i<=n;++i)cin>>h[i];
        cout<<solve()<<endl;
    }
    return 0;
}
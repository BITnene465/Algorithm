#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[10000005],n,m;
const ll mod = 1e9+7;
ll q[20000005],tail,head; // 实现双端队列
ll ans = 0;
int main(void)
{
    scanf("%lld %lld",&n,&m);
    scanf("%lld",v+1);
    for(ll i=2;i<=n;i++)
        v[i] = (v[i-1]*v[i-1] + 100)%mod;
    // 单调队列维护, 最大值一定是队首 次大值可能是第二个（不一定有） 也可能是出队（什么时候出队的？）的最大值
    ll ans = 0;
    ll temp,temp2;
    tail = 1e6,head = tail+1; 
    for(int cur=1;cur<=n;cur++)     // cur表示当前要入队的编号
    {
        while(head<=tail&&q[head]+m<=cur)   ++head;
        while(head<=tail&&v[q[tail]]<=v[cur]) temp2=v[q[tail--]];   // 本次的更新用temp2暂时记上，到时候再转给temp

        if(head+1<=tail)    temp = max(temp,v[q[head+1]]);
        if(cur>=m)  ans=max(ans,temp+v[q[head]]);
        temp = temp2;     // temp保留的是下一个区间的可能的最小值
    }
    //
    printf("%lld\n",ans);
    return 0;
}
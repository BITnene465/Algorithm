// 跳房子 //
// DP + 单调队列优化 //
// 答案单调性 -> 可以二分搜索 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = LONG_LONG_MIN;
deque<ll> q;
ll n,d,k,Max,sum;
ll value[1000005];  // 机器人从 0 出发
ll dis[1000005];
ll dp[1000005];   // 到第 n 个格子的最大分数
bool check(ll g)
{
    ll l = max((ll)1,d-g);
    ll r = d+g;
    // init
    q.clear();
    for(ll i=1;i<=n;i++)
        dp[i] = INF;
    dp[0] = 0;
    //
    ll cur = 0;  // 当前要入队列的格子的下标
    for(ll i=0;i<=n;i++)
    {
        while(dis[cur]+r<dis[i])    cur++;   // cur太靠后了，要加回来
        while(dis[cur]+l<=dis[i])   // 由定义 必有 cur<=i<=n ,不会越界
        {
            while(!q.empty()&&dp[q.back()]<=dp[cur])    q.pop_back();
            q.push_back(cur);
            cur++;
        }
        while(!q.empty()&&dis[q.front()]+r<dis[i])  q.pop_front();
        if(!q.empty()&&dp[q.front()]!=INF)     
        {
            dp[i] = dp[q.front()]+value[i];
            if(dp[i]>=k)    return true;
        }
    }
    //
    return false;
}
int main(void)
{
    cin>>n>>d>>k;
    dis[0] = 0;
    for(ll i=1;i<=n;++i)
    {
        scanf("%lld %lld",dis+i,value+i);
        if(value[i]>0) sum+=value[i];
    }
    // 判断是否可一到达分数k
    if(sum<k){
        printf("-1\n");
        return 0;
    }
    ll mid; 
    ll r = 1010;   // 挑一个大一点点的数
    ll l = 1;
    while(r!=l)
    {
        mid = (r+l)/2;
        if(check(mid))  r = mid;
        else    l = mid+1; 
    }
    printf("%lld\n",l);
    return 0;
}
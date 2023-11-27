#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll v[10000005],n,m;
const ll mod = 1e9+7;
deque<ll> q;
ll ans = 0;
int main(void)
{
    scanf("%lld %lld",&n,&m);
    scanf("%lld",v+1);
    for(ll i=2;i<=n;i++)
        v[i] = (v[i-1]*v[i-1] + 114514)%mod;
    // 单调队列
    for(ll i=1;i<=m-1;i++)
    {
        while(!q.empty()&&v[q.back()]<=v[i])  q.pop_back();
        q.push_back(i);
    }
    for(ll cur=m;cur<=n;cur++)    // 有一部分欠考虑了，导致出错！！！ WA还找不到错误就重写一遍
    {
        while(!q.empty()&&cur-q.front()>=m) q.pop_front();
        if(v[q.front()]<=v[cur])    
        {
            ans = max(ans,v[cur]+v[q.front()]);
            while(!q.empty()&&v[q.back()]<=v[cur])  q.pop_back();
            q.push_back(cur);
            continue;
        }
        while(!q.empty()&&v[q.back()]<=v[cur])  q.pop_back();
        q.push_back(cur);
        ll index1,index2;
        index1 = q.front();
        q.pop_front();
        index2 = q.front();
        q.push_front(index1);
        ans = max(ans,v[index1]+v[index2]);
    }
    //
    printf("%lld\n",ans);
    return 0;
}
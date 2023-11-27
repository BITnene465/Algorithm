// 弱化版 AC //
// 加强版 TLE 必须要用 o(n) 的算法 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
priority_queue<ll,vector<ll>,greater<ll>> q;  // 小根堆
int main(void)
{
    cin>>n;
    ll ans = 0;
    ll temp,temp2;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&temp);
        q.push(temp);
    }
    while(!q.empty())
    {
        temp = q.top();
        q.pop();
        if(q.empty())   break;
        temp2 = q.top();
        q.pop();
        temp = temp + temp2;
        ans+=temp;
        q.push(temp);
    }
    cout<<ans<<endl;
    return 0;
}
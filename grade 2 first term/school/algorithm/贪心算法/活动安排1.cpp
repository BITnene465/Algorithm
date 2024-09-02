// n个活动申请一个活动室，求最大相容活动子集  //
// 贪心策略： 1. 每次选当前可选的结束最早的活动 //
// 时间复杂度： o(nlogn)  主要是在排序 //
#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int st, ed;
}node[1005];
int main(void)
{
    int n;
    cin >> n;
    for(int i=1;i<=n;++i)cin>>node[i].st>>node[i].ed;
    sort(node+1, node+n+1, [](Node& a, Node& b){return (a.ed != b.ed)?(a.ed<b.ed):(a.st<b.st);});

    int ans = 0;
    int now = 0;
    for(int i=1;i<=n;++i)
    {
        if(node[i].st >= now) now = node[i].ed, ans++;
    }
    cout<<ans<<endl;
    return 0;
}
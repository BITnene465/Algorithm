// 典型贪心算法 贪心策略： 每次做当前可以做的结束时间最早的任务 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+5;
int n;
struct Task{
    int st,ed;
}tasks[maxn];
bool cmp(Task  a, Task  b)
{
    //  if(a.ed<b.ed)return 1;
    return a.ed < b.ed;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>tasks[i].st>>tasks[i].ed;
    sort(tasks+1,tasks+n+1,cmp);
    // for(int i=1;i<=n;++i)cout<<tasks[i].st<<' '<<tasks[i].ed<<endl;
    int cnt=0,now=0;
    for(int i=1;i<=n;++i)
    {
        if(now>tasks[i].st)continue;
        now=tasks[i].ed;
        cnt++;
    }
    cout<<cnt<<endl;
    return 0;
}
// 贪心算法 //
/* 
题解：设一组最优解为N，n组起始和终止时间分别为 a[1],b[1],...,a[n],b[n],且b按照升序排序
断定：最优解N中必包含a[1],b[1]
证明：否则设包含的下标最小的时间段为a[i],b[i],且i>1,则a[i]~b[i]是最先结束的节目，由于b[1]<b[i],将其替换为a[1],b[1]
仍然为最优解
贪心策略：如上
*/
#include<bits/stdc++.h>
using namespace std;
const int N =100;
int ans;
int n;
struct node {
    int st;
    int ed;
}times[N];
void solve()
{
    ans = 1;
    int index = 0;
    int i = index+1;
    while(1){
    while(times[i].st<times[index].ed&&i<n)  i++;
    if(i==n)    break;
    else
    {
        ++ans;
        index = i;
        ++i;
    }
    }
}
bool cmp(node a,node b)
{
    return a.ed<b.ed;
}
int main(void)
{
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d %d",&times[i].st,&times[i].ed);
    sort(times,times+n,cmp);
    ans = 0;
    solve();
    cout<<ans<<endl;
    return 0;
}
// 一维DP 单调队列优化  如果每次劳累值增量会改变，那么就不是这么简单了 //
#include<bits/stdc++.h>
using namespace std;
int n,q,d[1000005],k;
int dp[1000005];
deque<int> qu;
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",d+i);
    cin>>q;
    while(q--)
    {
        scanf("%d",&k);
        //
        memset(dp,0,sizeof(int)*(n+1));   // 由于本题的树都可以到达，故不需要设置INF
        qu.clear();
        int cur = 1;
        for(int i=2;i<=n;i++)
        {
            while(cur+k<i) cur++;    // cur落后了
            while(cur+1<=i)   // 在区间内，可以入队
            {
                while(!qu.empty()&&(dp[qu.back()]>dp[cur]||dp[qu.back()]==dp[cur]&&d[cur]>=d[qu.back()])) // 有第二关键字，树高
                    qu.pop_back();
                qu.push_back(cur);
                cur++;
            }
            while(!qu.empty()&&qu.front()+k<i)  qu.pop_front();   // 清除越界
            //
            int index = qu.front();
            dp[i] = dp[index] + (d[i]>=d[index]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
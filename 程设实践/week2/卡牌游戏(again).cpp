// 策略固定，分类讨论 //
// Again //
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int ans,n,heap[maxn],idx[maxn];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){int x;cin>>x;if(x==0)continue;idx[x]=0;}  // idx[i]=0表示i在手上
    for(int i=1;i<=n;++i){int x;cin>>x;idx[x]=i;heap[i]=x;}
    // 检测结尾部分是否是从1开始的连续序列
    bool isConstant = 1;
    for(int i=n;i>=0;--i)
    {
        if(heap[i]==1)break;
        if(heap[n]-heap[i]!=n-i){isConstant=0;break;}
    }
    if(isConstant)    // 结尾为从1开始的连续序列
    {
        bool isok=1;   // 检查是否可以一轮过
        for(int i=heap[n]+1;i<=n;++i)if(idx[i]-i+heap[n]>=0){isok=0;break;}
        if(isok){ans=n-heap[n];}  // 可以一轮过
        else    {ans=(n-heap[n]+1)+n;}   // 无奈再加一轮
    }
    else             // 结尾不是从1开始的连续序列
    { 
        int t=0;    // 要求t+i时刻牌i在手上 ， 故有 idx[i]<=t+i-1 对于任意i成立
        for(int i=1;i<=n;++i)t=max(t,idx[i]-i+1);
        ans=t+n;
    }
    cout<<ans<<endl;
    return 0;
}

/*
测试案例：
结尾连续 5 0 1 2 3 4
        0 0 1 2 3 4
结尾不连续 1 0 2 3 4
          0 0 2 3 4
*/
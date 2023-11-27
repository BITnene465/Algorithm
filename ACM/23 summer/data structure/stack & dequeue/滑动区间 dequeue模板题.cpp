#include<bits/stdc++.h>
using namespace std;
deque<int> q1;   // 用来存编号,维护最大值
deque<int> q2;   // 维护最小值
int n,k;
int arr[1000005];
int mi[1000005],ma[1000005];
int main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    // 单调队列
    for(int cur=1;cur<=n;cur++)
    {
        if(!q1.empty())
        {
            if(q1.front()<=cur-k)  q1.pop_front();   // 编号在区间之外，队首出，该操作优先级高
            while(!q1.empty()&&arr[q1.back()]<arr[cur])    q1.pop_back();   // 维护队列单调
        }
        q1.push_back(cur);
        if(cur>=k) ma[cur-k+1] = arr[q1.front()];   // 更新最大值
        // 下面的最小值同理
        if(!q2.empty())
        {
            if(q2.front()<=cur-k)  q2.pop_front();
            while(!q2.empty()&&arr[q2.back()]>arr[cur])   q2.pop_back();
        }
        q2.push_back(cur);
        if(cur>=k) mi[cur-k+1] = arr[q2.front()];
    }
    // print
    for(int i=1;i<=n-k+1;i++)
        printf("%d%c",mi[i],(i==n-k+1)?'\n':' ');
    for(int i=1;i<=n-k+1;i++)
        printf("%d%c",ma[i],(i==n-k+1)?'\n':' ');
    return 0;
}
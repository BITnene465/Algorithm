/*
我们假设某个点为某个区间最小值，那当区间从该点往左右延拓的时候，
由于区间和在变大，最小值又不变，则所求的值是单调递增的，
那么只需求出每个点最远能向左和向右延拓到的最远的点即可，
即是求每个点左边和右边的第一个小于自身的点的位置

解决上述问题就是单调栈的模板问题，
求出来左右端点后枚举一遍取最小值即可。
*/
#include<bits/stdc++.h>
using namespace std;
int arr[100005];
int f1[100005],f2[100005];  // 分别记录NLE 和 PLE
stack<int> s;
int n;
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    // init
    for(int i=1;i<=n;i++)
        f1[i]=n+1,f2[i]=0;
    // NLE
    for(int cur=1;cur<=n;cur++)
    {
        while(!s.empty()&&arr[cur]<arr[s.top()])    f1[s.top()]=cur,s.pop();
        s.push(cur);      
    }
    // PLE
    while(!s.empty())   s.pop();   // 清空栈
    for(int cur=n;cur>=1;cur--)
    {
        while(!s.empty()&&arr[cur]<arr[s.top()])    f2[s.top()]=cur,s.pop();
        s.push(cur);
    }
    // 枚举
    int ans = INT_MIN;
    int r=0,l=0;
    for(int i=1;i<=n;i++)
    {
        int sum = 0;
        for(int j=f2[i]+1;j<=f1[i]-1;j++)
            sum+=arr[j];
        sum = sum*arr[i];
        if(sum>ans)
        {
            ans = sum;
            l = f2[i]+1;
            r = f1[i]-1;
        }
    }
    // print
    cout<<ans<<endl;
    cout<<l<<" "<<r<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
stack<int> s;   // 存编号
int f[3000005];
int arr[3000005];
int n;
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    // 单调栈
    for(int cur=1;cur<=n;cur++)  // 每次都维护单调
    {
        while(!s.empty()&&arr[cur]>arr[s.top()])   f[s.top()]=cur,s.pop();  // 把非空判断写在前面
        s.push(cur);
    }
    for(int i=1;i<=n;i++)
        printf("%d ",f[i]);
    printf("\n");
    return 0;
}
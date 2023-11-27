// G鱼鱼之怒->单调栈完善版 //
// 要注意到可能挡住鱼鱼的值是单调的 //
#include<bits/stdc++.h>
using namespace std;
int a[1000005];  
int n;
int s[1000005],top = -1;  //实现栈
int main(void)
{
    cin>>n;
    int ans=0;
    for(int i=1;i<=n;i++)   scanf("%d",a+i);
    for(int cur=1;cur<=n;cur++)
    {
        while(top!=-1&&a[s[top]]<=a[cur])   ans = ans^s[top--];
        s[++top] = cur;
        ans = ans^cur;
        printf("%d\n",ans);
    }
    return 0;
}

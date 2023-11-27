// 数组实现栈 //
#include<iostream>
#include<cstdio>
using namespace std;
typedef long long ll;
ll arr[100005];
int f1[100005],f2[100005];  // 分别记录NLE 和 PLE
int s[100005];   // 实现栈
int top;
int n;
ll sum[100005];  // 储存前缀和
int main(void)
{
    while(~scanf("%d",&n))
    {
        sum[0] = 0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",arr+i);
            sum[i] = sum[i-1] + arr[i];
        }
        // init
        for(int i=1;i<=n;i++)
            f1[i]=n+1,f2[i]=0;
        // NLE
        top = -1;
        for(int cur=1;cur<=n;cur++)
        {
            while(top!=-1&&arr[cur]<arr[s[top]])    f1[s[top--]]=cur;
            s[++top] = cur;      
        }
        // PLE
        top = -1;                  // 清空栈
        for(int cur=n;cur>=1;cur--)
        {
            while(top!=-1&&arr[cur]<arr[s[top]])    f2[s[top--]]=cur;
            s[++top] = cur;
        }
        // 枚举
        ll ans = 0;
        int r=0,l=0;
        for(int i=1;i<=n;i++)
            if(ans<arr[i]*(sum[f1[i]-1]-sum[f2[i]+1]))
            {
                ans=arr[i]*(sum[f1[i]-1]-sum[f2[i]]);
                l = f2[i]+1;
                r = f1[i]-1;
            }
        // print
        printf("%lld\n",ans);
        printf("%d %d\n",l,r);
    }
    return 0;
}
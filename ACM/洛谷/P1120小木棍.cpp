// TLE版本
#include<bits/stdc++.h>
using namespace std;
const int maxN = 66;
int n;
int L,N;
int ans;
int sum;
int vis[maxN];
int arr[maxN];
bool cmp(int x,int y)
{
    return x>y;
}
//  last 表示上一个小木棒的序号
void dfs(int now,int t,int last,bool &flag)  // t用来记录当前补齐了多少根小木棍
{
    if(t==N-1)      // 优化：t等于N-1结合sum的定义可知一定有符合题意的解
    {
        flag = true;
        return;
    }
    else
    {
        int res = L-now;
        int st = last+1;       // 优化：从比上一根短的木棍开始搜索
        while(vis[st]||arr[st]>res) st++;
        //
        for(int i=st;i<=n;i++)     
        {
            if(!vis[i])
            {
                if(arr[i]<res)
                {
                    vis[i]=1;
                    dfs(now+arr[i],t,i,flag);
                    vis[i]=0;    // 还原vis数组
                    if(flag)  return;   // 优化：找到答案就退出
                }
                else if(arr[i]==res)
                {
                    vis[i]=1;
                    dfs(0,t+1,0,flag);
                    vis[i]=0;    // 还原vis数组
                    if(flag)  return;  // 优化：找到答案就退出
                }
            }
        }
    }
}
bool check(int L)    // N根长木棒，长度为L
{
    N = sum/L;
    bool flag = false;
    dfs(0,0,0,flag);
    return flag;
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",arr+i);
    sort(arr+1,arr+n+1,cmp);    // 优化：注意要用arr+n+1,降序排序,为了搜索时更加灵活
    sum = 0;
    for(int i=1;i<=n;++i)
        sum+=arr[i];
    //
    for(L=arr[1];L<=sum/2;L++)     // 优化：只看arr[1]<=L<=sum/2的情况，否则只能L==sum符合题意
    {
        if(sum%L==0)
        {
            if(check(L))
            {
                ans = L;
                break;
            }
        }
    }
    // 输出结果
    if(ans==0)
        ans = sum;
    printf("%d\n",ans);
    return 0;
}
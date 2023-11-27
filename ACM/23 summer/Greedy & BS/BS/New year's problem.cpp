// 由于答案有单调性，可以二分答案 //
#include<bits/stdc++.h>
using namespace std;
int m,n,t;
int p[1005][1005];
int flag[1005];
int flag2;
// c可行 当且仅当 1.有一家商店可以满足两个好友 2.每一个好友都至少有一个商店可以满足
bool check(int c)
{
    flag2 = 0;
    for(int i=1;i<=n;i++)
        flag[i] = 0;
    for(int i=1;i<=m;i++)
    {
        int cnt=0;
        for(int j=1;j<=n;j++)
        {
            if(p[i][j]>=c)
            {
                flag[j] = 1;
                cnt++;
            }
        }
        if(cnt>=2)  flag2 = 1;
    }
    if(flag2)
    {
        for(int i=1;i<=n;i++)
        {
            if(!flag[i])    return false;
        }
        return true;
    }
    return false;
}
int main(void)
{
    cin>>t;
    while(t--)
    {
        scanf("%d %d",&m,&n);
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&p[i][j]);
        int c;
        int l=1,r=1e9;
        while(l<=r)
        {
            int mid = (l+r)/2;
            if(check(mid))  l=mid+1;
            else r=mid-1;
        }
        if(r!=0)    // 找到了
            printf("%d\n",r);
    }
    return 0;
}
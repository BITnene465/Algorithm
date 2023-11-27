// hdu 1213 "how many tables" //
#include<bits/stdc++.h>
#define N 100
using namespace std;
int ans;
int s[N];   // 用于实现并查集的数组
void init_set(int n)    // 初始化
{
    for(int i=1;i<=n;++i)
        s[i] = i;
    return;
}
int find_set(int x)   // 查找
{
    return x==s[x]?x:find_set(s[x]);
}
void union_set(int x,int y)   // 合并
{
    x = find_set(x);
    y = find_set(y);
    s[x] = y;
    return;
}

int main(void)
{
    int n;
    cin>>n;
    init_set(n);
    ans = 0;
    //
    int T;
    cin>>T;
    for(int i=0;i<T;++i)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        union_set(x,y);
    }
    //
    for(int i=1;i<=n;++i)
    {
        if(s[i]==i)
            ++ans;
    }
    cout<<ans<<endl;
    return 0;
}
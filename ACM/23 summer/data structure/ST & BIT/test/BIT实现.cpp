#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
int a[maxn],bit[maxn],n;
inline int lowbit(int x){return x&-x;}
int add(int x,int k)    // a[x]的值增加k
{
    while(x<=n){bit[x]+=k;x=x+lowbit(x);}// 防止越界
}
void init()   // O(nlogn)建树，n次单点增加（add）即可
{
    for(int i=1;i<=n;++i)add(i,a[i]);
}
void init2()   // O(n) 建树
{
    
}
int getsum(int x)   // 计算sum[x]
{
    int res=0;
    while(x)
    {
        res+=bit[x];
        x=x-lowbit(x);
    }
    return res;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    init();
    while(1)
    {
        int l,r;
        cin>>l>>r;
        if(!l)break;
        cout<<getsum(r)-getsum(l-1)<<endl;
    }
    return 0;
}
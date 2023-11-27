// 猜测或打表来证明单调决策 //
// 在已知单调决策的情况下使用 分治法 //
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+5;
int a[N],p1[N],p2[N],s[N],n;
double sqr[N];   // 预处理根号
void solve(int l,int r,int L,int R)   // [l,r]是待测区间 , [L,R]是搜索区间
{
    if(l>r) return;
    int mid = l +(r-l>>1);
    int id = -1;
    for(int i=L;i<=min(R,mid-1);i++)
        if(id==-1||(double)a[i]+sqr[mid-i]>(double)a[id]+sqr[mid-id])  id=i;   // 找到mid的最佳决策点
    s[mid] = id;
    solve(l,mid-1,L,id);
    solve(mid+1,r,id,R);
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)   scanf("%d",a+i);
    for(int i=0;i<=n;i++)   sqr[i] = sqrt(i);
    solve(1,n,1,n);  
    for(int i=1;i<=n;i++)   p1[i] = ceil(a[s[i]]-a[i]+sqr[i-s[i]]);
    reverse(a+1,a+n+1);
    solve(1,n,1,n);
    for(int i=1;i<=n;i++)   p2[i] = ceil(a[s[i]]-a[i]+sqr[i-s[i]]);
    reverse(p2+1,p2+n+1);
    for(int i=1;i<=n;i++)   printf("%d\n",max(0,max(p1[i],p2[i])));    // 0 是为了防止浮点数运算的误差
    return 0;
}
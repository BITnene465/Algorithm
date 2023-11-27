// AC 代码 //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> CP;
const ll maxn=1<<22;
const double PI=acos(-1.0);   // 常数PI
// 时间复杂度O(nlogn) //
// n=2^k ,若不足则补齐，否则该算法不成立 //
CP f[maxn],g[maxn],tmp[maxn];
void _FFT(CP* f,ll n,ll rev)
{
    if(n==1)  return;   // 长度为1，无需操作，直接返回
    for(ll i=0;i<n;++i) tmp[i]=f[i];
    // 偶数放左边，奇数放右边 //
    for(ll i=0;i<n;++i)
    {
        if(i&1) f[n/2+i/2]=tmp[i];
        else    f[i/2]=tmp[i];
    }
    // 递归DFT
    _FFT(f,n/2,rev);_FFT(f+n/2,n/2,rev);
    // cur当前的乘数因子 , step为本原单位根
    CP cur(1,0),step(cos(2*PI/n),rev*sin(2*PI/n));
    for(ll k=0;k<n/2;++k)
    {
        tmp[k]=f[k]+f[n/2+k]*cur;
        tmp[k+n/2]=f[k]-f[n/2+k]*cur;
        cur*=step;
    }
    for(ll i=0;i<n;i++)    f[i]=tmp[i];  
    return;
}
// DFT & IDFT//
// n=2^k ,若不足则补齐，否则该算法不成立 //
void FFT(CP* f,ll n,ll rev)
{
    _FFT(f,n,rev);
    if(rev==-1) for(ll i=0;i<n;i++) f[i]=f[i]*(CP)(1.0/n)+0.5;   // 浮点数运算精度问题，此处要加0.5 
    return;
}
// 该算法的辅助函数 2^k严格大于n，n为f的最高次数 //
ll log2ceil(ll n){ll cnt=0;for(ll i=1;i<=n;i=i<<1)++cnt;return cnt;}

ll n,m;
int main(void)
{
    scanf("%lld %lld",&n,&m);
    for(ll i=0;i<=n;i++)    scanf("%lf",f+i);
    for(ll i=0;i<=m;i++)    scanf("%lf",g+i);
    ll deg=1<<log2ceil(n+m);
    FFT(f,deg,1);FFT(g,deg,1);
    for(ll i=0;i<deg;i++)   f[i]=f[i]*g[i];
    FFT(f,deg,-1);
    for(ll i=0;i<=n+m;i++)  printf("%lld ",(ll)f[i].real());
    printf("\n");
    return 0;  
}
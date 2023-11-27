#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef complex<double> CP;
const ll maxn=1<<20;
const CP I(0,1);     // 虚数单位
const double PI=acos(-1);   // 常数PI
// 时间复杂度O(nlogn) //
// n=2^k ,若不足则补齐，否则该算法不成立 //
CP f[maxn],tmp[maxn];
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
    if(rev==-1) for(ll i=0;i<n;i++) f[i]*=(CP)(1.0/n);
    return;
}
// 该算法的辅助函数 2^k严格大于n，n为f的最高次数 //
ll log2ceil(ll n){ll cnt=0;for(ll i=1;i<=n;i=i<<1)++cnt;return cnt;}

// test //
CP g[maxn],h[maxn];
int main(void)
{   
    ll l1,l2;
    cin>>l1>>l2;
    double t;
    for(ll i=0;i<=l1;i++)   {cin>>t;g[i].real(t);g[i].imag(0.0);}
    for(ll i=0;i<=l2;i++)   {cin>>t;h[i].real(t);h[i].imag(0.0);}
    cout<<"g(x)="<<endl;
    for(ll i=0;i<=l1;i++)    printf("%+.2lf x^%lld ",g[i].real(),i);
    cout<<endl;
    cout<<"h(x)="<<endl;
    for(ll i=0;i<=l2;i++)    printf("%+.2lf x^%lld ",h[i].real(),i);
    cout<<endl;
    ll deg=1<<log2ceil(l1+l2);
    for(ll i=l1+1;i<=deg;++i)   g[i]=0;
    for(ll i=l2+1;i<=deg;++i)   h[i]=0;
    FFT(g,deg,1);FFT(h,deg,1);
    // 
    for(ll i=0;i<deg;i++)  f[i]=g[i]*h[i];
    FFT(f,deg,-1);
    cout<<"f(x)="<<endl;
    for(ll i=0;i<=l1+l2;i++)    printf("%+.2lf x^%lld ",f[i].real(),i);
    cout<<endl;
    FFT(h,deg,-1);
    cout<<"h(x)="<<endl;
    for(ll i=0;i<deg;i++)    printf("%+.2lf x^%lld ",h[i].real(),i);
    return 0;
}
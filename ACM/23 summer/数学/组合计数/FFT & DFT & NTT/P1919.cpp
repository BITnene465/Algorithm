#include<bits/stdc++.h>
using namespace std;
typedef complex<double> CP;
const double PI=acos(-1.0);
const int maxn=4e6+5;
CP f[maxn],g[maxn],h[maxn];
int ans[maxn];
int read_num(CP *a)
{
    char ch;int cur=-1;
    ch=getchar();
    while(ch>'9'||ch<'0')ch=getchar();
    while(ch<='9'&&ch>='0'){a[++cur]=(CP)(ch-'0');ch=getchar();}
    return cur;
}
CP tmp[maxn];
void _FFT(CP* f,int n,int rev)
{
    if(n==1)return;
    for(int i=0;i<n;i++)tmp[i]=f[i];
    for(int i=0;i<n/2;i++)
    {
        f[n/2+i]=tmp[2*i+1];
        f[i]=tmp[2*i];
    }
    _FFT(f,n/2,rev);_FFT(f+n/2,n/2,rev);
    CP cur_w=CP(1,0),w=CP(cos(2*PI/n),rev*sin(2*PI/n));
    for(int k=0;k<n/2;++k)
    {
        tmp[k]=f[k]+cur_w*f[n/2+k];
        tmp[n/2+k]=f[k]-cur_w*f[n/2+k];
        cur_w*=w;
    }
    for(int k=0;k<n;++k)
        f[k]=tmp[k];
    return;
}   
void FFT(CP* f,int n,int rev)
{
    _FFT(f,n,rev);
    if(rev==-1)
        for(int i=0;i<n;i++)     // 注意0<=i<n
            f[i]*=(CP)(1.0/n);
    return;
}
int log2ceil(int n)
{
    int cnt=0;
    for(int x=1;x<=n;x=x<<1)cnt++;
    return cnt;
}
int main(void)
{
    int dg,dh;
    dg=read_num(g);
    dh=read_num(h);
    CP t;
    for(int i=0;i<=dg/2;i++){t=g[i];g[i]=g[dg-i];g[dg-i]=t;}
    for(int i=0;i<=dh/2;i++){t=h[i];h[i]=h[dh-i];h[dh-i]=t;}
    int deg=1<<log2ceil(dg+dh);
    FFT(g,deg,1);
    FFT(h,deg,1);
    for(int i=0;i<deg;i++)
        f[i]=g[i]*h[i];
    FFT(f,deg,-1);
    // 进位 //
    for(int i=0;i<=dg+dh+1;i++)   // 最多dg+dh+2位数
    {
        ans[i]+=(int)(f[i].real()+0.5);
        ans[i+1]+=ans[i]/10;
        ans[i]=ans[i]%10;
    }
    int cur=dg+dh+2;
    while(cur>-1&&!ans[cur])    --cur;
    if(cur==-1){printf("0\n");return 0;}
    for(int i=cur;i>=0;--i)
        printf("%d",ans[i]);
    printf("\n");
    return 0;
}
// F 初级魔法 2 //
// WA 乐 等会再查//
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t lll;
const lll maxn=1e7+5;
const lll mod=(lll)1<<64;
lll n,m;
lll read()
{
    lll f=1,x=0;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return f*x;
}
void write(lll x, char c = '\0') {
  if (x < 0) putchar('-'), x = -x;
  if (x > 9) write(x / 10);
  putchar(x % 10 + '0');
  if (c != '\0') putchar(c);
}
lll phi[maxn],sum[maxn],pri[maxn],cnt;bool isnp[maxn];
void linear(lll n)
{
    phi[1]=1,cnt=0,sum[0]=0,sum[1]=1;
    for(lll i=2;i<=n;++i)
    {
        if(!isnp[i])pri[++cnt]=i,phi[i]=i-1;
        for(lll j=1;j<=cnt&&i*pri[j]<=n;++j)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0)
            {
                phi[i*pri[j]]=phi[i]*pri[j]%mod;
                break;
            }
            else
                phi[i*pri[j]]=phi[i]*(pri[j]-1);
        }
        sum[i]=(sum[i-1]+phi[i])%mod;
    }
    return;
}
map<lll,lll> mp;
lll du_phi(lll n)
{
    if(n<maxn) return sum[n];
    if(mp.count(n)) return mp[n];
    lll res=n*(n+1)/2%mod;
    for(lll l=2,r;l<=n;l=r+1)
    {
        r=n/(n/l);
        res=(res-(r-l+1)*du_phi(n/l)%mod+mod)%mod;
    }
    return mp[n]=res;
}
lll qpow(lll x,lll power,lll mod)    // 改为ll power 可以省时间
{
    x=x%mod;
    lll ans=1;
    for(;power;power=power>>1,x=x*x%mod)
    {
        if(power&1) ans=ans*x%mod;
    }
    return ans;
}
int main(void)
{
    n=read(),m=read();
    linear(maxn-1);
    lll ans=0;
    for(lll r,l=1;l<=m;l=r+1)
    {
        r=m/(m/l);
        ans=(ans+qpow(m/l,n,mod)*((du_phi(r)-du_phi(l-1))%mod+mod)%mod)%mod;
    }
    write(ans);
    cout<<endl;
    return 0;
}
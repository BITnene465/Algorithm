#include<bits/stdc++.h>
using namespace std;
const int maxn=1005; 
// isnp 即 is_not_prime ; 设n最小质因子为p，p^k||n,mnp记录p^k的值 
int f[maxn],pri[maxn],mnp[maxn],cnt;bool isnp[maxn];
int calc(int n)   
{
    int id;
    for(int j=1;j<=cnt;j++)
    {
        if(n%pri[j]==0){id=j;break;}
    }
    int cnt=0;
    while(n%pri[id]==0)cnt++,n=n/pri[id];
    return pow(pri[id],cnt)-pow(pri[id],cnt-1);
}
void linear(int n)
{
    f[1]=1;cnt=0;   // 积性函数的f(1)=1,进行初始化 
    for(int i=2;i<=n;i++)
    {
        if(!isnp[i]){pri[++cnt]=i;mnp[i]=i;f[i]=calc(i);} // 此时，n=p
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
        {
            isnp[i*pri[j]]=true;
            if(i%pri[j]==0)
            {
                mnp[i*pri[j]]=mnp[i]*pri[j];   // 此时一定有pri[j]是i的最小素因子
                if(i==mnp[i])  // 此时，n=p^k形式
                    f[i*pri[j]]=calc(i*pri[j]);
                else
                    f[i*pri[j]]=f[i/mnp[i]]*f[mnp[i]*pri[j]];
                break;
            }
            else
            {
                mnp[i*pri[j]]=pri[j];
                f[i*pri[j]]=f[pri[j]]*f[i];
            }
        }
    }
}
int main(void)
{
    int n;
    cin>>n;
    linear(n);
    for(int i=1;i<=n;i++)
    {
        printf("f(%d)=%d ",i,f[i]);
        if(i%4==0)printf("\n");
    }
    return 0;
}
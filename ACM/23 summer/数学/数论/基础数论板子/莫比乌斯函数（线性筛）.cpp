#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
// ¿‡À∆”⁄≈∑¿≠…∏ //
int mu[maxn],pri[maxn],cnt;bool vis[maxn]; 
void linear_mu(int n)
{
    mu[1]=1;cnt=0;
    for(int i=2;i<=n;i++)
    {
        if(!vis[i]){pri[++cnt]=i;mu[i]=-1;}
        for(int j=1;j<=cnt&&i*pri[j]<=n;j++)
        {
            vis[i*pri[j]]=true;
            if(i%pri[j]==0){mu[i*pri[j]]=0;break;}
            else    mu[i*pri[j]]=-mu[i];
        }
    }
}
int main(void)
{
    int n;
    cin>>n;
    linear_mu(n);
    for(int i=1;i<=n;i++)
    {
        printf("mu(%d)=%d ",i,mu[i]);
        if(i%4==0)printf("\n");
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=305;
const double eps=1e-8;
int cnt[maxn];
int n,k,ans;
ll x[maxn],y[maxn];
int main(void)
{
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++)    scanf("%lld %lld",x+i,y+i);
    if(k==1){
        printf("Infinity\n");
        return 0;
    }
    else
    {
        double b,kk;
        for(int i=1;i<=n-1;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                kk=((double)y[i]-(double)y[j])/(x[i]-x[j]);
                b=y[i]-kk*x[i];
                int cnt2=2;
                for(int t=j+1;t<=n;t++)
                {
                    if(fabs(y[t]-kk*x[t]-b)<eps)  cnt2++;
                }
                cnt[cnt2]++;    // 含有cnt2个点的直线数量加一
            }
        }
        cout<<cnt[k]<<endl;
        return 0;
    }
}
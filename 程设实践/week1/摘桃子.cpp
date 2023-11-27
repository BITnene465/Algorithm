#include<cstdio>
const int maxn=3005;
int n,v,buc[maxn];
int ans;
int main(void)
{
    scanf("%d%d",&n,&v);
    for(int i=1;i<=n;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        buc[a]+=b;
    }
    ans=0;
    for(int i=1;i<=3001;++i)
    {
        if(v>buc[i-1]+buc[i])
        {
            ans+=buc[i-1]+buc[i];
            buc[i-1]=buc[i]=0;
            continue;
        }
        if(buc[i-1]+buc[i]<=v)
        {
            buc[i-1]=buc[i]=0;
            ans+=v;
            continue;
        }
        if(buc[i-1]<=v)
        {
            buc[i]=buc[i]+buc[i-1]-v;
            buc[i-1]=0;
            ans+=v;
            continue;
        }
        if(buc[i-1]>v)
        {
            buc[i-1]-=v;
            ans+=v;
            continue;
        }
    }
    printf("%d\n",ans);
    return 0;
}
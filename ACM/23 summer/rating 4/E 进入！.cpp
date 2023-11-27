#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
// 0-1字典树 
int nex[32*maxn][2],cnt;
void reset()
{
    cnt=0;
    memset(nex,0,sizeof(nex));
    return;
}
int find(int val)
{ 
    // 搜索可以和val异或得到的最大值 //
    int ans=0;
    int p=0;
    for(int i=(1<<30);i;i>>=1)
    {
        bool c=val&i;
        if(nex[p][!c])
        {//如果这一位可以进行异或就沿着这一条往下走
            ans+=i;
            p=nex[p][!c];
        }
        else p=nex[p][c];//否则就沿着另一条路往下走
    }
    return ans;
}
void insert(int val)
{
    // 插入
    int p=0;
    for(int i=(1<<30);i;i>>=1)
    {
        bool c=val&i;
        if(!nex[p][c])nex[p][c]=++cnt;
        p=nex[p][c];
    }
    return;
}
// 主函数
int pre_max[maxn],suf_max[maxn],a[maxn],sum[maxn],sum2[maxn];
int ans,n;
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr); 
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>a[i];
    sum[0]=sum2[0]=0;
    for(int i=1;i<=n;++i)
        sum[i]=a[i]^sum[i-1],sum2[i]=sum2[i-1]^a[n+1-i];
    // 字典树操作
    insert(0);
    pre_max[0]=suf_max[n+1]=0;
    for(int i=1;i<=n;++i)
    {
        pre_max[i]=max(pre_max[i-1],find(sum[i]));
        insert(sum[i]);
    }
    reset();
    insert(0);
    for(int i=1;i<=n;++i)
    {
        suf_max[i]=max(suf_max[i-1],find(sum2[i]));
        insert(sum2[i]);
    }
    // 
    ans=0;
    for(int i=1;i<=n;++i)
    {
        ans=max(ans,pre_max[i]+suf_max[n-i]);
    }
    cout<<ans<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
int n,k,m,ans[maxn],nxt[maxn],pre[maxn];   // 用整数指针实现双向链表
bool check(int n,int k,int m)
{
    // cout<<n<<' '<<k<<' '<<m<<endl;
    if(n<1||m<1||k<1){cout<<"n,m,k must bigger than 0."<<endl;return 0;}
    if(k>n){cout<<"k should not bigger than n."<<endl;return 0;}
    return 1;
}
void init(int n)
{
    for(int i=1;i<=n-1;++i)nxt[i]=i+1;
    nxt[n]=1;
    for(int i=n;i>=2;--i)pre[i]=i-1;
    pre[1]=n;
    return;
}
void playgame(int n,int k,int st,int* ans)
{
    int siz = 0;
    int now = st;
    while(siz<n)
    {
        int cnt=0;
        while(++cnt<k)now=nxt[now];
        int tmp=pre[now];
        pre[nxt[now]]=tmp;
        nxt[tmp]=nxt[now];
        ans[++siz]=now;
        now=nxt[now];   // 及时更新
    }
    return;
}
void print_ans(int n,int* ans)
{
    for(int i=1;i<=n-1;++i)
    {
        if(i%10==0) cout<<ans[i]<<'\n';
        else        cout<<ans[i]<<' ';
    }
    cout<<ans[n]<<endl;
    return;
}
int main(void)
{
    char tmp;
    cin>>n>>tmp;
    cin>>k>>tmp;
    cin>>m;
    if(!check(n,k,m))return 0;
    init(n);
    playgame(n,m,k,ans);
    print_ans(n,ans);
    return 0;
}
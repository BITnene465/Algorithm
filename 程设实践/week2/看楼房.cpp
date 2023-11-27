// 维护一个单调栈，以高度为判断基准 //
// 时间复杂度 O(Tn) T为询问次数 //
#include<bits/stdc++.h>
using namespace std;
const int maxc=1e6+5;
const int maxn=1e6+5;
int cnum,n,T,color[maxc],h[maxn],stk[maxn],top,buc_c[maxc];   // buc_c来存当前栈内的颜色数量
void solve()
{
    // init //
    memset(buc_c,0,sizeof(buc_c));
    top=0;
    //
    int type=0;
    for(int cur=1;cur<=n;++cur)
    {
        while(top&&h[stk[top]]<=h[cur]){if(--buc_c[color[stk[top]]]==0) --type;--top;}
        stk[++top]=cur;
        if(++buc_c[color[stk[top]]]==1)++type;
        if(cur<n)cout<<type<<' ';
        else cout<<type<<'\n';
    }
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>T;
    while(T--)
    {
        cin>>n;
        for(int i=1;i<=n;++i)cin>>color[i];
        for(int i=1;i<=n;++i)cin>>h[i];
        solve();
    }
    return 0;
}
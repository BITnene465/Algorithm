// 枚举第一行的操作情况，2^m种情况 ; 然后每一行开着的灯，只能由下一行的操作来改变，从而下面的策略已经固定//
#include<bits/stdc++.h>
using namespace std;
int n,m;
int st[20][20];   //状态图，状态压缩
int tmp[20][20];
int ans,cnt;
string s;
bool solve()
{
    memcpy(tmp,st,sizeof st);
    for(int i=2;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(tmp[i-1][j]){tmp[i][j-1]^=1;tmp[i][j]^=1;tmp[i][j+1]^=1;tmp[i+1][j]^=1;tmp[i-1][j]^=1;cnt++;}
    for(int j=1;j<=m;++j)if(tmp[n][j])return 0;
    return 1;
}
void dfs(int x,int c)
{
    if(x==m+1)
    {
        cnt=c;
        if(solve())ans=min(ans,cnt);
        return;
    }
    st[1][x-1]^=1;st[2][x]^=1;st[1][x+1]^=1;st[1][x]^=1;
    dfs(x+1,c+1);    // 操作x
    st[1][x-1]^=1;st[2][x]^=1;st[1][x+1]^=1;st[1][x]^=1;
    dfs(x+1,c);    // 不操作x
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        for(int j=0;j<m;++j)if(s[j]=='1')st[i][j+1]=1;
    }
    ans=10000000;
    dfs(1,0);
    cout<<ans<<endl;
    return 0;
}
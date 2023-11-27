#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll ex,ey,cx,cy,dp[25][25];
bool vis[25][25];
const ll dx[]={1,2,2,1,-1,-2,-2,-1};
const ll dy[]={2,1,-1,-2,-2,-1,1,2};
ll p[8][2];
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>ex>>ey>>cx>>cy;
    dp[0][0]=1;
    for(ll i=0;i<8;++i)p[i][0]=cx+dx[i],p[i][1]=cy+dy[i];
    for(ll i=0;i<8;++i)
    {
        if(p[i][0]>=0&&p[i][0]<=ex&&p[i][1]>=0&&p[i][1]<=ey)vis[p[i][0]][p[i][1]]=1;
    }
    vis[cx][cy]=1;
    if(vis[0][0]){cout<<'0'<<endl;return 0;}
    // dp[i][0]
    for(ll i=1;i<=ex;++i)
    {
        if(vis[i][0])dp[i][0]=0;
        else        dp[i][0]=dp[i-1][0];
    }
    // dp[0][j]
    for(ll j=1;j<=ey;++j)
    {
        if(vis[0][j])dp[0][j]=0;
        else        dp[0][j]=dp[0][j-1];
    }
    // dp
    for(ll i=1;i<=ex;++i)
    {
        for(ll j=1;j<=ey;++j)
        {
            if(vis[i][j])dp[i][j]=0;
            else    dp[i][j]=dp[i-1][j]+dp[i][j-1];
        }
    }
    cout<<dp[ex][ey]<<endl;
    return 0;
}
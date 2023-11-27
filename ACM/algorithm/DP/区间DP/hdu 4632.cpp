// hdu 4632 "Palindrome Subsequence" //
// 区间DP //
// TLE版本 ， 记忆化搜索虽然时间复杂度和循环版一样，但是常数过高，导致超时//
#include<bits/stdc++.h>
using namespace std;
int T;
int dp[1001][1001];
char s[1002];
const int mod = 10007;
int ans[51];
int dfs(int i,int j)
{
    if(i>j) return 0;
    else if(i==j)    return 1;
    else if(dp[i][j]>0) return dp[i][j];
    else 
    {
        if(s[i]==s[j])
        return dp[i][j] = (dfs(i,j-1)+dfs(i+1,j)+1)%mod;  //这个1十分关键
        else
        return dp[i][j] = (dfs(i,j-1)+dfs(i+1,j)-dfs(i+1,j-1))%mod;
    }
}
int main(void)
{
    cin>>T;
    for(int i=1;i<=T;i++)
    {
        scanf("%s",s);
        memset(dp,0,sizeof(dp));
        int len = strlen(s);
        ans[i] = dfs(0,len-1);
    }
    // print
    for(int i=1;i<=T;i++)
        printf("Case %d: %d\n",i,ans[i]);
    return 0;
}
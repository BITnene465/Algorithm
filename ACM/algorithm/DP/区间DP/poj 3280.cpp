// poj 3280 "Cheapest Palindrome" //
// 区间DP ， 回文串 //
#include<bits/stdc++.h>
using namespace std;
char s[2100];
int dp[2100][2100];
int n,m;      // 有n个不同的小写字母，长度为m的字符串
int cost[100];   // add & del 效果相同，贪心取最小代价的操作即可
int dfs(int i,int j)
{
    if(j<=i)    return 0;
    else if(dp[i][j]>0) return dp[i][j];
    else if(s[i]==s[j]) return dp[i][j] = dfs(i+1,j-1);
    else    return dp[i][j] = min(dfs(i+1,j)+cost[s[i]],dfs(i,j-1)+cost[s[j]]);
}
int main(void)
{
    cin>>n>>m;
    cin>>s;
    int x,y;
    char ch;
    for(int i=0;i<n;i++)
    {
        cin>>ch>>x>>y;
        cost[ch] = min(x,y);
    }
    cout<<dfs(0,m-1)<<endl;
    return 0;
}
/*
sample:
3 4
abcb
a 1000 1100
b 350 700
c 200 800

ans = 900
*/
// DP解决LCH //
#include<bits/stdc++.h>
using namespace std;
const int MaxLength = 1001;
string str1,str2;
// 滚动数组作为dp
int dp[2][MaxLength];
int solve()
{
    memset(dp,0,sizeof(dp));
    for(int i=1;i<=str1.length();i++)
    {
        for(int j=1;j<=str2.length();j++)
        {
            if(str1[i-1]==str2[j-1])
                dp[i%2][j] = dp[(i+1)%2][j-1]+1;
            else
                dp[i%2][j] = max(dp[(i+1)%2][j],dp[i%2][j-1]); 
        }
    }
    return  dp[str1.length()%2][str2.length()];    
}
int main(void)
{
    getline(cin,str1);
    getline(cin,str2);
    cout<<solve()<<endl; 
    return 0;  
}
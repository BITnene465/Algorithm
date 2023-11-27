#include<bits/stdc++.h>
using namespace std;
const int MaxLength = 1001;
string str1,str2;
struct point{
    int x;
    int y;
}path[MaxLength][MaxLength];    // 用来记录转移路径
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
            {
                dp[i%2][j] = dp[(i-1)%2][j-1]+1;
                path[i][j].x = i-1;
                path[i][j].y = j-1;
            }
            else
            {
                if(dp[(i-1)%2][j]>dp[i%2][j-1])
                {
                    dp[i%2][j] = dp[(i-1)%2][j];
                    path[i][j].x = i-1;
                    path[i][j].y = j;
                }
                else
                {
                    dp[i%2][j] = dp[i%2][j-1];
                    path[i][j].x = i;
                    path[i][j].y = j-1;
                }
            } 
        }
    }
    return  dp[str1.length()%2][str2.length()];    
}
void print_path()
{
    int x,y;
    x = str1.length();
    y = str2.length();
    string varT;
    while(x&&y)
    {
        if(str1[x-1]==str2[y-1])
        varT.push_back(str1[x-1]);
        //
        x = path[x][y].x;
        y = path[x][y].y;
    }
    reverse(varT.begin(),varT.end());    // c++string的翻转
    cout<<"一个符合题意的公共子序列为:\n"<<varT<<endl;
}
int main(void)
{
    getline(cin,str1);
    getline(cin,str2);
    cout<<solve()<<endl; 
    print_path();
    return 0;  
}
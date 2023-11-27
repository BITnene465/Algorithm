#include<bits/stdc++.h>
using namespace std;
const int maxLength = 1001;
int arr[maxLength];
int dp[maxLength];
int path[maxLength];
int N;    // 数组长度
int index_i;
void solve()
{
    memset(dp,0,sizeof(dp));   // 最主要的是dp[0]=0
    for(int i=1;i<=N;i++)
    {
        int index;
        index = 0;
        // 找到a[0]~a[i-1]中小于arr[i]的dp最大数的索引 //
        for(int j=1;j<i;j++)
        {
            if(dp[index]<dp[j]&&arr[i]>=arr[j])
                index = j;
        }
        dp[i] = dp[index] + 1;
        path[i] = index;
    }
    //找出最大的dp
    index_i = 0;
    for(int i=1;i<=N;i++)
    {
        if(dp[i]>dp[index_i])
            index_i = i;
    }
}
void print_path()
{
    int i = index_i;
    vector<int> t;
    while(i)
    {
        t.insert(t.begin(),arr[i]);
        i = path[i];
    }
    cout<<"一个最长的递增子序列为："<<endl;
    for(auto it:t)
        cout<<it<<" ";
    cout<<endl;
}
int main(void)
{
    while(cin>>N)
    {
        arr[0] = INT_MIN;    //哨兵
        for(int i=1;i<=N;i++)
            cin>>arr[i];
        solve();
        cout<<dp[index_i]<<endl;
        print_path();
    }
    return 0;
}
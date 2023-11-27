// 错误的思路 //
// WWWWWWWWWW //
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,v[maxn];  // v数组记录每个括号序列的左括号数-右括号数 
string s;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        int l=(int)s.length();
        v[i]=0;
        for(int j=0;j<l;++j)
        {
            if(s[j]=='(') ++v[i];
            else --v[i];
        }
    }
    // 然后转换为两数之和为0的配对数求解 时间复杂度O(nlogn) //
    sort(v+1,v+1+n);
    int i=1,j=n;   // 双指针 , 时间复杂度O(n) //
    while(i<j)
    {
        if(v[i]+v[j]==0)++ans,++i,--j;
        else if(v[i]+v[j]>0)--j;
        else ++i;
    }
    cout<<ans<<endl;
    return 0;
}
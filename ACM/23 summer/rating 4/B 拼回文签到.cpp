#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+5;
int ans,t,d1[maxn],d2[maxn];
string s;
// 字符串s,长度n,两个数组d1[],d2[]
void manacher(string s,int n,int d1[],int d2[])
{
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])    ++k;
        d1[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k+1;}
        // 更新最大值
        if(i-k+1==0||i+k==n)ans=max(ans,2*k-1);
    }
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-1-k>=0&&i+k<n&&s[i+k]==s[i-1-k])    ++k;
        d2[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k;}
        // 更新最大值
        if(i-k==0||i+k==n)ans=max(ans,2*k);
    }
    return;
}
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--)
    {
        cin>>s;
        int idx=0;
        int l=(int)s.length();
        while(idx<l-1-idx&&s[idx]==s[l-1-idx])idx++;
        int l2=l-2*idx;
        ans=0;
        manacher(s.substr(idx,l2),l2,d1,d2);
        ans=ans+2*idx;
        cout<<ans<<endl;
    }
    return 0;
}
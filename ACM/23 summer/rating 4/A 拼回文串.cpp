#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
int ans,t,flag,d1[maxn],d2[maxn];
string s,tmp;
// 字符串s,长度n,两个数组d1[],d2[]
void manacher(string s,int n,int d1[],int d2[])
{
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])    ++k;
        d1[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k+1;}
        //
        if(i-d1[i]+1==0&&ans<2*d1[i]-1)ans=2*d1[i]-1,flag=1;
        else if(i+d1[i]==n&&ans<2*d1[i]-1)ans=2*d1[i]-1,flag=2;
    }
    for(int i=0,l=0,r=-1;i<n;++i)
    {
        int k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-1-k>=0&&i+k<n&&s[i+k]==s[i-1-k])    ++k;
        d2[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k;}
        //
        if(i-d2[i]==0&&ans<2*d2[i])ans=2*d2[i],flag=1;
        else if(i+d2[i]==n&&ans<2*d2[i])ans=2*d2[i],flag=2;
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
        if(flag==1)tmp=s.substr(0,idx+ans)+s.substr(l-idx,idx);
        else if(flag==2)tmp=s.substr(0,idx)+s.substr(l-ans-idx,ans+idx);
        cout<<tmp<<endl;
    }
    return 0;
}
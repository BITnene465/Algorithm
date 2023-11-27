// ce //
#include<bits/stdc++.h>
using namespace std;
typedef unsigned int uin;
typedef vector<uin> vei;
const uin maxn=3e6+5;
uin n,m,d1[maxn],d2[maxn],a[maxn],sum0[maxn],sum1[maxn];
vei id;   // 记录所有字符串匹配的位置
string s1,s2;
vei kmp_find(string t,string s,uin n,uin m)
{
    string cur=s+'#'+t;
    vei pi(n+m+1);
    for(uin i=1;i<=n+m+1;++i)
    {
        uin j=pi[i-1];
        while(j>0&&cur[i]!=cur[j])j=pi[j-1];
        if(cur[i]==cur[j])++j;
        pi[i]=j;
    }
    vei v;
    for(uin i=m+1;i<=n+m;++i)
        if(pi[i]==m)v.push_back(i-2*m);
    return v;
}
void manacher(string s,uin n)
{
    for(uin i=0,l=0,r=-1;i<n;++i)
    {
        uin k=(i>r)?1:min(r-i+1,d1[r+l-i]);
        while(i-k>=0&&i+k<n&&s[i-k]==s[i+k])++k;
        d1[i]=k;
        if(i+k-1>r)r=i+k-1,l=i-k+1;
    }
    for(uin i=0,l=0,r=-1;i<n;++i)
    {
        uin k=(i>r)?0:min(r-i+1,d2[r+l-i]);
        while(i-1-k>=0&&i+k<n&&s[i-1-k]==s[i+k])++k;
        d2[i]=k;
        if(i+k-1>r){r=i+k-1;l=i-k;}
    }
    return;
}
// 预处理前缀和 //
void pre(int n)
{
    for(auto i:id)
        a[i]=1;
    sum0[0]=sum1[0]=0;
    for(uin i=1;i<n;++i)
    {
        sum0[i]=sum0[i-1]+a[i];
        sum1[i]=sum1[i-1]+i*a[i];
    }
    return;
}
uin get_sum(uin l,uin r)
{
    r=r-m+1;
    if(l>r)return (uin)0;
    uin mid=r+l>>1;
    return sum1[mid]-sum1[l-1]-(l-1)*(sum0[mid]-sum0[l-1])+(r+1)*(sum0[r]-sum0[mid])-(sum1[r]-sum1[mid]);
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>n>>m;
    cin>>s1>>s2;
    id=kmp_find(s1,s2,n,m);
    manacher(s1,n);
    pre(n);
    //  开始求区间和
    uin ans=(uin)0;
    for(uin i=0;i<n;++i)
    {
        uin r=i+d1[i]-1,l=i-d1[i]+1;
        ans+=get_sum(l,r);
        r=i+d2[i]-1,l=i-d2[i];
        ans+=get_sum(l,r);
    }   
    cout<<ans<<endl;
    return 0;
}
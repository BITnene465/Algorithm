#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vei;
vei prefix_func(string s)
{
    int n=(int)s.length();
    vei pi(n);
    for(int i=1;i<n;++i)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])++j;
        pi[i]=j;
    }
    return pi;
}
vei kmp_find(string t,string s)
{
    int l1=(int)t.length();
    int l2=(int)s.length();
    string cur=s+'#'+t;
    vei pi=prefix_func(cur);
    vei v;
    for(int i=l2+1;i<=l1+l2;++i)
        if(pi[i]==l2)v.push_back(i-2*l2);
    return v;
}
int main(void)
{
    string s,t;
    cin>>t>>s;
    vei pi=prefix_func(s);
    int n=(int)s.length();
    vei index=kmp_find(t,s);
    for(auto it:index)
        printf("%d\n",it+1);
    for(int i=0;i<n;i++)
        printf("%d%c",pi[i],(i==n-1)?'\n':' ');
    return 0;
}
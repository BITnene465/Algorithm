#include<bits/stdc++.h>
using namespace std;
vector<int> prefix_func(string s)
{
    int n=(int)s.length();
    vector<int> pi(n);   // 最大容量是n,全部用0初始化
    for(int i=1;i<n;++i)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j])j=pi[j-1];
        if(s[i]==s[j])  ++j;
        pi[i]=j;
    }
    return pi;
}
vector<int> kmp_find(string t,string s)
{
    int sz1=(int)t.length(),sz2=(int)s.length();
    string cur = s+'#'+t;
    vector<int> id;
    vector<int> pi=prefix_func(cur);
    for(int i=sz2+1;i<=sz1+sz2;++i)
        if(pi[i]==sz2)  id.push_back(i-2*sz2);
    return id;
}
int main(void)
{
    string t,s;
    cin>>t;
    cin>>s;
    cout<<"t="<<t<<endl;
    cout<<"s="<<s<<endl;
    vector<int> index=kmp_find(t,s);
    int sz2=(int)s.length();
    for(auto it:index)
        cout<<"index="<<it<<" "<<t.substr(it,sz2)<<endl;
    return 0;
}   
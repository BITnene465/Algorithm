#include<bits/stdc++.h>
using namespace std;
string s;
set<string> ss;
int n;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        if(s.length()>=11)ss.insert(s);
    }
    cout<<ss.size()<<endl;
    return 0;
}
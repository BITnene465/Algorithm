#include<bits/stdc++.h>
using namespace std;
int n,k;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>k;
    if(k>n-1){cout<<"-1"<<endl;return 0;}
    cout<<n-k<<' ';
    for(int i=2;i<=n-k;++i)cout<<i-1<<' ';
    for(int i=n-k+1;i<=n;++i)cout<<i<<' ';
    cout<<endl;
    return 0;
}
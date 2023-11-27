#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll T,n;
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>T;
    while(T--)
    {
        cin>>n;
        cout<<ceil(log2(n))<<endl;
    }
    return 0;
}
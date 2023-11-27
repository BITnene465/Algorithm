// °å×Ó //
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll D[21];
ll n;
int main(void)
{
    cin>>n;
    D[0]=1,D[1]=0;
    for(ll i=2;i<=n;i++)
        D[i]=(i-1)*(D[i-1]+D[i-2]);
    cout<<D[n]<<endl;
    return 0;
}
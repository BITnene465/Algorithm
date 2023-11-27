#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll s1, s2, n, arr[500005], vis[500005];
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin>>n>>s1>>s2;
    for(ll i=1;i<=n;++i) cin>>arr[i];
    sort(arr+1, arr+n+1);
    int cur1 = 1;
    int cur2 = 1;
    while(1)
    {
        bool flag1=0, flag2=0;
        while(s1>arr[cur1+1]||vis[cur1])cur1++;
        if(s1>arr[cur1]){
            s1 += arr[cur1];
            vis[cur1] = 1;
            flag1 = 1;
        }
        while (s2 > arr[cur2 + 1] || vis[cur2])cur2++;
        if (s2 > arr[cur2])
        {
            s2 += arr[cur2];
            vis[cur2] = 1;
            flag2 = 1;
        }
        if(!flag1 && !flag2) break;
    }
    
}
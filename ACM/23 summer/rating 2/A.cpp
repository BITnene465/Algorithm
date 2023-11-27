#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,q,l,r,id,fa[maxn];
int query(int l,int r,int id)
{
    int cnt=0;
    for(int i=l;i<=r;i++)
    {
        if(fa[i]==id)   cnt++;
        fa[i]=id;
    }
    return cnt;
}
int main(void)
{
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>fa[i];
    while(cin>>l>>r>>id)
    {
        printf("%d\n",query(l,r,id));
    }
    return 0;
}
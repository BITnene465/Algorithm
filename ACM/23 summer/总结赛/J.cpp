#include<bits/stdc++.h>
using namespace std;
typedef  long long ll;
const ll maxn=1e7+5;
ll n,m;
ll s[maxn],sum[maxn];
vector<ll> son[maxn];
void init(ll n)
{
    for(ll i=1;i<=n;++i)
        s[i]=sum[i]=i,son[i].clear();
}
ll Find(ll p)
{
    if(s[p]!=p)p=s[p];
    return p;
}
ll Union(ll p,ll q)
{
    p=Find(p),q=Find(q);
    if(p==q)return;   // ²»²Ù×÷
    s[p]=q;son[q].push_back(p);
    sum[q]=sum[q]+sum[p];
    sum[p]=0;
}
void Move(ll p,ll q)
{
    q=Find(q);ll t=Find(p);ll tt;
    if(q==t)return;
    if(son[p].size())
    {
        if(s[p]==p)tt=s[son[p][0]]=son[p][0];
        else tt=s[son[p][0]]=s[p];
        for(int i=1;i<son[p].size();++i)s[son[p][i]]=son[p][0];
        ll r=Find(tt);
        sum[r]-=p;
        sum[p]=0;
        son[p].clear();
        s[p]=q;
        sum[q]+=p;
        return;
    }
    sum[t]-=p;
    sum[p]=0;
    sum[q]+=p;
    s[p]=q;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while(cin>>n>>m)
    {
        init(n);
        int flag,p,q;
        while(m--)
        {
            cin>>flag;
            if(flag==1)
            {
                cin>>p>>q;
                Union(p,q);
            }
            else if(flag==2)
            {
                cin>>p;
                Move(p,q);
            }
            else 
            {
                cin>>p;
                cout<<sum[Find(p)];
            }
        }
    }
}

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll f[maxn][26];
ll g[26][26];
vector<int> idx[26];
char s[maxn];
int main(void)
{
    ll ans=0;
    scanf("%s",s);
    int l=strlen(s);
    for(int i=1;i<=l;++i)
    {
        int c=s[i-1]-'a';
        idx[c].push_back(i);
        for(int j=0;j<c;++j)
            f[i][j]=f[i-1][j];
        f[i][c]=f[i-1][c]+1;
        for(int j=c+1;j<26;++j)
            f[i][j]=f[i-1][j];
    }
    for(int i=0;i<26;++i)
    {
        for(int j=0;j<26;++j)
        {
            int tt=idx[j].size();
            for(int t=tt-1;t>=0;--t)
            {
                g[i][j]+=f[idx[j][t]-1][i];
            }
            ans=max(ans,g[i][j]);
        }
    }
    cout<<ans<<endl;
    return 0;
}
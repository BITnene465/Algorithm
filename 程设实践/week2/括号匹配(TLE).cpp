#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,ans,stk[maxn],top,L[maxn],R[maxn];  // L记录有多少没被匹配的左括号，R同理
bool vis[maxn];
string s;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        cin>>s;
        int l=(int)s.length();
        top=0;
        for(int j=0;j<l;++j)
        {
             if(top&&s[stk[top]]=='('&&s[j]==')')--top;
            else stk[++top]=j;
        }
        L[i]=R[i]=0;
        for(int j=1;j<=top;++j){if(s[stk[j]]=='(') ++L[i];else ++R[i];}
    }
    // 要想两个串配对之后能够匹配：L[i]==R[j]&&L[j]==R[i]==0  或 L[i]==R[j]==0&&L[j]==R[i]  //
    // 此处时间复杂度为 O(n^2) 导致TLE //
    ans=0;
    for(int i=1;i<=n-1;++i)
    {
        if((L[i]&&R[i])||vis[i])continue;
        if(R[i]==0)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(vis[j])continue;
                if(R[j]==L[i]&&L[j]==0){++ans;vis[i]=vis[j]=1;break;}
            }
        }
        else if(L[i]==0)
        {
            for(int j=i+1;j<=n;++j)
            {
                if(vis[j])continue;
                if(R[i]==L[j]&&R[j]==0){++ans;vis[i]=vis[j]=1;break;}
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}
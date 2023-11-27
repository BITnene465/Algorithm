// 用桶存，总的时间复杂度为O(n) //
#include<bits/stdc++.h>
using namespace std;
const int maxL=1e5+5;
typedef long long ll;
int n,stk[maxL],top;
ll ans;
int buc_L[maxL],buc_R[maxL];
string s;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    int cnt=0;   // 记录本身就合法的字符串
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
        int L=0,R=0;
        for(int j=1;j<=top;++j){if(s[stk[j]]=='(') ++L;else ++R;}
        if(R&&L)continue;    // 这种字符串和谁配都不合法
        if(R==0&&L==0){cnt++;}
        else if(R>0)++buc_R[R];
        else if(L>0)++buc_L[L];
    }
    ans=(ll)cnt/2;
    for(int i=1;i<=maxL-1;++i) ans+=(ll)min(buc_L[i],buc_R[i]);
    cout<<ans<<endl;
    return 0;
}
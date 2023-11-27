#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],stk[maxn],top;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
        for(int i=1;i<=n;++i)cin>>a[i],a[i]%=2;   // 只要看mod2的余数即可
        top=0;
        for(int i=1;i<=n;++i)
        {
            if(!top||a[i]!=stk[top])stk[++top]=a[i];
            else    --top;
        }
        if(top==0||top==1)cout<<"YES"<<endl;   // 最后剩下数超过1个，则一定没法填满
        else cout<<"NO"<<endl;
    }
    return 0;
}
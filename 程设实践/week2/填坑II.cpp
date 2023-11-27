#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
int n,a[maxn],stk[maxn],top;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    while(cin>>n)
    {
        int ma=0;
        for(int i=1;i<=n;++i)cin>>a[i],ma=max(ma,a[i]);
        top=0;stk[0]=1e9+5;
        for(int i=1;i<=n;++i)
        {
            if(top&&stk[top]==a[i]&&stk[top-1]>=a[i])--top;    // 还得保证前一个元素不小于a[i],否则也填不满（其实这里可以直接break输出no了）
            else stk[++top]=a[i];
        }
        if(top==0||(top==1&&ma==stk[top]))cout<<"YES"<<endl;   // 最后剩下数超过1个，则一定没法填满; 如果剩下一个，若不是最高点，也不能填满
        else cout<<"NO"<<endl;
    }
    return 0;
}
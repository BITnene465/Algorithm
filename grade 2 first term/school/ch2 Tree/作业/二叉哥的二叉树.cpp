// 没想到，竟然还不会写捏 //
// 看大佬题解，溜了溜了 //
#include<bits/stdc++.h>
using namespace std;
int T, ans;
void Dfs(int n, int m)
{
    if(n<m+1)return;   // 前m层每层只放一个都不够
    if(n==m+1){
        ans++;
        return;
    }
    int cur=1;  // 记录当前的层数
    n = n-m-1;
    ans++;
    if(n==0||cur>m)return;
    int need=1<<cur-1;
    while(n-need>0){    // 还没放满
        ans+=1<<cur-1;
        n-=need;
        cur++;
        need = 2*need+1;
        if(cur>m)return;
    }
    if(n-need==0){   // 刚好放满
        ans+=1<<cur-1;
        return;
    }
    else Dfs(n, cur-1);
}
int main(void)
{
    cin>>T;
    while(T--)
    {
        int n,m;
        cin>>n>>m;
        ans = 0;
        Dfs(n, m);
        cout<<ans<<endl;
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int a[1000005],f[1000005];  
int n;
int s[1000005],top = -1;  //实现栈
struct node{
    int id;
    int nge;
    bool operator>(const node& a) const { return nge > a.nge; };
};
priority_queue<node,vector<node>,greater<node>> q;
int main(void){
    cin>>n;
    for(int i=1;i<=n;i++)
        scanf("%d",a+i);
    // 单调栈
    for(int i=1;i<=n;i++)
        f[i] = n+1;   
    top = -1;
    for(int cur=1;cur<=n;cur++)
    {
        while(top!=-1&&a[cur]>=a[s[top]])    f[s[top--]]=cur;
        s[++top] = cur;      
    }
    //for(int i=1;i<=n;i++)
        // printf("f[%d]=%d\n",i,f[i]);
    //
    int ans = 0;
    for(int k=1;k<=n;k++)
    {
        while(!q.empty()&&q.top().nge<=k){
            ans = ans^q.top().id;
            // printf("%d弹出\n",q.top().id);
            q.pop();
        }
        ans = ans^k;
        q.push({k,f[k]});
        // printf("%d入队\n",k);
        printf("%d\n",ans);
    }
    return 0;
}
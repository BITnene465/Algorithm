// 用整数作为索引构建双向链表，某种程度上提高贪心的效率 //
// 大部分时候时间复杂度在 O(nlog)  但是可以被卡 //
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+5;
char s1[maxn],s2[maxn];
int n, arr[maxn], nxt[maxn], pre[maxn], cnt,  first, ans;
bool vis[maxn];
int main(void)
{
    scanf("%d",&n);
    getchar();
    scanf("%s",s1+1);
    scanf("%s",s2+1);
    // puts(s1);
    // puts(s2);
    cnt = 0;
    int cnt0=0,cnt1=0;
    for(int i=1;i<=n;++i){  // 使用arr数组记录有用信息
        if(s1[i]==s2[i])continue;
        else if(s1[i]=='b')arr[++cnt]=1,++cnt1;
        else arr[++cnt]=0,++cnt0;
    }
    // for(int i=1;i<=cnt;++i)printf("%d",arr[i]);
    // printf("\n");
    for(int i=1;i<=cnt-1;++i){
        nxt[i] = i+1;
        pre[i+1] = i;
    }
    nxt[cnt] = 0;
    pre[1] = 0;
    first = 1;
    // 现在只要处理arr数组即可
    if(cnt0!=cnt1){printf("-1\n");return 0;}
    int cnt2 = 0;
    while(cnt > cnt2){
        int last = first;
        int tmp = 0;
        for(int i=nxt[last];i;i=nxt[i]){
            if(!vis[i]&&arr[last]!=arr[i]){
                // 删除last
                nxt[pre[last]] = nxt[last];
                pre[nxt[last]] = pre[last];
                pre[last] = nxt[last] = 0;
                //
                vis[last] = 1;
                last = i;
                tmp++;
            }
        }
        if(tmp%2==1){
            tmp++;
            nxt[pre[last]] = nxt[last];
            pre[nxt[last]] = pre[last];
            pre[last] = nxt[last] = 0;
            vis[last] = 1;
        }
        cnt2 += tmp;
        // 更新first
        while(vis[first])++first;
        // 更新ans
        ans++;
    }
    printf("%d\n",++ans);
    return 0;
}
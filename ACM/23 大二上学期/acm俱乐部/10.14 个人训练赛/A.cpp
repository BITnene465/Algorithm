#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,days[100005];
struct node{
    ll st,ed;
} act[100005];
bool mycmp(node a,node b){
    return a.st < b.st;
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d %d",&act[i].st,&act[i].ed);
    }
    scanf("%d",&m);
    for(int i=1;i<=m;++i){
        scanf("%d",days+i);
    }
    sort(act+1, act+1+n, mycmp);
    // Ì°ÐÄ
    ll cnt = 0;
    int j = 1, i = 1;
    while(i<=m&&j<=n){
        if(act[j].st <= days[i]){
            if(days[i] <= act[j].ed){
                cnt++;
                j++;
                continue;
            }
            else {
                j++;
                continue;
            }
        }
        else {
            i++;
            continue;
        }
    }
    printf("%lld\n",cnt);
    return 0;
}
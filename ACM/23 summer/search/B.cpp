#include<bits/stdc++.h>
using namespace std;
int n,m,a,b;  // n行m列，a个感染源，b个领主
struct node{
    int x,y;
}pos[100005];
int dis[100005];
int main(void)
{
    cin>>n>>m>>a>>b;
    int t1,t2;
    for(int i=1;i<=a;i++)
        scanf("%d %d",&pos[i].x,&pos[i].y);
    for(int i=1;i<=b;i++)
    {
        scanf("%d %d",&t1,&t2);
        dis[i] = 1e8;
        for(int k=1;k<=a;k++)
            dis[i] = min(dis[i],abs(pos[k].x-t1)+abs(pos[k].y-t2));
    }
    for(int i=1;i<=b;i++)
        printf("%d\n",dis[i]);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int n,T;
struct node{
    int t;
    int b;
} task1[100005],task2[100005];
bool cmp1(node &x,node &y)
{
    return x.t<=y.t;
}
bool cmp2(node &x,node &y)
{
    return (x.b+x.t)>=(y.b+y.t);
}
int main(void)
{
    int q;
    scanf("%d",&q);
    while(q--)
    {
        scanf("%d %d",&n,&T);
        int j = 0;
        int k = 0;
        int b,t;
        for(int i=1;i<=n;i++)
        {
            scanf("%d %d",&t,&b);
            if(b<0) task2[++k].b = b,task2[k].t = t;
            else    task1[++j].b = b,task1[j].t = t;
        }
        // ¸øÈÎÎñÅÅÐò
        sort(task1+1,task1+j+1,cmp1);
        sort(task2+1,task2+k+1,cmp2);
        bool out = false;
        for(int i=1;i<=j;i++)
        {
            if(T<=task1[i].t)
            {
                printf("-1s\n");
                out = true;
                break;
            }
            T+=task1[i].b;
        }
        if(out) continue;
        for(int i=1;i<=k;i++)
        {
            if(T<=task2[i].t)
            {
                printf("-1s\n");
                out = true;
                break;
            }
            T+=task2[i].b;
        }
        if(out) continue;
        if(T<=0)    printf("-1s\n");
        else    printf("+1s\n");
    }
    return 0;
}
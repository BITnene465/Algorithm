#include<bits/stdc++.h>
using namespace std;
struct node{
    int id;
    int t;
}a[1001];
int n;
bool cmp(node x,node y)
{
    return x.t<y.t;
}
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].t);
        a[i].id = i;
    }
    sort(a+1,a+n+1,cmp);
    double sum = 0.;
    int T =0;
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i].id);
        sum+= T;
        T+= a[i].t;
    }
    printf("\n%.2lf\n",sum/n);
    return 0;
}
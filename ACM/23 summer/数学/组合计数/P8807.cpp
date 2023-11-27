// P8807 ȡģ //
#include<bits/stdc++.h>
using namespace std;
int n,m,q;
bool check(int n,int m)
{
    for(int x=2;x<=m;x++)   if(n%x^x-1) return true;
    return false;
}
int main(void)
{
    cin>>q;
    while(q--)
    {
        scanf("%d %d",&n,&m);
        if(check(n,m))  printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
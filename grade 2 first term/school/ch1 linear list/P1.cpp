#include<cstdio>
#include<iostream>
using namespace std;
int a[1005],n,val;
int main(void)
{
    cin>>n;
    for(int i=1;i<=n;++i)cin>>a[i];
    int p1=1,p2=n;
    cin>>val;
    while(a[p2]==val&&p2>p1)p2--;
    while(p1<p2)
    {
        if(a[p1]==val)
        {
            swap(a[p1],a[p2]);
            p2--;
        }
        else ++p1;
        while(a[p2]==val&&p2>p1)p2--;
    }
    for(int i=1;i<=p2;++i)cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}
// 选数 //
// 还可以应用素数篩法来优化is_primer函数 //
#include<bits/stdc++.h>
using namespace std;
int n,k;
int arr[21];
int cnt;
bool cmp(int x,int y)
{
    return x>y;
}
bool is_primer(int x)
{
    for(int i=2;i<=sqrt(x);i++)
        if(x%i==0)  return false;
    return true;
}
void dfs(int sum,int i,int num)  // sum表示当前和，i表示当前搜索的数的下标，num表示当前已经使用了几个数
{
    if(num==k)
    {
        if(is_primer(sum))  cnt++;
        return;
    }
    if(n-i+1<k-num) return;   // 这个世界线已经废了
    dfs(sum+arr[i],i+1,num+1);
    dfs(sum,i+1,num);
    return;
}
int main(void)
{
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        scanf("%d",arr+i);
    sort(arr+1,arr+n+1,cmp);
    dfs(0,1,0);
    cout<<cnt<<endl;
    return 0;
}
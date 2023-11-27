#include<bits/stdc++.h>
using namespace std;
int a,b,n;   // a行b列
int arr[1001][1001];
int ma[1001][1001];
int mi[1001][1001];
deque<int> q;    // 单调队列
int main(void)
{
    cin>>a>>b>>n;
    for(int i=1;i<=a;i++)
        for(int j=1;j<=b;j++)
            scanf("%d",&arr[i][j]);
    // step1 维护最大值
    // 每一行，求最大值
    for(int i=1;i<=a;i++)
    {
        q.clear();
        q.push_back(1);
        for(int cur=2;cur<=b;cur++)
        {
            if(cur-q.front()>=n)  q.pop_front();  
            while(!q.empty()&&arr[i][q.back()]<=arr[i][cur]) q.pop_back();
            q.push_back(cur);
            if(cur>=n)  ma[i][cur-n+1] = arr[i][q.front()];    // 最大值在队首
        }
    }
    // 每一列，求最大值
    for(int j=1;j<=b-n+1;j++)
    {
        q.clear();
        q.push_back(1);
        for(int cur=2;cur<=a;cur++)
        {
            if(cur-q.front()>=n)    q.pop_front();
            while(!q.empty()&&ma[q.back()][j]<=ma[cur][j])  q.pop_back();
            q.push_back(cur);
            if(cur>=n)  ma[cur-n+1][j] = ma[q.front()][j];   // 可以原地改，下一步该数会被弹出栈，故不会有影响
        }
    }
    // step2 维护最小值
    // 每行的最小值
    for(int i=1;i<=a;i++)
    {
        q.clear();
        q.push_back(1);
        for(int cur=2;cur<=b;cur++)
        {
            if(cur-q.front()>=n)    q.pop_front();
            while(!q.empty()&&arr[i][q.back()]>=arr[i][cur])    q.pop_back();
            q.push_back(cur);
            if(cur>=n)  mi[i][cur-n+1] = arr[i][q.front()];
        }
    }
    // 每列的最小值
    for(int j=1;j<=b-n+1;j++)
    {
        q.clear();
        q.push_back(1);
        for(int cur=2;cur<=a;cur++)
        {
            if(cur-q.front()>=n)    q.pop_front();
            while(!q.empty()&&mi[q.back()][j]>=mi[cur][j])    q.pop_back();
            q.push_back(cur);
            if(cur>=n)  mi[cur-n+1][j] = mi[q.front()][j];
        }
    }
    // step 3 求最大值和最小值差的最小值
    int ans = 1e10;
    for(int i=1;i<=a-n+1;i++)
        for(int j=1;j<=b-n+1;j++)
            if(ma[i][j]-mi[i][j]<ans)   ans= ma[i][j] - mi[i][j];
    cout<<ans<<endl;
    return 0;
}
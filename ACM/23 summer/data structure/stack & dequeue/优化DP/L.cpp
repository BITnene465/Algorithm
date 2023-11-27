//  1D 但是 单调队列优化 //
// f[i] = max(f[j]) + a[i] , 其中 i-R<=j<=i-L //
#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005];   // f[i] 表示以i为终点，能得到的最大冰冻能量
deque<int> q;
int n,l,r;
int main(void)
{
    cin>>n>>l>>r;
    for(int i=0;i<=n;i++)
        scanf("%d",a+i);
    f[0] = a[0];  // 初始化
    for(int i=1;i<=n;i++)
    {
        int cur=i-l;
        // 单调队列
        if(cur>=0)    // 如果cur>=0 则要维护单调队列
        {
            while(!q.empty()&&cur-q.front()>r-l)    q.pop_front();
            if(f[cur]!=INT_MIN)     // 没有这个判断将收获惨痛的教训
            {
                while(!q.empty()&&f[cur]>=f[q.back()]) q.pop_back();
                q.push_back(cur);
            }
        }
        if(!q.empty())  f[i]=f[q.front()]+a[i];
        else    f[i]=INT_MIN; //表示跳不到这个点
    }
    int ans = INT_MIN;
    for(int i=n+1-r;i<=n;i++)
        ans = max(ans,f[i]);
    cout<<ans<<endl;
    return 0;
}

/*
Hack:
5 3 4
0 1 2 3 4 5
ans = 4
已解决
*/
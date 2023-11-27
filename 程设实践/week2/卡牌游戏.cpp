// 猜想： 最优策略为每次在队列末尾尝试加入 q.back()+1 , 如果不能，直接加入 0  //
// 模拟次策略即可 , 终止检测： 看手牌中0的个数是否为 n,但是开头要特判 //
#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+5;
bool flag[maxn];    // 标记手牌
int n,step;
int cnt0;   // 计数手牌中 0 的个数
deque<int> q;
int main(void)
{
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x==0){++cnt0;continue;}
        flag[x]=1;
    }
    bool f=1;   // 特判检测
    for(int i=1;i<=n;++i)
    {
        int x;
        cin>>x;
        if(x!=i)f=0;
        q.push_back(x);
    }
    if(cnt0==n&&f){cout<<'0'<<endl;return 0;}    // 开头处特判
    // 模拟过程
    do{
        // 先放
        int bac=q.back();
        if(flag[bac+1]){flag[bac+1]=0;q.push_back(bac+1);}
        else {--cnt0;q.push_back(0);}
        // 后取
        int fro=q.front();q.pop_front();
        if(fro==0)cnt0++;
        else flag[fro]=1;
        ++step;
    }while(cnt0!=n||q.back()!=n);
    cout<<step<<endl;
    return 0;
}

// upd:  这是一个错误的算法，但是通过了绝大部分样例 ， WA：3,11.14 //
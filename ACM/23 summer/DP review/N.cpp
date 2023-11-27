#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 3e5+3;
ll b[N];
int n;
vector<ll> tree[N];
ll sum[N];
ll vis[N];     // vis数组防止走回头路
ll f[N][2];    // 0->父节点指向子节点，1->子节点指向父节点
// 表示第i个顶点在自己与父亲的边的指向确定后，其子树能达到的最大权值
bool cmp(int x,int y)
{
    return x>y;
}
void dfs(int n)
{
    f[n][0] = f[n][1] = 0;
    vis[n] = 1;
    vector<ll> temp;
    for(auto v:tree[n])        
    {
        if(!vis[v])
        {
            dfs(v);
            f[n][0] += f[v][1];
            f[n][1] += f[v][1];
            temp.push_back(f[v][0]-f[v][1]);
        }
    }
    sort(temp.begin(),temp.end(),cmp);    // 降序排列
    //
    ll max1,max2;
    max1=b[0];   // 初始化
    max2=b[1];   // 初始化
    for(int i=1;i<=temp.size();i++)
    {
        sum[i] = sum[i-1] + temp[i-1];
        max1 = max(max1,sum[i]+b[i]);
        max2 = max(max2,sum[i]+b[i+1]);
    }
    //
    f[n][1] += max2;
    f[n][0] += max1;
    return;
}
int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<=n-1;i++)
        scanf("%d",b+i);
    for(int i=1;i<n;i++)
    {
        int u,v;
        scanf("%d %d",&u,&v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    dfs(1);
    cout<<f[1][0]<<endl;       // 以1为根节点
    return 0;
}
// 此处是暴力搜索 //
#include<bits/stdc++.h>
using namespace std;
int vil[3001],post[3001];
int n,m;
int lim;
int Min;
int vis[3001];
int vis2[3001];
void dfs(int sum,int d,int last)
{
    if(d==m+1)
    {
        if(sum<Min){
            Min = sum;
            for(int i=1;i<=lim;i++)
                vis2[i] = vis[i];
        }
        return;
    }
    else if(last==lim)  return;   
    else
    {
        for(int i=last+1;i<=lim;i++)
        {
            vis[i] = 1;
            int newsum = 0;
            for(int j=1;j<=n;j++)
            {
                int temp = INT_MAX;
                for(int k=1;k<=lim;k++)
                {
                    if(vis[k]&&temp>abs(vil[j]-k))  temp = abs(vil[j]-k);
                }
                newsum+=temp;
            }
            dfs(newsum,d+1,i);
            vis[i] = 0;
        }
    }
}
int main(void)
{
    int start = clock();
    cin>>n>>m;    // n个村庄，m个邮局
    for(int i=1;i<=n;i++)
    {
        cin>>vil[i];
        lim = max(lim,vil[i]);
    }
    memset(vis,0,sizeof(vis));
    Min = INT_MAX;
    dfs(INT_MAX,1,0);
    cout<<"min="<<Min<<endl;
    for(int i=1;i<=lim;i++)
    {
        if(vis2[i]) cout<<i<<" ";
    }
    cout<<endl;
    int end = clock();
    cout<<"time="<<end-start<<"ms"<<endl;
    return 0;
}
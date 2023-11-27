// 领接表存图，在算法上没有任何优势 但是简单容易实现 //
#include<bits/stdc++.h>
using namespace std;
#define MAXN 5005
int G[MAXN][MAXN];
int m,n,f;
int cnt1,cnt2,cnt,indeg[MAXN],outdeg[MAXN],deg[MAXN];
int stk[MAXN],top=0;
void reset()
{
    cnt1=cnt2=cnt=0;
    memset(indeg,0,sizeof(indeg));
    memset(outdeg,0,sizeof(outdeg));
    memset(deg,0,sizeof(deg));
    memset(G,0,sizeof(G));
    top=0;
}
void Dfs1(int s)   // 天然字典序最小，无需排序
{
    for(int i=1;i<=n;++i)
    {
        if(G[s][i])
        {
            G[s][i]--;
            Dfs1(i);
        }
    }
    stk[++top]=s;
}
void Dfs2(int s)
{
    for(int i=1;i<=n;++i)
    {
        if(G[s][i])
        {
            G[s][i]--;
            G[i][s]--;
            Dfs2(i);
        }
    }
    stk[++top]=s;
}
void print_euler()
{
    while(top)cout<<stk[top--]<<" ";
    cout<<endl;
}
int main(void)
{
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    while(1)
    {
        reset();
        cout<<"有向图扣1,无向图扣2(其他退出)"<<endl;
        cin>>f;
        cout<<"输入两个数分别为节点数和边数"<<endl;
        if(f==1)
        {
            cin>>n>>m;
            cout<<"节点1~"<<n<<",输入"<<m<<"条边"<<endl;
            for(int i=1;i<=m;++i)
            {
                int u,v;
                cin>>u>>v;
                G[u][v]++;
                indeg[v]++,outdeg[u]++;
            }
            // 判断联通性
            
            // 统计并判断
            bool flag=1;int s=1;
            for(int i=1;i<=n;++i)
            {
                if(indeg[i]==outdeg[i])continue;
                flag=0;
                if(indeg[i]-outdeg[i]==1)cnt2++;
                else if(outdeg[i]-indeg[i]==1)cnt1++,s=i;
                else {cout<<"该图不存在欧拉路径"<<endl;f=3;break;}
            }
            if(f==3){continue;} 
            if(!flag&&!(cnt1==cnt2&&cnt1==1)){cout<<"该图不存在欧拉路径"<<endl;continue;}
            if(flag){cout<<"该图存在欧拉回路:"<<endl;Dfs1(s);print_euler();}
            else{cout<<"该图存在欧拉路径:"<<endl;Dfs1(s);print_euler();}
            cout<<"\n\n"<<endl;
        }
        else if(f==2)
        {
            cin>>n>>m;
            cout<<"节点1~"<<n<<",输入"<<m<<"条边"<<endl;
            for(int i=1;i<=m;++i)
            {
                int u,v;
                cin>>u>>v;
                G[u][v]++;G[v][u]++;
                deg[u]++;deg[v]++;
            }
            // 判断连通性


            // 统计并特判
            bool flag=1;int s=1;
            for(int i=1;i<=n;++i)
            {
                if(deg[i]%2==0)continue;
                flag=0;
                cnt++;
            }
            if(!flag&&!(cnt==2)){cout<<"该图不存在欧拉路径"<<endl;continue;}
            if(flag){cout<<"该图存在欧拉回路:"<<endl;Dfs2(s);print_euler();}
            else{cout<<"该图存在欧拉路径:"<<endl;Dfs2(s);print_euler();}
            cout<<"\n\n"<<endl;
        }
        else break;
    }
    return 0;
}   
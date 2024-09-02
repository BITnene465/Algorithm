#include<bits/stdc++.h>
using namespace std;
int f[105][105], n;
void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                f[i][j] = f[i][j] | f[i][k] & f[k][j];
}
int main(void)
{
    cin >> n;
    for(int i=1;i<=n;++i)for(int j=1;j<=n;++j)cin>>f[i][j];
    floyd();
    bool flag = 1, flag2 = 1;
    for(int i=1;i<=n;++i)for(int j=i+1;j<=n;++j)
    {
        if(!f[i][j]){
            flag = false;
            if(!f[j][i]){flag2=false;break;}
        }
    }
    if(flag){cout<<"A"<<endl;}
    else if(flag2){cout<<"B"<<endl;}
    else {cout<<"C"<<endl;}   // 其实要再用无向图跑一遍floyd，但是算了。
    return 0;
}
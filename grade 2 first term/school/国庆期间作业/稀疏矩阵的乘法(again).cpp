#include<bits/stdc++.h>
using namespace std;
int n1,m1,num1,n2,m2,num2;
int mat1[105][105],mat2[105][105],mat3[105][105];
int main(void)
{
    cin>>n1>>m1>>num1;
    for(int i=1;i<=num1;++i){
        int x,y,val;
        cin>>x>>y>>val;
        mat1[x][y]=val;
    }
    cin>>n2>>m2>>num2;
    for(int i=1;i<=num2;++i){
        int x,y,val;
        cin>>x>>y>>val;
        mat2[x][y]=val;
    }
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=m2;++j){
            for(int k=1;k<=m1;++k){
                mat3[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
    // output
    int num3 = 0;
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=m2;++j){
            if(mat3[i][j]) num3++;
        }
    }
    cout<<n1<<'\n'<<m2<<'\n'<<num3<<'\n';
    for(int i=1;i<=n1;++i){
        for(int j=1;j<=m2;++j){
            if(mat3[i][j]) cout<<i<<','<<j<<','<<mat3[i][j]<<'\n';
        }
    }
    return 0;
}
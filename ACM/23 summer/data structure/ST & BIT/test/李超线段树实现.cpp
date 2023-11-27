//  李超线段树 //
#include<bits/stdc++.h>
using namespace std;
double k[1000000],b[1000000];   // 存储李超线段树     
int flag[1000000];
// 浮点数运算会有误差 //
const double eps = 1e-9;
double mmax(double x,double y)
{
    if(x-y>eps) return x;
    if(y-x>eps) return y;
    return (x+y)/2.0;
}
// 插入实现 
// 在区间[l,r] 中插入线段 y = nk*x+nb //
void ins(int root,int l,int r,double nk,double nb)
{
    if(!flag[root]){flag[root]=1;k[root]=nk;b[root]=nb;return;}
    int mid=l+(r-l>>1);
    double l1=(double)l*nk+nb,r1=(double)r*nk+nb;
    double l2=(double)l*k[root]+b[root],r2=(double)r*k[root]+b[root];
    if(l1>=l2 && r1>=r2){k[root]=nk;b[root]=nb;return;}
    if(l1<=l2 && r1<=r2)return;
    double it_x=(nb-b[root])/(k[root]-nk);
    if(it_x>=(double)mid){
        if(l1>l2){ins(root<<1|1,mid+1,r,k[root],b[root]);k[root]=nk;b[root]=nb;}
        else ins(root<<1|1,mid+1,r,nk,nb);
    }
    else{
        if(l1<l2){ins(root<<1,l,mid,k[root],b[root]);k[root]=nk;b[root]=nb;}
        else ins(root<<1,l,mid,nk,nb);
    }
}
// 查询实现
double query(int root,int l,int r,int d)
{
    if(l==r)return k[root]*(double)d+b[root];
    int  mid=l+(r-l>>1);
    double res=k[root]*(double)d+b[root];
    if(mid>=d)res=mmax(res,query(root<<1,l,mid,d));
    else res=mmax(res,query(root<<1|1,mid+1,r,d));
    return res;
}
int main(void)
{
    
}
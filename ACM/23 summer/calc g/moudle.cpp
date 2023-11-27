#include<bits/stdc++.h>
using namespace std;
// 常数定义
const double eps = 1e-9;     // 可更改
const double PI = acos(-1.0);
// 基础函数定义
int sign(double x)
{
    if(fabs(x)<eps) return 0;
    if(x<0) return -1;
    else    return 1;
}
int dcmp(double x,double y)
{
    if(x>y+eps) return 1;
    if(x<y-eps) return -1;
    return 0;
}
// 结构体、类
// # 点、向量
struct P{
    double x,y;
    P(){};
    
};
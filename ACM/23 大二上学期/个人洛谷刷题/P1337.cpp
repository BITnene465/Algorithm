// n点费马点计算，模拟退火
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;
double ans, ans_x, ans_y;    // 维护全局最优值，而不是每次的当前值
int n, x[maxn], y[maxn], w[maxn];
double Rand(){return (double)rand()/RAND_MAX;}   // 返回一个 0~1 的小数
double func(double xx, double yy)   // 计算一个点的权值
{
    double res = 0;
    for(int i=1;i<=n;++i)
    {
        double dis_x = (xx - x[i]) * (xx - x[i]);
        double dis_y = (yy - y[i]) * (yy - y[i]);
        res += sqrt(dis_x + dis_y)*w[i];
    }
    if(res < ans) {ans = res; ans_x = xx; ans_y = yy;}
    return res;
}
void SA()
{     
    double T = 20000;    // 初始温度
    double T0 = 1e-10;      // 终止温度（最好是所求精度）
    double down = 0.9997;
    // 初始化设置为重心，未加权
    double now_x, now_y, now_dis;
    for(int i=1;i<=n;++i)now_x += x[i], now_y += y[i];
    now_x = now_x / n;
    now_y = now_y / n; 
    now_dis = func(now_x, now_y);   // 此时ans也初始化了
    
    // 模拟退火
    while(T > T0){
        double nxt_x, nxt_y, nxt_dis;
        nxt_x = now_x + T*(2 * Rand() - 1);    // 每次变化范围为  -T~+T
        nxt_y = now_y + T*(2 * Rand() - 1);
        nxt_dis = func(nxt_x, nxt_y);
        double delta = nxt_dis - now_dis;
        if(exp(-delta/T) > Rand()){    // 如果delta < 0 自然也会接受 ; T越小，越难接受
            now_dis = nxt_dis;
            now_x = nxt_x;
            now_y = nxt_y;
        } 
        T = T*down;
    }
}
int main(void)
{
    srand(time(NULL));
    scanf("%d", &n);
    for(int i=1;i<=n;++i) scanf("%d %d %d", x+i, y+i, w+i);
    
    ans = 100000000;
    
    while((double)clock()/CLOCKS_PER_SEC < 0.80)
        SA();

    printf("%.3lf %.3lf\n", ans_x, ans_y);
    return 0;
}
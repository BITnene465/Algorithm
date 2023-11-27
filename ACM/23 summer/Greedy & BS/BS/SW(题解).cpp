#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
typedef long long ll;
const ll MAXN = 1e5 + 5;

ll n, m, k;
double a[MAXN], b[MAXN], c[MAXN], d[MAXN], more[MAXN];

//计算浓度大于mid的方案数
ll check(double cc) {
    //浓度是cc,对于m个瓶子，水是y，则糖需要cc * y / (1 - cc)
    //多余的糖是x - cc * y / (1 - cc)，把每个瓶子中多余的糖放到more数组里
    for (int i = 0; i < m; ++i) {
        more[i] = c[i] - cc * d[i] / (1 - cc);
    }
    //按照多余的糖排序
    sort(more, more + m);
    ll cnt = 0;
    //遍历n个瓶子，对于每个瓶子，计算它缺少的糖
    for (int i = 0; i < n; ++i) {
        double less = -(a[i] - cc * b[i] / (1 - cc));
        //二分查找，找到所有多余的糖比less多的个数
        ll t = more + m - upper_bound(more, more + m, less);
        cnt += t;
    }
    return cnt;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }
    //二分排名第k的浓度
    double low = 0, high = 1, mid;
    for (int i = 0; i < 100; ++i) {
        mid = (low + high) / 2;
        if (check(mid) < k) {
            high = mid;
        } else {
            low = mid;
        }
    }
    printf("%.15lf\n", high*100);
    return 0;
}
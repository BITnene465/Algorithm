// 给定平面n个点，求最近点对的距离 （答案就是这个距离除以2） //
// n点最近点对  分治法 计算几何 //
#include<bits/stdc++.h>
using namespace std;
int n;
double ans;
struct Point
{
    double x, y;
}point[100005];
Point B[100005], C[105];   // 临时集合
void upd_ans(Point& a, Point& b)
{
    ans = min(ans, sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y))); // 尝试更新
    // cout<<a.x<<" "<<a.y<<" "<<b.x<<" "<<b.y<<endl;
    // cout<<ans<<endl;
}
bool cmp_x(Point a, Point b)
{
    return a.x < b.x || (a.x==b.x && a.y < b.y);
}
bool cmp_y(Point a, Point b)
{
    return a.y > b.y;
}
void find_cross(int l, int mid, int r)
{   // 两侧合并
    int cnt=0;
    for (int i = mid + 1; fabs(point[i].x - point[mid].x) < ans && i<=r; ++i)
    {
        ++cnt;
        B[cnt].x = point[i].x;
        B[cnt].y = point[i].y;
    }
    for (int i = mid; fabs(point[mid].x - point[i].x) < ans && i>=l; --i)
    {
        ++cnt;
        B[cnt].x = point[i].x;
        B[cnt].y = point[i].y;
    }
    // sort B
    sort(B+1, B+cnt+1, cmp_y);
    // Merge
    for(int i=1;i<=cnt-1;++i)
    {
        for(int j=i+1;j<=cnt&&fabs(B[j].y - B[i].y)<ans;++j){
            upd_ans(B[i], B[j]);
        }
    }
}
void find_ans(int l, int r)
{
    if(r<=l)return;   // 点数小于2
    if(r-l==1){   // 刚好两个点
        upd_ans(point[l], point[r]);
        return;
    }
    int mid = l+r>>1;
    find_ans(l, mid);
    find_ans(mid+1, r);
    find_cross(l, mid, r);
}
void solve()
{
    ans = 1E20;
    find_ans(1, n);
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    while(cin>>n)
    {
        if(!n) break;
        for(int i=1;i<=n;++i)cin>>point[i].x>>point[i].y;
        sort(point+1, point+n+1, cmp_x);
        solve();
        cout<<fixed<<setprecision(2)<<ans/2<<endl;
    }
    return 0;
}

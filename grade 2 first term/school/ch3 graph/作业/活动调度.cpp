// 经典的 主持人调度题 ，使用贪心算法
// 基本思想是，排序后：每组都最贪心地选择可以相容的任务，最后得到的分组组数是最少的，也即 答案
#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
int st[maxn], ed[maxn], cnt, ans, n;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> st[i] >> ed[i];
    sort(st, st + n);
    sort(ed, ed + n);
    int i=0, j=0;
    while (i < n && j < n)
    {
        if (st[i] < ed[j])
        {
            cnt++;
            i++;
            ans = max(ans, cnt);
        }
        else if (st[i] > ed[j])
        {
            cnt--;
            j++;
        }
        else
        {
            j++;
            i++;
        }
    }
    cout << ans << endl;
    return 0;
}

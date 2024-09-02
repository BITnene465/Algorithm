#include <bits/stdc++.h>
using namespace std;
map<int, int> m; // <value, index>
int nums[100005], n, target;
int main(void)
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> nums[i];
    for (int i = 1; i <= n; ++i)
        m[nums[i]] = i;
    cin >> target;
    int index1, index2;
    for (int i = 1; i <= n; ++i) // 时间复杂度 O(nlogn)
    {
        if (m.count(target - nums[i]) && m[target - nums[i]] != i)
        {
            index1 = i - 1;   // 题目的要求
            index2 = m[target - nums[i]] - 1;
            if(index1>index2) swap(index1, index2);
            break;
        }
    }
    cout << index1 << ' ' << index2 << endl;
    return 0;
}
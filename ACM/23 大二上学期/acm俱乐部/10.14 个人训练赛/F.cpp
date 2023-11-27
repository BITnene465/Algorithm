#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,p[1000005];
ll quickSort(int *num, const int &begin, const int &end) {
    if (begin >= end)return 0;
    int count = 0, *left_num, *right_num;
    int pivot = num[begin];
    right_num = new int[end - begin];
    int left = begin + 1, left_pos = begin, temp = 0;
    bool flag = true;
    while (left <= end) {
	++count;
	if (num[left] < pivot) {
	    num[left_pos] = num[left];
	    ++left_pos;
	} else {
	    right_num[temp] = num[left];
	    ++temp;
	}
	++left;
    }
    num[left_pos] = pivot;
    for (int i = 0; i < temp; ++i) {
	num[left_pos + i + 1] = right_num[i];
    }
    delete[]right_num;
    return count + quickSort(num, begin, left_pos - 1) + quickSort(num, left_pos + 1, end);
}
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",p+i);
    printf("%lld\n",quickSort(p, 1, n));
    return 0;
}
// 分治法，O(n)找数组中位数！ 快速选择法！ //
// 更一般地，可以找第k大的数 //
#include<bits/stdc++.h>
using namespace std;
int coordinate_y[2000005], cnt;
int partition(int arr[], int l, int r)    // 以基准划分（会改变arr数组）
{
    int pivot = arr[r];   // 选一个当基准就好
    int i = l-1, j = l;
    
    while(j<r){
        if(arr[j]<=pivot) swap(arr[++i], arr[j]);
        j++;
    }

    swap(arr[i+1], arr[r]);
    return i+1;
}
int find_kth(int arr[],int l, int r, int cl, int cr, int k)  // 找数组中的第k大的数
{
    if(cl>cr)return -1; // 没有第k大的数
    int pivotIndex = partition(arr, cl, cr);

    if(pivotIndex == k-l+1) return arr[pivotIndex];
    else if(pivotIndex < k-l+1) return find_kth(arr, l, r, pivotIndex+1, cr, k);
    else return find_kth(arr, l, r, cl, pivotIndex-1, k);
}
int main(void)
{
    int x, y;
    while(~scanf("%d,%d", &x, &y)) coordinate_y[++cnt] = y;
    int ans = find_kth(coordinate_y, 1, cnt, 1, cnt, (cnt+1)/2);
    printf("%d\n", ans);
    return 0;
}
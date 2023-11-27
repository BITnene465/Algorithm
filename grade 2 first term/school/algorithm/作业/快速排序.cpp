// 选取基准记录的三者取中的的快速算法 + 简单情况插入算法混合 //
#include<bits/stdc++.h>
using namespace std;
const int cutoff = 5;    // 较小的数组直接用插入排序
string line;
int arr[1005], n;
int median3_value[1005], cnt;
void insertsort(int arr[], int l, int r)
{
    int i, key, j;
    for (i = l + 1; i <= r; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= l && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int median3(int arr[], int l, int r)
{
    int mid = (l + r) >> 1;
    int k = l;
    if (arr[mid] < arr[k])
    {
        k = mid;
    }
    if (arr[r] < arr[k])
    {
        k = r; // k指向三者中最小值
    }
    if (k != l)
    {
        swap(arr[k], arr[l]);
    }
    if (mid != r && arr[mid] < arr[r])
    {
        swap(arr[mid], arr[r]);
    }

    return arr[r];
}
// 感觉这个版本并不纯正？害！
// 将arr[l~r] 按照arr[l]划分，并返回分界下标idx
int partition(int arr[], int l, int r)
{
    if (r <= l) return l; // special
    int i = l, j = r - 1;
    int pivot = median3(arr, l, r);
    median3_value[++cnt] = pivot;    // 加入答案
    while(1)
    {
        while(i<j && arr[i] < pivot) ++i;
        while(i<j && pivot < arr[j]) --j;
        if(i < j)swap(arr[i++], arr[j--]);
        else break;
    }
    if(arr[i] > pivot){
        arr[r] = arr[i];
        arr[i] = pivot;
    }
    return i;
}
void quicksort(int arr[], int l, int r)
{
    if(r - l < cutoff)  // 长度 <= cutoff
    {
        insertsort(arr, l, r);
        return;
    }
    int pivotpos = partition(arr, l, r);
    quicksort(arr, l, pivotpos-1);
    quicksort(arr, pivotpos+1, r);
}
int main(void)
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    n = 0;
    while(1)
    {
        cin >> line;
        if(line[0]=='#')break;
        arr[n++] = stoi(line);
    }
    // sort
    quicksort(arr, 0, n-1);
    // print
    cout<<"After Sorting:\n";
    for(int i=0;i<n;++i) cout<< arr[i] << ' ';
    cout<<'\n';
    cout<<"Median3 Value:\n";
    if(cnt>0){
        for(int i=1;i<=cnt;++i) cout<< median3_value[i] << ' ';
        cout<<'\n';
    }
    else{cout<<"none\n";}
    return 0;
}
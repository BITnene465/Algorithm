#include<iostream>
using namespace std;
void bubble_sort(int* arr, int l, int r)
{
    for(int i=r-1;i>=l;--i)
        for(int j=i;j<=r;++j)
            if(arr[j]<arr[j-1])swap(arr[j], arr[j-1]);
}
int main(void)
{
    int arr[] = {1, 9, 10, -1, -9, -98};
    int l = sizeof(arr) / sizeof(int);
    bubble_sort(arr, 0, l - 1);
    for(int i=0;i<l;++i) cout << arr[i] << " ";
    cout<<endl;
    return 0;
}
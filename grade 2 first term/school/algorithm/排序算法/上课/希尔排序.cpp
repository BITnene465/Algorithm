#include <iostream>
#include <vector>
void shellSort(std::vector<int> &arr)
{
    int n = arr.size();
    // 选择间隔序列（这里使用经典的3x+1序列）
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        // 对每个小组进行插入排序
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;
            while (j >= gap && arr[j - gap] > temp)
            {
                arr[j] = arr[j - gap];
                j -= gap;
            }
            arr[j] = temp;
        }
    }
}
int main()
{
    std::vector<int> arr = {12, 34, 54, 2, 3};

    shellSort(arr);

    std::cout << "希尔排序后的数组: ";
    for (int num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

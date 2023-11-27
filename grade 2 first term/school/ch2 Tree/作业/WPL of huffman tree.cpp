// 直接套了算法题的模板 //
#include<bits/stdc++.h>
using namespace std;
int getWPL(int arr[], int n) {  // 对于未建好的霍夫曼树，直接求其 WPL
  priority_queue<int, vector<int>, greater<int>> huffman;  // 小根堆
  for (int i = 0; i < n; i++) huffman.push(arr[i]);

  int res = 0;
  for (int i = 0; i < n - 1; i++) {
    int x = huffman.top();
    huffman.pop();
    int y = huffman.top();
    huffman.pop();
    int temp = x + y;
    res += temp;
    huffman.push(temp);
  }
  return res;
}
int n,arr[10005];
int main(void)
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)scanf("%d",arr+i);
    printf("WPL=%d\n",getWPL(arr, n));
    return 0;
}
// 此处要实现一个大根堆，使用数组版的完全二叉树实现
// 实现了一个模板类
// 这个堆排序还写的挺好的，就是慢了点
#include<bits/stdc++.h>
using namespace std;
int n, arr[1005];
template<typename T> class Heap{   // 一个最简单的二叉堆实现，各种操作的速度都非常慢（默认大根堆）
    
    public:
    Heap(T arr[], int l, int r)
    {
        max_size = r-l+1;
        tot = r-l+1;
        data = new T[max_size];
        for(int i=0;i<tot;++i)
            data[i] = arr[l+i];
        // display();
        init_heap();
    }
    T top() { return data[0]; }
    void pop()
    {
        data[0] = data[--tot];
        swap_down(0, tot-1);   // 把这个元素调整一下即可
    }
    void display()
    {
        for(int i=0;i<tot;++i)cout<<data[i]<<' ';
        cout<<'\n';
    }
    ~Heap(){delete[] data;}    // 删除堆

    private:
    T* data; 
    int max_size = 0;
    int tot = 0;
    void swap_down(int st, int ed)
    {
        int fa = st;
        int child = 2*fa+1;  // 初始是左儿子
        while(child <= ed)
        {
            if(child+1<=ed && data[child]<data[child+1]) child=child+1;
            if(data[fa]>=data[child])return;
            else {
                swap(data[fa], data[child]);
                fa = child;
                child = fa*2+1;
            }
        } 
    }
    void init_heap(){
        // 从最后一个节点的父节点开始建堆
        for(int i=(tot-2)/2;i>=0;--i) swap_down(i, tot-1);
    }
};
int main(void)
{
    cin>>n;
    for(int i=0;i<n;++i) cin>>arr[i];
    Heap<int> heap(arr, 0, n - 1);
    
    for(int i=1;i<=3;++i){
        heap.display();
        heap.pop();
    }
    return 0;
}
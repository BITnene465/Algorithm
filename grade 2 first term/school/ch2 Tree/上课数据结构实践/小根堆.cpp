#include<bits/stdc++.h>
using namespace std;
class heap{
    int tot;
    int* arr;
    int maxSize;
    heap(int size){
        this->maxSize = size;
        this->tot = 0;
        this->arr = new int[maxSize+1]; // 从下标1开始
    }

    void adjust(int rt)
    {
        int minId = rt;
        
    }
    void add(int val)
    {
        arr[++tot] = val;
        if(tot==1) return;
        adjust(1);
    }
    int top()
    {
        if(tot>=1)return arr[1];
        else return -1;
    }
    void pop()
    {
        if(tot==0) return;
        arr[1] = arr[tot--];
        adjust(1);
    }
};
int main(void)
{

}
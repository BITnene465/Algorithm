**tips**: sort函数千万不能用 $\leq$ 和 $\geq$ ，可能导致数组越界！

遍历map对象,利用迭代器或者使用auto来取出键值对
```cpp
int main(void)
{
    map<int,vector<int>> m;
    m[1] = vector<int> {2,3,4,5};
    m[2] = vector<int> {1,3,4,5};
    m[3] = vector<int> {1,2,4,5};
    m[4] = vector<int> {1,2,3,5};
    m[5] = vector<int> {1,3,4,2};
    for(auto key_vlaues:m)
    {
        int key = key_vlaues.first;
        for(auto value:key_vlaues.second)
        {
            printf("m[%d] include %d\n",key,value);
        }
        printf("\n");
    }
    return 0;
}
```

unique() 函数 ， 使用前需要先排序，unique函数会删除相邻的重复元素，其工作原理是将重复元素放置于后面"隐藏起来",返回一个迭代器，指向不重复的最后一个数



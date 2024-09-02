#include <iostream>
using namespace std;
class IntArray
{
private:
    static const int size = 5;
    const int v1;
    static int v2;
    int arr[size];

public:
    inline IntArray(int v) : v1(v)
    {
        for (int i = 0; i < size; ++i)
            arr[i] = v1;
        cout << "class is constructed" << endl;
    }

    static void printStaticVariable();

    // inline member function
    void print()
    {
        cout << "Array Values:" << endl;
        for (int i = 0; i < size; ++i)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        printStaticVariable(); 
    }
};
// 初始化类
int IntArray::v2 = 10;
void IntArray::printStaticVariable(){
    cout << "static value: " << v2 <<endl;
}

int main()
{
    IntArray array(5);
    array.print();
    return 0;
}

/*
输出为：
class is constructed
Array Values:
5 5 5 5 5
static value: 10
*/
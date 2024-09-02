// 一种 p无法修改； 一种 *p无法修改；
// 判别方法： const关键字离得近： *(常量型) or 类型名(指向常量)
#include<iostream>
using namespace std;
int main(void)
{
    // 1
    // pointer to const -- 指向常量的指针 -> 无法通过该指针修改它指向变量或常量的取值(read only)
    int a = 1;
    int const* ptc1 = &a;
    const int* ptc2 = &a;

    // error:  *ptc1 = 12;    


    // 2
    // const pointer  -- 常量型指针  ->  该指针必须初始化，并且无法更改自己指向的对象
    int b = 10;
    int* const cp1 = &b;

    // error:  cp1 = &a;   


    // 3
    // 常量的地址只能赋给指向常量的指针
    const int byteSize = 8;
    int* ptr1;
    const int* ptr2;
    // error:  ptr1 = &byteSize;  
    ptr2 = &byteSize;


    // 4    
    // const pointer to a const  -> 双重约束 p 与 *p 均不可变
    const int c = 10;
    const int* const ptr3 = &c;


    return 0;
}
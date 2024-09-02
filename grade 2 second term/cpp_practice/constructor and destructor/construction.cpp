// 保留默认构造函数
#include<iostream>
using namespace std;
class Student{
    int ID;

public:
    Student(int id):ID(id){};
    Student() = default;   // 保留默认构造函数
    void disp();
};
void Student::disp(){
    cout<< ID << endl;
}

int main(void)
{
    Student s1;
    s1.disp();
    Student s2(10);
    s2.disp();
    // 以上两种方法都是在栈上申请空间，自动创建、自动删除(作用域结束之后，类似于自动变量)
    return 0;
}
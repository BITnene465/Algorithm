#include <iostream>
using namespace std;
class Demo
{
public:
    void display(int value){
        cout << "value " << value << endl;
    }
};
int main(void)
{
    Demo d;
    Demo *dp = &d; // 常规的对象指针

    void (Demo::*fptr)(int)= &Demo::display;   // 没有绑定特定的对象

    d.display(1);
    (d.*fptr)(2);
    (dp->*fptr)(3);
    return 0;

}
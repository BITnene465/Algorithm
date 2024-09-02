// a class as a friend
#include<bits/stdc++.h>
using namespace std;
class X; class Y; class A;
class X{};
class Y{};

class A{
    friend class X;
    friend class Y;   // 从而 X，Y的对象都可以访问 A的对象
};


int main(void)
{
    return 0;
}
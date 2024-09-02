#include<iostream>
#include "shinku2.h"
using namespace std;
void func1(){
    shinku::nikaidou1();
}
void func2(){
    using namespace shinku;
    nikaidou1();
}
int main(void)
{
    func1();
    func2();
    return 0;
}
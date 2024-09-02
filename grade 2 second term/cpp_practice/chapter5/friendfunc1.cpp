#include<iostream>
using namespace std;
class Time{
    int hours, minutes;
public:
    void set(int hours, int minutes){this->hours=hours;
    this->minutes = minutes;}
    friend void show(Time& time);   // a frined function
};

void show(Time& time){
    cout<< time.hours << ":" << time.minutes << endl;
}

int main(void)
{
    Time t;
    t.set(20, 30);
    show(t);    // 采用全局函数的调用格式而不是类内函数
    return 0;
}
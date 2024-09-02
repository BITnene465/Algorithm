#include<iostream>
using namespace std;
class A{
    int *p;
public:
    A(int i){p = new int(i);}
    ~A(){delete p;}
    A(const A& a);
    A& operator=(const A& a);
};
A::A(const A& a){
    p = new int(*a.p);
}
A& A::operator=(const A& a){
    if(this==&a){
        return *this;
    }
    delete p;
    p = new int(*a.p);
    return *this;
}

int main(void)
{
    
}
#include<iostream>
using namespace std;
class cls1; class cls2; class cls3;
class cls3
{
public:
    int getdata(cls1 &c);
};

class cls2
{
public:
    void incrementing(cls1& c);
};

class cls1
{
    int data;
public:
    cls1() = default;
    cls1(int data):data(data){};
    friend class cls2;   // friend class 
    friend int cls3::getdata(cls1& c); // friend function
};

void cls2::incrementing(cls1 &c){
    cout<< "data=" << c.data << endl;
    cout<< "自增后 data=" << ++c.data << endl;
}

int cls3::getdata(cls1& c){
    return c.data;
}

int main(void)
{
    cls1 c1(0721);
    cls2 c2;
    cls3 c3;

    cout<< "友元类访问:" << endl;
    c2.incrementing(c1);

    cout<< "友元函数访问:\ndata=" << c3.getdata(c1) << endl;
    return 0;
}
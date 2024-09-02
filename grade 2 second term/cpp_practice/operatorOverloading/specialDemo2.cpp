// special operator overloading
#include <iostream>
#include<string>
#include<sstream>
using namespace std;
class Student
{
public:
    int age;
    int ID;
};
class X{
    Student* s;
public:
    X(){s = new Student; s->age=0, s->ID=0;}
    ~X(){delete s;}
    Student* operator->(){return s;}

    string info(){
        stringstream ss;
        ss << "age: " << s->age << " \n" << "ID: " << s->ID << " ";  
        return ss.str();
    }
};
int main(void)
{
    X x;
    x->age = 10;   // (x.operator->())->age = 10;   箭头会递归调用，所以不用 x->->age = 10;
    x->ID  = 100;  // (x.operator->())->ID = 100;

    cout << x.info() << endl;
    return 0;
}
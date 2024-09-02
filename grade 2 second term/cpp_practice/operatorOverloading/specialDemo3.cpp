#include <iostream>
#include <string>
#include <sstream>
using namespace std;
class Student
{
public:
    int age;
    int ID;
};
class X
{
    Student *s;

public:
    X()
    {
        s = new Student;
        s->age = 0, s->ID = 0;
    }
    ~X() { delete s; }
    Student *operator->() { return s; }

    // ÖØÔØÊäÈëÊä³ö
    friend ostream& operator<<(ostream& o, const X& x){
        o << "age: " << x.s->age << " \nID: " << x.s->ID << " ";
        return o;
    }
    friend istream& operator>>(istream& i, X& x){
        i >> x.s->age >> x.s->ID;
        return i;
    }
};
int main(void)
{
    X x;
    cin >> x;   // operator>>(cin, x)
    cout << x << endl;  // operator<<(cout, x)
    return 0;
}
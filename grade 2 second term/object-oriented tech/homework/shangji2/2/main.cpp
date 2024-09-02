#include<iostream>
using namespace std;
class Mammal{
public:
    virtual void speak(){
        cout << "Mammal voice" << endl;
    }
};
class Dog: public Mammal{
    virtual void speak(){
        cout << "dog bark" << endl;
    }
};
class Pug: public Dog{
    virtual void speak(){
        cout << "pug bark" << endl;
    }
};
void Talk(Mammal& m){
    m.speak();
}
int main(void)
{
    Mammal m1;
    Dog m2;
    Pug m3;
    Talk(m1);
    Talk(m2);
    Talk(m3);
    return 0;
}
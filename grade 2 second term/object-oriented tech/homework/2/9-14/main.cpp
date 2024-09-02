#include <iostream>
class A
{
public:
    // Inline default constructor
    A() { std::cout << "ClassA is constructed." << std::endl; }
};

class B
{
public:
    A a;
    // Inline constructor
    B() { std::cout << "ClassB is constructed." << std::endl; }
};
int main()
{
    B array1[3];
    std::cout << "=======" << std::endl;
    B* array2 = new B[3];
    return 0;
}

## 14-5 
In Combined.cpp, create a class D that inherits from B and has a member object of class C. Add code to show when the constructors and destructors are being called.

在main函数中实例化一个D的对象，最终结果为：
```cpp
B::B() : 47
B::B() : 47
A::A() : 47
C::C() : 47
D::D() : 47
D::~D()
C::~C()
A::~A()
B::~B()
B::~B()
```
创建D的对象时，首先调用其父类B的构造函数，在调用其数据成员C的构造函数，最后调用自己的构造函数

## 15-4 
Modify C14:Combined.cpp so that f( ) is virtual in the base class. Change main( ) to perform an upcast and a virtual call.

见代码

## 15-22
Write a class with three overloaded virtual functions. Inherit a new class from this and override one of the functions. Create an object of your derived class. Can you call all the base class functions through the derived-class object? Upcast the address of the object to the base. Can you call all three functions through the base? Remove the overridden definition in the derived class. Now can you call all the base class functions through the derived-class object?


1. 使用派生类对象只能调用第一个成员函数，并且会调用重定义后的版本。因为重定义函数会隐藏基类中所有的同名函数。（name hiding）  (注： 可以使用`Base::func(arg)` 来访问基类的三个函数)
2. 使用基类指针来指向派生类对象，正常情况下，第一个函数会调用派生类的版本（override），后两个函数会调用基类的版本，但是仍然可以使用`pb->Base::func()` 来调用第一个函数的基类版本
3. 如果去掉了 override defination， 那么派生类对象会完全继承基类的三个函数，可以直接调用


## 16-17
Templatize the Int class in TPStash2Test.cpp so that it holds any type of object (feel free to change the name of the class to something more appropriate).

```cpp
template<typename T>
class Container
{
    T data;

public:
    Container(T& obj) : data(obj)
    {
        cout << ">" << data << endl;
    }
    ~Container() { cout << "~" << i << ' '; }
    operator T() const { return data; }
    friend ostream &
    operator<<(ostream &os, const Container &x)
    {
        return os << "Container: " << x.data;
    }
    friend ostream &
    operator<<(ostream &os, const Container *x)
    {
        return os << "Container: " << x->data;
    }
};
```
将原Int类改名为Container类，将其模板化


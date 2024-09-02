## 3-9
**Q: Compile and run Static.cpp. Remove the static keyword from the code, compile and run it again, and explain what happens.**

去掉`static`关键字后，`i` 变为自动变脸，作用域为函数作用域，最后会输出10个 `i=1`



## 3-32
**Q: Define a function that takes a double argument and returns an int. Create and initialize a pointer to this function, and call the function through your pointer.**

使用 `int (*funcptr)(double) = double2int` 来声明并且定义函数指针


## 5-5
**Q: Create three classes. The first class contains private data, and grants friendship to the entire second class and to a member function of the third class. In main( ), demonstrate that all of these work correctly.**




## 5-14
**Q: Create a StackOfInt class (a stack that holds ints) using the "Cheshire cat" technique that hides the low-level data structure you use to store the elements in a class called StackImp. Implement two versions of StackImp: one that uses a fixed-length array of int, and one that uses a vector<int>. Have a preset maximum size for the stack so you don'tq have to worry about expanding the array in the first version. Note that the StackOfInt.h class doesn't have to change with StackImp.**




## 6-10
**Q: Create a class without any constructors, and show that you can create objects with the default constructor. Now create a nondefault constructor (one with an argument) for the class, and try compiling again. Explain what happened.**

创建类`A`后，如果没有构造函数，编译器会自动加上一个默认的构造函数，可以使用`A a;` 来实例化对象。    
如果有有参数的构造函数，则不能调用`A a;`实例化对象。   


## 7-4
**Q: Create a class that contains four member functions, with 0, 1, 2, and 3 int arguments, respectively. Create a main( ) that makes an object of your class and calls each of the member functions. Now modify the class so it has instead a single member function with all the arguments defaulted. Does this change your main( )?**

全是默认参数的成员函数如果和零参数的成员函数重名，则无法通过编译。如果不重名，那么输出无影响。

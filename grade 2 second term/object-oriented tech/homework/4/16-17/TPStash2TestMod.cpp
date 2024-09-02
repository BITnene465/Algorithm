//: C16:TPStash2Test.cpp
#include "TPStash2.h"
// #include "../require.h"   // 未找到该文件
#include <iostream>
#include <vector>
#include <string>
using namespace std;

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

int main()
{
    { // To force destructor call
        PStash<Container<int>> ints;
        for (int i = 0; i < 30; i++)
            ints.add(new Container<int>(i));
        cout << endl;
        PStash<Container<int>>::iterator it = ints.begin();
        it += 5;
        PStash<Container<int>>::iterator it2 = it + 10;
        for (; it != it2; it++)
            delete it.remove(); // Default removal
        cout << endl;
        for (it = ints.begin(); it != ints.end(); it++)
            if (*it) // Remove() causes "holes"
                cout << *it << endl;
    } // "ints" destructor called here
    cout << "\n-------------------\n";
    
    // ifstream in("TPStash2Test.cpp");
    // assure(in, "TPStash2Test.cpp");


    // Instantiate for String:
    PStash<string> strings;
    string line;
    while (getline(cin, line))
        strings.add(new string(line));
    PStash<string>::iterator sit = strings.begin();
    for (; sit != strings.end(); sit++)
        cout << **sit << endl;
    sit = strings.begin();
    int n = 26;
    sit += n;
    for (; sit != strings.end(); sit++)
        cout << n++ << ": " << **sit << endl;
} ///:~
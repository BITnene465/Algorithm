// a member function as friend function 
#include<iostream>
#include<string>
using namespace std;
class Girl;   // 前向声明，否则 Girl 会被默认当做 int
class Boy
{
private:
    string name;

public:
    void init(string n) { name = n; }
    void disp(Girl& g);
};

class Girl
{
private:
    string name;

public:
    void init(string n) { name = n; }
    friend void Boy::disp(Girl& g);   // 友元函数的声明，所以 Boy 通过该友元函数可以访问Girl的数据
    // 必须加上 Boy的限定符， 否则会被当做全局函数
};

void Boy::disp(Girl &g) { cout << g.name << endl; }

int main(void)
{
    Boy b;
    Girl g;
    g.init("shinku");
    b.disp(g);
    return 0;
}

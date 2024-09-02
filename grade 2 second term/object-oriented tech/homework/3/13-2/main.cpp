#include<iostream>
using namespace std;
class Counted{
    static int count;
    int id;
public:
    Counted(): id(count++){cout << "id: " << id << " is being created\n";}
    ~Counted(){cout << "id: " << id << " is being destroyed\n";}
};
int Counted::count = 0;

int main(void)
{
    Counted* pc = new Counted();
    delete pc;

    Counted* pc_array = new Counted[10];
    delete[] pc_array;

    return 0;
}
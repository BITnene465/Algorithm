// special operator overloading
#include<iostream>
using namespace std;
class vect{
    int *v;
public:
    vect(int size){
        v = new int[size];
    }
    ~vect(){
        delete[] v;
    }
    int& operator[](int i){
        cout << "Called by []" << endl;
        return v[i];
    }
};
int main(void)
{
    vect v(10);
    v[1] = 10;
    cout << v[1] << endl;
    return 0;
}
// global function as friend function 2
#include <iostream>
using namespace std;
class Car; class Boat;  // Ç°ÏòÉùÃ÷
class Car
{
    int weight;

public:
    Car(int weight) : weight(weight){};
    friend int addWeight(Car &c, Boat &b);
};

class Boat
{
    int weight;

public:
    Boat(int weight) : weight(weight){};
    friend int addWeight(Car &c, Boat &b);
};

int addWeight(Car& c, Boat& b){
    return c.weight + b.weight;
}


int main(void)
{
    Car c(10);
    Boat b(10);
    cout << addWeight(c, b) << endl;
    return 0;
}
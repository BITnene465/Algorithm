#include "StackOfInt1.h"
#include "StackOfInt2.h"
#include<iostream>
using namespace std;
int main(void)
{
    cout<< "²âÊÔStackOfInt1:" << endl;
    StackOfInt1 stk1;
    cout<< "1, 2, 3, 4 ÈëÕ»" << endl;
    stk1.push(1);
    stk1.push(2);
    stk1.push(3);
    stk1.push(4);
    while(!stk1.empty()){
        cout<< "³öÕ»£º" << stk1.top() << endl;
        stk1.pop();
    }

    cout<< "²âÊÔStackOfInt2:" << endl;
    StackOfInt1 stk2;
    cout<< "1, 2, 3, 4 ÈëÕ»" << endl;
    stk2.push(1);
    stk2.push(2);
    stk2.push(3);
    stk2.push(4);
    while(!stk2.empty()){
        cout<< "³öÕ»£º" << stk2.top() << endl;
        stk2.pop();
    }
    
    return 0;
}
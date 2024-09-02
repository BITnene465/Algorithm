// const ³£Á¿ÉùÃ÷
#include<iostream>
using namespace std;
const int byteSize(){
    return 8;
}
int main(void)
{
    const int x = 10;
    const int bytesize = byteSize();
    cout<<bytesize<<endl;
    return 0;
}

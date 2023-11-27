#include<iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(void)
{
    vector<int> array;
    int i;
    for(i=0;i<100;i++)
        array.push_back(i);
    vector<int>::iterator it;
    for(it=array.begin();it!=array.end();it++)
        cout<<*it<<endl;
    cout<<"hello world"<<endl;
    return 0;
}
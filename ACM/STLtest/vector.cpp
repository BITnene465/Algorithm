#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    cout<<"After insert:"<<endl;
    a.insert(a.begin()+1,10);
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<endl;
    }
    return 0;
}
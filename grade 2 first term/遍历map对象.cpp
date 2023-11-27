// encoding=gbk //
#include<bits/stdc++.h>
using namespace std;
int main(void)
{
    map<int,vector<int>> m;
    m[1] = vector<int> {2,3,4,5};   // vector
    m[2] = vector<int> {1,3,4,5};
    m[3] = vector<int> {1,2,4,5};
    m[4] = vector<int> {1,2,3,5};
    m[5] = vector<int> {1,3,4,2};
    for(auto key_vlaues:m)
    {
        int key = key_vlaues.first;
        for(auto value:key_vlaues.second)
        {
            printf("m[%d] include %d\n",key,value);
        }
        printf("\n");
    }
    return 0;
}
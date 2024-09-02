//
// Created by Okabu on 2024/8/3.
//

#include<iostream>
#include "MyTrees.h"
using namespace std;
int main(void)
{
    BSTree<int, int> tr1;
    int arr[] ={10, -9, 92, -183, 31, 0, -2};
    for(int i=0;i<sizeof(arr)/sizeof(int); i++)
        tr1.Insert(arr[i], arr[i]);

    tr1.inOrder();

    tr1.Delete(-9);
    tr1.inOrder();


    return 0;
}

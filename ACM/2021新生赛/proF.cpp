#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int arr[500000];
int main()
{
    int n,len;
    scanf("%d",&n);
    len = n;
    int i = 0;
    while(i<n)
    {
        scanf("%d",arr+i);
        i++;
    }
    while(len>1)
    {
        for(i=0;i<len-1;i++)
        {
            if(arr[i]!=arr[i+1])
            {
                arr[i] = 6 - arr[i] - arr[i+1];
            }
        }
        --len;
    }
    cout<<arr[0]<<endl;
    return 0;
}
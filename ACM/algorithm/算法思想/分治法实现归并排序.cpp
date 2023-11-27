#include<bits/stdc++.h>
using namespace std;
#define N 100
void merge(int arr[],int left,int mid,int right)
{
    int i,j,k;
    i=left,j=mid+1,k=0;
    int varT[N];
    while(i<=mid&&j<=right)
    {
        if(arr[i]>arr[j])   varT[k++]=arr[i++];
        else    varT[k++]=arr[j++];
    }
    if(i==mid+1)
        while(j<=right) varT[k++]=arr[j++];
    else
        while(i<=mid)   varT[k++]=arr[i++];
    //  将临时数组拷贝到原数组  //
    for(i=0;i<k;i++)    arr[left+i]=varT[i];
    return;
}
void mergesort(int arr[],int left,int right)
{
    if(right==left)
        return;
    else
    {
        int mid = (left+right)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
int main(void)
{
    int arr[N];
    int n;
    cout<<"enter the number of Numbers:";
    cin>>n;
    for(int i=0;i<n;++i)
        scanf("%d",arr+i);
    //
    mergesort(arr,0,n-1);
    //
    for(int i=0;i<n;++i)
        printf("%3d",arr[i]);
    printf("\n");
    return 0;
}
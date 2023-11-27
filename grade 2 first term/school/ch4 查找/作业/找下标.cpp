// 没有二分，但是O(n) //
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6+5;
int arr[maxn], ans[maxn], cnt, n;
int main(void)
{
    scanf("%d", &n);
    for(int i=0;i<n;++i)
        scanf("%d", arr+i);
    
    for(int i=0;i<n;++i)
    {
        if(arr[i] == i){
            ans[++cnt] = i;
        }
    }
    if(cnt==0){printf("No \n");}
    else{
        for(int i=1;i<=cnt;++i)printf("%d ", ans[i]);
        printf("\n");
    }
    
    return 0;
}
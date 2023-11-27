#include<bits/stdc++.h>
using namespace std;
int n,c1,c2;
int s1[100010],s2[100010];
int main(void)
{
    scanf("%d",&n);
    for(int i=1;i<=n;++i){
        scanf("%d",s1+i);
    }
    for(int i=1;i<=n;++i){
        scanf("%d",s2+i);
    }
    for(int i=1;i<=n-1;++i){
        if(s1[i]==s1[i+1])c1++;
    }
    for(int i=1;i<=n-1;++i){
        if(s2[i]==s2[i+1])c2++;
    }
    if(c1>c2){
        printf("Alice\n");
    }
    else printf("Bob\n");
    return 0;
}
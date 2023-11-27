#include<bits/stdc++.h>
using namespace std;
int T,n,m,k;
char s[100];
int main(void)
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d %d %d",&n,&m,&k);
        for(int i=1;i<=k;++i){
            for(int j=1;j<=n;++j)scanf("%s",s);
        }
        if(k>4)printf("3\n");
        else if(k==2)printf("1\n");
        else{
            printf("2\n");
        }
    }
    return 0;
}





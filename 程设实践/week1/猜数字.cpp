#include<bits/stdc++.h>
using namespace std;
int ma,mi,flag,m;
char s[101];
int main(void)
{
    mi=1;ma=10;flag=1;
    while(1)
    {
        scanf("%d",&m);
        getchar();
        if(m==0)break;
        gets(s);
        if(s[4]=='l'){mi=max(m+1,mi);if(ma<mi)flag=0;}
        else if(s[4]=='h'){ma=min(m-1,ma);if(ma<mi)flag=0;}
        else 
        {
            if(m<mi||m>ma)flag=0;
            if(flag)printf("Tom may be honest\n");
            else printf("Tom is dishonest\n");
            flag=1,ma=10,mi=1;
            continue;
        }
    }
    return 0;
}